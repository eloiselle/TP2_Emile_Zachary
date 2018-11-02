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

public:
	deplacement();
	~deplacement();
};

deplacement::deplacement()
{
}

deplacement::~deplacement()
{
}
