/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Gère les informations sur les déplacements (emplacement,
				  direction)
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once

//================================
//			Déclarations
//================================

class deplacement
{
private:
	int _x;				//Position X
	int _y;				//Position Y
	char _orientation;	//Orientation en int (1 = Nord, 2 = Est, 3 = Sud, 4 = Ouest, 0 = Aucun

public:
	deplacement();					//Initialise sans paramètres
	deplacement(int, int, char);	//Initialise avec 3 paramètres
	~deplacement();					//Destruction

	int& x();					//Obtient la valeur de x par référence
	int& y();					//Obtient la valeur de y par référence
	char& orientation();		//Obtient la valeur de l'orientation par référence

	const int& x() const;					//Obtient la valeur de x par référence constante
	const int& y() const;					//Obtient la valeur de y par référence constante
	const char& orientation() const;		//Obtient la valeur de l'orientation par référence constante

	void init(int, int, char);		//Initialise le déplacement
	void clear();					//Remet tout à NULL

	const deplacement& operator=(const deplacement& d);		//Copie le contenu d'un déplacement vers une autre
	bool operator==(const deplacement& s)const;				//Compare 2 déplacements, dans l'orientation
	bool operator!=(const deplacement& s)const;				//Compare 2 déplacements, dans l'orientation
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

deplacement::deplacement(int x, int y, char orientation)
{
	init(x, y, orientation);
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

char& deplacement::orientation()
{
	return _orientation;
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

const char & deplacement::orientation() const
{
	return _orientation;
}

//Initialise toutes les variables avec les paramètres
void deplacement::init(int x, int y, char orientation)
{
	assert(orientation == 'N' || orientation == 'n' ||
		orientation == 'S' || orientation == 's'
		|| orientation == 'E' || orientation == 'e' ||
		orientation == 'O' || orientation == 'o'
		|| orientation == 'A' || orientation == 'a');

	_x = x;
	_y = y;

	if (orientation == 'N' || orientation == 'n')
		_orientation = 'N';

	else if (orientation == 'E' || orientation == 'e')
		_orientation = 'E';

	else if (orientation == 'S' || orientation == 's')
		_orientation = 'S';

	else if (orientation == 'O' || orientation == 'o')
		_orientation = 'O';

	else
		_orientation = 'A';
}

//Remet tout à NULL
void deplacement::clear()
{
	//nullptr non-accepté?
	_x = NULL;
	_y = NULL;
	_orientation = NULL;
}

//Permet d'assigner le dontenu d'un deplacement vers un autre
const deplacement & deplacement::operator=(const deplacement & d)
{
	_x = d._x;
	_y = d._y;
	_orientation = d._orientation;

	return *this;
}

//Compare 2 déplacements, sans l'orientation
bool deplacement::operator==(const deplacement & p) const
{
	return _x == p._x && _y == p._y;
}

//Compare 2 déplacements, sans l'orientation
bool deplacement::operator!=(const deplacement & p) const
{
	return !(_x == p._x && _y == p._y);
}