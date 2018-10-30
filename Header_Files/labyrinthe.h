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
#include <map.h>
#include <iostream>

using namespace std;

//================================
//			Déclarations
//================================

class labyrinthe
{
private:

	//Contient les murs d'une map
	map<TYPE> _map;

	//Dimensions
	int _nbCol;
	int _nbLin;

	//Point d'entrée et sortie
	int _posDepart;
	int _posArrivee;

public:

	//Constructeurs et destructeurs
	labyrinthe();
	labyrinthe(map<char> m);
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

labyrinthe::labyrinthe(map<char> m)
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
	_map.clear();
}

void labyrinthe::print() const
{
}