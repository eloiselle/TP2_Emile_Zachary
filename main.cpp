/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 29 octobre 2018
	Programme	: main.cpp
	But			: Gère les opérations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//SFML Librairies
#include <SFML/Graphics.hpp>
#include <iostream>

//Default Librairies
#include <stack>

//Custom Librairies
#include <labyrinthe.h>
#include <map.h>

using namespace std;

int main()
{
	//Le labyrinthe actuel
	labyrinthe labActif;

	//Crée une fenêtre
	sf::RenderWindow window(sf::VideoMode(640, 480), "Labyrinthe");

	//Tant que la fenêtre est ouverte
	while (window.isOpen())
	{
		//Déclare un événement
		sf::Event event;

		//Si un événement est déclanché
		while (window.pollEvent(event))
		{
			//Pour l'événement
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Séquence qui rafraîchi l'affichage
		window.clear();
		//window.draw(shape);
		window.display();
	}

	return 0;
}