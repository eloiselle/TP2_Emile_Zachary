/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Entité qui se dplace dans un labyrinthe en essayant
				  toutes les options possibles.
==================================================================*/
#pragma once
#include <assert.h>
#include "pile.h"
using namespace std;

class robot
{
public:
	robot();
	robot(deplacement& d);
	~robot();
private:
	pile<deplacement> historique;
};

robot::robot()
{
}

robot::robot(deplacement & d)
{
	historique.push(d);
}

robot::~robot()
{
}
