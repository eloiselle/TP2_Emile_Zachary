/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 29 octobre 2018
	Programme	: main.cpp
	But			: Gère les opérations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

//SFML Librairies
#include <SFML/Graphics.hpp>

//Default Librairies
#include <iostream>
#include <fstream>

//Custom Librairies
#include "labyrinthe.h"
#include "robot.h"

using namespace std;

int main()
{
	//================================
	//			Initialisations
	//================================

	//Permet les caractères spéciaux français
	setlocale(LC_ALL, "fr_FR.UTF-8");

	labyrinthe labActif(cin, cout);					//Le labyrinthe actuel
	robot robActif(labActif.getPosDepart());		//Les déplacements du robot

	//Charge les textures
	sf::Texture textureMap;
	textureMap.loadFromFile("images/map_spriteSheet.png");

	//Créer les sprites
	sf::IntRect rectSourceMap(0, 0, 32, 32);
	sf::Sprite spriteMap(textureMap, rectSourceMap);

	//Variables pour l'affichage
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Labyrinthe");
	sf::View MyView = window.getDefaultView();

	sf::Vector2f oldPos;
	bool moving = false;
	float zoom = 1;

	//================================
	//		Input utilisateur
	//================================

	//Tant que la fenêtre est ouverte
	while (window.isOpen())
	{
		//Déclare un événement
		sf::Event event;

		//Si un événement est déclanché
		while (window.pollEvent(event)) {
			switch (event.type) {
				//Bouton (X) pour fermer la fenêtre
			case sf::Event::Closed:
				window.close();
				break;

				//Bouton de souris pressé
			case sf::Event::MouseButtonPressed:

				//Si le bouton de gauche est pressé
				if (event.mouseButton.button == 0)
				{
					moving = true;
					oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				}
				break;

				//Bouton de souris relâché
			case  sf::Event::MouseButtonReleased:

				//Si le bouton de gauche est relâché
				if (event.mouseButton.button == 0)
					moving = false;

				break;

				//Si la souris est bougée
			case sf::Event::MouseMoved:
			{
				//Si on n'appuis pas sur un bouton
				if (!moving)
					break;

				//Obtient la position actuelle du curseur
				const sf::Vector2f newPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));

				//Calcul la différence entre la position du curseur appuyé
				const sf::Vector2f deltaPos = oldPos - newPos;

				//Rafraîchi l'affichage
				MyView.setCenter(MyView.getCenter() + deltaPos);
				window.setView(MyView);

				//Remplace la vieille position avec la nouvelle position
				oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				break;
			}
			case sf::Event::MouseWheelScrolled:

				if (moving)
					break;

				if (event.mouseWheelScroll.delta <= -1)
					zoom = std::min(2.f, zoom + .1f);
				else if (event.mouseWheelScroll.delta >= 1)
					zoom = std::max(.5f, zoom - .1f);

				MyView.setSize(window.getDefaultView().getSize());
				MyView.zoom(zoom);
				window.setView(MyView);
				break;
			}
		}

		//================================
		//			Événements
		//================================

		if (!labActif.getFinRecherche())
		{
			//Si on n'est pas arrivés à la fin et qu'on est pas au départ ou qu'on a jamais bougé
			if (!labActif.arrived(robActif.top()) &&
				(robActif.top() != labActif.getPosDepart() || robActif.nextMove().x() == NULL))
			{
				//Vérifie si on peut bouger et où on peut bouger si oui
				if (labActif.canMove(robActif.top(), robActif.nextMove()))
				{
					//Place un 'V' ou on est
					labActif.getMap().at(robActif.top().x(), robActif.top().y()) = 'V';

					//Bouge vers le nouvel emplacement
					robActif.push(robActif.nextMove());
				}

				//Si on ne peut pas bouger
				else
				{
					//Place un 'V' où on était
					labActif.getMap().at(robActif.top().x(), robActif.top().y()) = 'V';

					//Recule d'une case
					robActif.pop();

					//Place la case actuelle d'un vide
					labActif.getMap().at(robActif.top().x(), robActif.top().y()) = '0';
				}
			}

			//Si on est de retour au début
			else if (robActif.top() == labActif.getPosDepart())
			{
				cout << "Aucune solution" << endl;
				labActif.getFinRecherche() = true;
			}

			//Si on est à la fin
			else
			{
				cout << "Solution trouvee" << endl;
				labActif.getFinRecherche() = true;

				while (robActif.size() > 1)
				{
					labActif.getMap().at(robActif.top().x(), robActif.top().y()) = 'T';
					robActif.pop();
				}
			}
		}

		//================================
		//			Affichage
		//================================

		//Efface tout
		window.clear();

		//Pour chaques cases
		for (int i = 0; i < labActif.getMap().getNbLine(); i++)
		{
			for (int j = 0; j < labActif.getMap().getNbCol(); j++)
			{
				//Emplacement de la fenêtre qui va être modifié
				spriteMap.setPosition(i * 32, j * 32);

				//Si c'est un mur dans la carte
				if (labActif.getMap()[i][j] == '1')
				{
					//Place la texture sur l'emplacement du mur
					rectSourceMap.left = 1;
					rectSourceMap.top = 0;
				}

				//Si c'est vide
				else if (labActif.getMap()[i][j] == '0')
				{
					//Place la texture sur l'emplacement du plancher
					rectSourceMap.left = 0;
					rectSourceMap.top = 0;
				}

				else if (labActif.getMap()[i][j] == 'V')
				{
					//Place la texture sur l'emplacement de la vitre
					rectSourceMap.left = 5;
					rectSourceMap.top = 0;
				}

				else if (labActif.getMap()[i][j] == 'T')
				{
					//Place la texture sur l'emplacement de la vitre
					rectSourceMap.left = 1;
					rectSourceMap.top = 1;
				}

				rectSourceMap.left = rectSourceMap.left * 32;
				rectSourceMap.top = rectSourceMap.top * 32;

				//Met à jour le sprite avec la nouvelle texture
				spriteMap.setTextureRect(rectSourceMap);

				//Affiche le sprite avec la nouvelle texture
				window.draw(spriteMap);
			}
		}

		//Afficher icone de depart du labyrinthe
		spriteMap.setPosition(labActif.getPosDepart().x() * 32, labActif.getPosDepart().y() * 32);
		rectSourceMap.left = 3 * 32;
		rectSourceMap.top = 0;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		//Afficher icone d'arrivée du labyrinthe
		spriteMap.setPosition(labActif.getPosArriver().x() * 32, labActif.getPosArriver().y() * 32);
		rectSourceMap.left = 0;
		rectSourceMap.top = 1 * 32;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		if (!labActif.getFinRecherche())
		{
			//Affiche le robot
			spriteMap.setPosition(robActif.top().x() * 32, robActif.top().y() * 32);
			rectSourceMap.left = 7 * 32;
			rectSourceMap.top = 0;
			spriteMap.setTextureRect(rectSourceMap);
			window.draw(spriteMap);
		}

		//Rafraîchit l'écran avec les nouvelles modifications
		window.display();

		//Vitesse a laquelle la solution du labyrinthe est executer
		//sf::sleep(sf::milliseconds(50));
	}

	return EXIT_SUCCESS;
}