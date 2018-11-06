/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Gère les informations sur les déplacements.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once

//Default Librairies
#include <assert.h>

using namespace std;

//================================
//			Déclarations
//================================

class deplacement
{
private:

	int _x;		//Position X
	int _y;		//Position Y

public:

	deplacement();				//Initialise sans paramètres
	deplacement(int, int);		//Initialise avec 2 paramètres
	~deplacement();				//Destruction

	int& x();		//Obtient la valeur de x par référence
	int& y();		//Obtient la valeur de y par référence

	const int& x() const;		//Obtient la valeur de x par référence constante
	const int& y() const;		//Obtient la valeur de y par référence constante

	void init(int, int);		//Initialise le déplacement
	void clear();				//Remet tout à NULL

	//Opérateurs
	const deplacement& operator=(const deplacement& d);
	bool operator==(const deplacement& s)const;
	bool operator!=(const deplacement& s)const;
};

//================================
//			Définitions
//================================

//	Constructeurs / Destructeur
//================================

deplacement::deplacement()
{
	clear();
}

deplacement::deplacement(int x, int y)
{
	init(x, y);
}

deplacement::~deplacement()
{
	clear();
}

//			Getteurs
//================================

int& deplacement::x()
{
	return _x;
}

int& deplacement::y()
{
	return _y;
}

//		Getteurs const
//================================

const int & deplacement::x()const
{
	return _x;
}

const int & deplacement::y() const
{
	return _y;
}

//Initialise toutes les variables avec les paramètres
void deplacement::init(int x, int y)
{
	_x = x;
	_y = y;
}

//Remet tout à NULL
void deplacement::clear()
{
	//nullptr non-accepté?
	_x = NULL;
	_y = NULL;
}

//			Opérateurs
//================================

const deplacement & deplacement::operator=(const deplacement & d)
{
	_x = d._x;
	_y = d._y;

	return *this;
}

bool deplacement::operator==(const deplacement & p) const
{
	return _x == p._x && _y == p._y;
}

bool deplacement::operator!=(const deplacement & p) const
{
	return !(_x == p._x && _y == p._y);
}