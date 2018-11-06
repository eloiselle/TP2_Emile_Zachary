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

	//PLanifie le prochain déplacement
	deplacement nextMove;

	//Le labyrinthe actuel
	labyrinthe labActif("Maps/Labyrinthe4.txt");

	//Les déplacements du robot
	robot robActif(labActif.getPosDepart());

	//Charge les textures
	sf::Texture textureMap;
	textureMap.loadFromFile("images/map_spriteSheet.png");

	//Créer les sprites
	sf::IntRect rectSourceMap(0, 0, 32, 32);
	sf::Sprite spriteMap(textureMap, rectSourceMap);

	//Crée une fenêtre
	sf::RenderWindow window(sf::VideoMode(
		labActif.getMap().getNbCol() * 32,
		labActif.getMap().getNbLine() * 32),
		"Labyrinthe");

	//================================
	//		Input utilisateur
	//================================

	//Tant que la fenêtre est ouverte
	while (window.isOpen())
	{
		//Déclare un événement
		sf::Event event;

		//Si un événement est déclanché
		while (window.pollEvent(event))
		{
			//Pour l'événement fermeture de fenêtre ( le X )
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			//Si on tente de resize l'écran
			if (event.type == sf::Event::Resized)
			{
				//Rafraîchi la vue au nouvel écran
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
		}

		//================================
		//			Événements
		//================================

		//Si on n'est pas arrivés à la fin et qu'on est pas au départ ou qu'on a jamais bougé
		if (!labActif.arrived(robActif.top()) &&
			(robActif.top() != labActif.getPosDepart() || nextMove.x() == NULL))
		{
			//Vérifie si on peut bouger et où on peut bouger si oui
			if (labActif.canMove(robActif.top(), nextMove))
			{
				//Place un 'V' ou on est
				labActif.getMap().at(robActif.top().x(), robActif.top().y()) = 'V';

				//Bouge vers le nouvel emplacement
				robActif.push(nextMove);
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
			cout << "Aucune solution";

		//Si on est à la fin
		else
			cout << "Success";

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
				spriteMap.setPosition(j * 32, i * 32);

				//Si c'est un mur dans la carte
				if (labActif.getMap()[i][j] == '1')
				{
					//Place la texture sur l'emplacement du mur
					rectSourceMap.left = 1 * 32;
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
					rectSourceMap.left = 6 * 32;
					rectSourceMap.top = 0;
				}
				//Met à jour le sprite avec la nouvelle texture
				spriteMap.setTextureRect(rectSourceMap);

				//Affiche le sprite avec la nouvelle texture
				window.draw(spriteMap);
			}
		}

		//Afficher icone de depart du labyrinthe
		spriteMap.setPosition(labActif.getPosDepart().y() * 32, labActif.getPosDepart().x() * 32);
		rectSourceMap.left = 96;
		rectSourceMap.top = 0;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		//Afficher icone d'arrivée du labyrinthe
		spriteMap.setPosition(labActif.getPosArriver().y() * 32, labActif.getPosArriver().x() * 32);
		rectSourceMap.left = 0;
		rectSourceMap.top = 32;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		spriteMap.setPosition(robActif.top().y() * 32, robActif.top().x() * 32);
		rectSourceMap.left = 7 * 32;
		rectSourceMap.top = 0;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		//Rafraîchit l'écran avec les nouvelles modifications
		window.display();

		sf::sleep(sf::milliseconds(50));
	}

	return EXIT_SUCCESS;
}