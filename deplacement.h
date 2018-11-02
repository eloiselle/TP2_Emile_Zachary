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

	int getX() const;
	int getY() const;
	char getOrientation() const;

	void setX(int x);
	void setY(int y);
	void setOrientation(char orientation);
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

int deplacement::getX() const
{
	return _x;
}

int deplacement::getY() const
{
	return _y;
}

char deplacement::getOrientation() const
{
	return _orientation;
}

void deplacement::setX(int x)
{
	_x = x;
}

void deplacement::setY(int y)
{
	_y = y;
}

void deplacement::setOrientation(char orientation)
{
	_orientation = orientation;
}
