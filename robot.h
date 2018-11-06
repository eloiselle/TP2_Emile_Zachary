/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Entité qui se délace dans un labyrinthe en essayant
				  tous les passages possibles.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once

//Default Librairies
#include <assert.h>

//Custom Librairies
#include "pile.h"

using namespace std;

//================================
//			Déclarations
//================================

class robot
{
private:
	pile<deplacement> historique;

public:
	robot();
	robot(deplacement d);
	~robot();

	pile<deplacement>& getHistorique();
};

//================================
//			Définitions
//================================

//	Constructeurs / Destructeur
//================================

robot::robot()
{
}

robot::robot(deplacement d)
{
	historique.push(d);
}

robot::~robot()
{
}

pile<deplacement>& robot::getHistorique()
{
	return historique;
}