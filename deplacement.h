/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Gère les informations sur les déplacements (emplacement,
				  direction)
==================================================================*/

#pragma once

//================================
//			Déclarations
//================================

class deplacement
{
private:
	int _x;
	int _y;
	char _orientation;

public:
	deplacement();
	deplacement(int, int, char);
	~deplacement();

	int& x();
	int& y();
	char& orientation();

	bool operator==(const deplacement& s)const;
};

//================================
//			Définitions
//================================

//	Constructeurs / Destructeur
//================================

deplacement::deplacement()
{
}

deplacement::deplacement(int x, int y, char orientation)
{
	_x = x;
	_y = y;
	_orientation = orientation;
}

deplacement::~deplacement()
{
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

bool deplacement::operator==(const deplacement & p) const
{
	if (_x == p._x && _y == p._y)
		return true;

	return false;
}