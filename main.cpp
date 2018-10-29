/*
Auteur:		Émile Loiselle
Date:		//
Programme:	main.cpp
But:		//
*/

//SFML Librairies
#include <SFML/Graphics.hpp>

//Default Librairies
#include <stack>

//Custom Librairies
//#include <labyrinthe.h>
//#include <map.h>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(200, 200), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	//Tant que la fenêtre est ouverte
	while (window.isOpen())
	{
		//Déclare un événement
		Event event;

		//Si un événement est déclanché
		while (window.pollEvent(event))
		{
			//Pour l'événement
			if (event.type == Event::Closed)
				window.close();
		}

		//Séquence qui rafraîchi l'affichage
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

//using namespace std;
//
//int main()
//{
//	setlocale(LC_CTYPE, "fra");
//
//	//Your code here...
//
//	cout << "test zac";
//	cout << "Hello, world!";
//
//	return 0;
//}