/*
Auteur:		Émile Loiselle
Date:		//
Programme:	main.cpp
But:		//
*/

#include <map.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "fra");

	string nom = "Maps/Labyrinthe2.txt";
	ifstream fichier(nom, ios::in);

	if (fichier)  //Si l'ouverture fonctionne.
	{
		map<char> mapLabyrinthe(fichier, nom);

		fichier.close();

		cout << mapLabyrinthe;
	}
	else //Si l'ouverture ne fonctionne pas.
	{
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}

	//Permet un arret avant la fin pour voir un apercu de la console.
	cout << endl; system("pause");
	return 0;
}