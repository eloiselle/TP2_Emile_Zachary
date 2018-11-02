/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Gère les informations sur les déplacements (emplacement,
				  direction)
==================================================================*/

#pragma once

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

	int& getX();
	int& getY();
	char& getOrientation();
};

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

int& deplacement::getX()
{
	return _x;
}

int& deplacement::getY()
{
	return _y;
}

char& deplacement::getOrientation()
{
	return _orientation;
}