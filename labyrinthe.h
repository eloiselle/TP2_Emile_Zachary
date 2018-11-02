/*==================================================================
	Auteur		: Émile Loiselle
	Date		: 29 octobre 2018
	Programme	: labyrinthe.h
	But			: Gère les opérations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once
#include "map.h"

//================================
//			Déclarations
//================================

class labyrinthe
{
private:

	//Contient les murs d'une map
	customMap<char> _mapLab;

	//Dimensions
	int _nbCol;
	int _nbLin;

	//Point d'entrée et sortie
	int _posDepart;
	int _posArrivee;

public:

	//Constructeurs et destructeurs
	labyrinthe();
	labyrinthe(customMap<char> m);
	~labyrinthe();

	//Vérifications
	bool canMove() const;
	bool arrived() const;

	//Utilitaires
	void clear();
	void print() const;
};

//================================
//			Définitions
//================================

labyrinthe::labyrinthe()
{
	clear();
}

labyrinthe::labyrinthe(customMap<char> m)
{
}

labyrinthe::~labyrinthe()
{
	clear();
}

bool labyrinthe::canMove() const
{
	return false;
}

bool labyrinthe::arrived() const
{
	return false;
}

void labyrinthe::clear()
{
	_nbCol = 0;
	_nbLin = 0;
	_posDepart = -1;
	_posArrivee = -1;
	_mapLab.clear();
}

void labyrinthe::print() const
{
}