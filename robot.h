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

	pile<deplacement> _pileDeplacement;
	deplacement _nextMove;			//Planifie le prochain déplacement

public:

	robot();					//Initialise sans paramètres
	robot(deplacement d);		//Initialise avec 3 paramètres
	~robot();					//Destruction

	deplacement& nextMove();		//Getteur

	const deplacement& top();
	void push(const deplacement&);
	void pop();
};

//================================
//			Définitions
//================================

//	Constructeurs / Destructeur
//================================

robot::robot()
{
	_pileDeplacement.clear();
}

robot::robot(deplacement d)
{
	_pileDeplacement.push(d);
}

robot::~robot()
{
	_pileDeplacement.clear();
}

//Obtient le deplacement _nextMove
deplacement& robot::nextMove()
{
	return _nextMove;
}

//		Operations pile
//================================

const deplacement & robot::top()
{
	return _pileDeplacement.top();
}

void robot::push(const deplacement& dep)
{
	_pileDeplacement.push(dep);
}

void robot::pop()
{
	_pileDeplacement.pop();
}
