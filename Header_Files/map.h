/*	Auteur		: Zachary Cockburn
	Date		: 10/10/18
	Programme	: map.h
	But			: Une matrice generique en 2 dimensions et dynamique.*/
#pragma once
#pragma warning(disable : 4996)  //Pour ne pas d'avoir d'erreurs avec strcpy
#include <iostream>
#include <assert.h>
using namespace std;

template <class TYPE>
class map
{
private:
	char *_name;	//pointeur sur le nom de la map
	TYPE **_map;	//La map dynamique en ligne et colonne
	int _nbLine, 	//nombre de ligne pour la matrice
		_nbCol;		//nombre de colonne pour la matrice
public:
	//Constructeurs et destructeur.
	map(istream & file, string name);
	//map(const char* name, int line, int col);
	~map();

	void init(istream & file);

	//Methodes pour clear.
	void clear();						//Fait un menage de printemps de la map
	void clearName();					//Efface le nom actuel de la map

	//Getteurs et setteurs.
	int nbLine()const; 					//retourne le nb de ligne
	int nbCol()const; 					//retourne le nb de colonne
	void resize(int nbLine, int nbCol);	//resize la matrice avec nouv dims

	//Methodes pour at() et l'operateur [].
	TYPE& at(int posI, int posJ) const;	//retourne une référence à l'ele à la pos i,j pour accéder ou modifier
	TYPE* operator[](int line);			//Operateur []

	//Methodes pour modifier ou obtenir le nom.
	const char* getName()const; 	  	//retourne le nom de la map
	void setName(const char* name);  	//modifie le nom de la map

	//Methodes pour modifier ou obtenir la map.
	void print(ostream& sortie)const;  	//print la matrice (sans le nom)
	void read(istream& entree);			//lit la matrice de la map ds le flux
};

//Constructeur
template <class TYPE>
map<TYPE>::map(istream & file, string name)
{
	_map = nullptr;
	_nbLine = _nbCol = 0;

	init(file);
}

/*
//Constructeur avec parametres
template <class TYPE>
map<TYPE>::map(const char* name, int line, int col)
{
	assert(line >= 0 && col >= 0);
	_map = nullptr;
	_name = nullptr;

	if (strlen(name) > 0)
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}

	_nbLine = line;
	_nbCol = col;

	if (line > 0 && col > 0)
	{
		_map = new TYPE *[_nbLine];
		for (int i = 0; i < _nbLine; i++)
		{
			*(_map + i) = new TYPE[_nbCol];
		}
	}
}
*/

//Deconstructeur
template <class TYPE>
map<TYPE>::~map()
{
	clear();
	clearName();
	_nbLine = _nbCol = 0;
}

// Initialise le vecteur 2D contenant les valeurs des tuiles de la carte
template <class TYPE>
void map<TYPE>::init(istream & file) {
	assert(!file.fail());
	//char z; // Virgule à ignorer
	int newNbLine, newNbCol;

	file >> newNbLine >> newNbCol;
	resize(newNbLine, newNbCol);
	read(file);
}

//Fait un menage de printemps de la map
template <class TYPE>
void map<TYPE>::clear()
{
	for (int i = 0; i < _nbLine; i++)
	{
		delete[] * (_map + i);
	}

	delete[]_map;
	_map = nullptr;
	_nbLine = 0;
	_nbCol = 0;
}

//Efface le nom actuel de la map.
template <class TYPE>
void map<TYPE>::clearName()
{
	delete[]_name;
	_name = nullptr;
}

//Retourne le nb de ligne
template <class TYPE>
int map<TYPE>::nbLine()const
{
	return _nbLine;
}

//Retourne le nb de colonne
template <class TYPE>
int map<TYPE>::nbCol()const
{
	return _nbCol;
}

//Resize la matrice avec nouv dims
template <class TYPE>
void map<TYPE>::resize(int nbLine, int nbCol)
{
	assert(nbLine >= 0 && nbCol >= 0);
	if (nbLine == 0 || nbCol == 0)
	{
		clear();
	}

	TYPE **newMap = new TYPE*[nbLine];

	for (int i = 0; i < nbLine; i++)
	{
		*(newMap + i) = new TYPE[nbCol];
	}

	for (int i = 0; i < nbLine && i < _nbLine; i++)
	{
		for (int j = 0; j < nbCol && j < _nbCol; j++)
		{
			*(*(newMap + i) + j) = *(*(_map + i) + j);
		}
	}

	clear();
	_map = newMap;
	_nbCol = nbCol;
	_nbLine = nbLine;
}

//Retourne une référence à l'ele à la pos i,j pour accéder ou modifier
template <class TYPE>
TYPE& map<TYPE>::at(int posI, int posJ) const
{
	assert(posI >= 0 && posJ >= 0);
	return *(*(_map + posI) + posJ);
}

//Operateur []
template <class TYPE>
TYPE* map<TYPE>::operator[](int line)
{
	assert(line >= 0 && line < _nbLine);
	return *(_map + line);
}

//Retourne le nom de la map
template <class TYPE>
const char* map<TYPE>::getName()const
{
	if (_name == nullptr)
	{
		return "\0";
	}
	return _name;
}

//Change le nom de la map
template <class TYPE>
void map<TYPE>::setName(const char* name)
{
	clearName();

	if (strlen(name) > 0)
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}
}

//Print la matrice (sans le nom)
template <class TYPE>
void map<TYPE>::print(ostream& sortie)const
{
	for (int i = 0; i < _nbLine; i++)
	{
		for (int j = 0; j < _nbCol; j++)
		{
			sortie << *(*(_map + i) + j);
		}
		sortie << endl;
	}
}

//Lit la matrice de la map ds le flux
template <class TYPE>
void map<TYPE>::read(istream& entree)
{
	for (int i = 0; i < _nbLine; i++)
	{
		for (int j = 0; j < _nbCol; j++)
		{
			entree >> *(*(_map + i) + j);
		}
	}
}

//Affiche le contenu du vecteur avec l’opérateur <<
template <class TYPE>
ostream& operator<<(ostream& sortie, const map<TYPE> &x)
{
	x.print(sortie);
	return sortie;
}

//Prend le contenu du vecteur avec l’opérateur >>
template <class TYPE>
istream& operator>>(istream& entree, map<TYPE> &x)
{
	x.read(entree);
	return x;
}
