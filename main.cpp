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
		//LES 3 LIGNE EN DESOSUS SONT JUSTE POUR MONTRER QUE LE FICHER PEU ETRE LUT
		//DECOMMENTE LA 4EME POUR VOIR OU JE SUIS RENDU AVEC MON ERREUR RESIZE.
		string contenu;
		getline(fichier, contenu);
		cout << contenu;
		//map<char> test(fichier, nom);

		fichier.close();
	}
	else //Si l'ouverture ne fonctionne pas.
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}

	cout << "Hello, world!" << endl;

	//Permet un arret avant la fin pour voir un apercu de la console.
	cout << endl; system("pause"); return 0;
}