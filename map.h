/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 31 octobre 2018
	Programme	: map.h
	But			: Une matrice dynamique en 2 dimensions.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once

//Default Librairies
#include <iostream>
#include <assert.h>

using namespace std;

//================================
//			Déclarations
//================================

template <class TYPE>
class customMap
{
private:
	char *_name;	//pointeur sur le nom de la map
	TYPE **_map;	//La map dynamique en ligne et colonne
	int _nbLine, 	//nombre de ligne pour la matrice
		_nbCol;		//nombre de colonne pour la matrice
public:
	//Constructeurs et destructeur.
	customMap(istream & file);
	customMap();
	//map(const char* name, int line, int col);
	~customMap();

	void init(istream & file);

	//Methodes pour clear.
	void clear();						//Fait un menage de printemps de la map
	void clearName();					//Efface le nom actuel de la map

	//Getteurs et setteurs.
	int getNbLine()const; 					//retourne le nb de ligne
	int getNbCol()const; 					//retourne le nb de colonne
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

//================================
//			Définitions
//================================

//Constructeur sans paramètres
template <class TYPE>
customMap<TYPE>::customMap()
{
	_map = nullptr;
	_nbLine = _nbCol = 0;
}

//Constructeur avec 2 paramètres
template <class TYPE>
customMap<TYPE>::customMap(istream & file)
{
	_map = nullptr;
	_nbLine = _nbCol = 0;

	init(file);
}

//Destructeur
template <class TYPE>
customMap<TYPE>::~customMap()
{
	clear();
	clearName();
	_nbLine = _nbCol = 0;
}

//Initialise le vecteur 2D contenant les valeurs des tuiles de la carte
template <class TYPE>
void customMap<TYPE>::init(istream & file) {
	assert(!file.fail());
	int newNbLine, newNbCol;

	file >> newNbLine >> newNbCol;
	resize(newNbLine, newNbCol);
	read(file);
}

//Fait un menage de printemps de la map
template <class TYPE>
void customMap<TYPE>::clear()
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

//Efface le nom
template <class TYPE>
void customMap<TYPE>::clearName()
{
	delete[]_name;
	_name = nullptr;
}

//Retourne le nb de ligne
template <class TYPE>
int customMap<TYPE>::getNbLine()const
{
	return _nbLine;
}

//Retourne le nb de colonne
template <class TYPE>
int customMap<TYPE>::getNbCol()const
{
	return _nbCol;
}

//Resize la matrice avec des nouvelles dimensions
template <class TYPE>
void customMap<TYPE>::resize(int nbLine, int nbCol)
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

//Retourne une référence de l'element à l'emplacement (i, j)
template <class TYPE>
TYPE& customMap<TYPE>::at(int posI, int posJ) const
{
	assert(posI >= 0 && posJ >= 0 && posI < _nbLine && posJ < _nbCol);
	return *(*(_map + posI) + posJ);
}

//Operateur []
template <class TYPE>
TYPE* customMap<TYPE>::operator[](int line)
{
	assert(line >= 0 && line < _nbLine);
	return *(_map + line);
}

//Retourne le nom de la map
template <class TYPE>
const char* customMap<TYPE>::getName()const
{
	if (_name == nullptr)
	{
		return "\0";
	}
	return _name;
}

//Change le nom de la map
template <class TYPE>
void customMap<TYPE>::setName(const char* name)
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
void customMap<TYPE>::print(ostream& sortie)const
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
void customMap<TYPE>::read(istream& entree)
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
ostream& operator<<(ostream& sortie, const customMap<TYPE> &x)
{
	x.print(sortie);
	return sortie;
}

//Prend le contenu du vecteur avec l’opérateur >>
template <class TYPE>
istream& operator>>(istream& entree, customMap<TYPE> &x)
{
	x.read(entree);
	return x;
}
