/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 29 octobre 2018
	Programme	: main.cpp
	But			: Gère les opérations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//SFML Librairies
#include <SFML/Graphics.hpp>

//Default Librairies
#include <iostream>
#include <fstream>
#include <stack>

//Custom Librairies
#include <labyrinthe.h>
#include <map.h>

using namespace std;

int main()
{
	//================================
	//			Initialisations
	//================================

	//Le labyrinthe actuel
	labyrinthe labActif;

	//Charge les textures
	sf::Texture textureMap;
	textureMap.loadFromFile("images/map_spriteSheet.png");

	//Créer les sprites
	sf::IntRect rectSourceMap(0, 0, 32, 32);
	sf::Sprite spriteMap(textureMap, rectSourceMap);

	//Charge la carte
	customMap<char> mapLabyrinthe;
	string nom = "Maps/Labyrinthe4.txt";
	ifstream fichier(nom);

	if (fichier)  //Si l'ouverture fonctionne.
	{
		mapLabyrinthe.init(fichier);
		fichier.close();
		cout << mapLabyrinthe;
	}
	else //Si l'ouverture ne fonctionne pas.
	{
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}

	//Crée une fenêtre
	sf::RenderWindow window(sf::VideoMode(
		mapLabyrinthe.getNbCol() * 32,
		mapLabyrinthe.getNbLine() * 32),
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
			if (event.type == sf::Event::Closed)
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
		//			Affichage
		//================================

		//Efface tout
		window.clear();

		//Pour chaques cases
		for (int i = 0; i < mapLabyrinthe.getNbLine(); i++)
		{
			for (int j = 0; j < mapLabyrinthe.getNbCol(); j++)
			{
				//Emplacement de la fenêtre qui va être modifié
				spriteMap.setPosition(j * 32, i * 32);

				//Si c'est un mur dans la carte
				if (mapLabyrinthe[i][j] == '1')
					//Place la texture sur l'emplacement du mur
					rectSourceMap.left = 32;

				//Si c'est vide
				else if (mapLabyrinthe[i][j] == '0')
					//Place la texture sur l'emplacement du plancher
					rectSourceMap.left = 0;

				//Met à jour le sprite avec la nouvelle texture
				spriteMap.setTextureRect(rectSourceMap);

				//Affiche le sprite avec la nouvelle texture
				window.draw(spriteMap);
			}
		}

		//Rafraîchit l'écran avec les nouvelles modifications
		window.display();
	}

	return EXIT_SUCCESS;
}