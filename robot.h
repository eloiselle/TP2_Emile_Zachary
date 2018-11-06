/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Entité qui se déplace dans un labyrinthe en essayant
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
	deplacement _nextMove;		//Planifie le prochain déplacement

public:

	//Constructeurs et destructeurs
	robot();
	robot(deplacement d);
	~robot();

	//Getteur
	deplacement& nextMove();

	const deplacement& top();			//Retourne un élément au dessus de la pile
	void push(const deplacement&);		//Ajoute un élément au dessus de la pile
	void pop();							//Enlève un élément au dessus de la pile
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

//Retourne un élément au dessus de la pile
const deplacement & robot::top()
{
	return _pileDeplacement.top();
}

//Ajoute un élément au dessus de la pile
void robot::push(const deplacement& dep)
{
	_pileDeplacement.push(dep);
}

//Enlève un élément au dessus de la pile
void robot::pop()
{
	_pileDeplacement.pop();
}