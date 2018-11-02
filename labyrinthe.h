/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
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
#include "deplacement.h"
#include <string>

//================================
//			Déclarations
//================================

class labyrinthe
{
private:

	//Contient les murs d'une map
	customMap<char> _mapLab;

	//Point d'entrée et sortie
	deplacement _posDepart;
	deplacement _posArrivee;

public:

	//Constructeurs et destructeurs
	labyrinthe();
	labyrinthe(string nom);
	~labyrinthe();

	//Vérifications
	bool canMove() const;
	bool arrived() const;

	//Acces a l'objet Map
	customMap<char>& getMap();

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

labyrinthe::labyrinthe(string nom)
{
	ifstream fichier(nom);

	if (fichier)  //Si l'ouverture fonctionne.
	{
		_mapLab.init(fichier);
		fichier >> _posDepart[0] >> _posDepart[1] >> _posArrivee[0] >> _posArrivee[1];
		fichier.close();
	}
	else //Si l'ouverture ne fonctionne pas.
	{
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}
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

inline customMap<char>& labyrinthe::getMap()
{
	return _mapLab;
}

void labyrinthe::clear()
{
	_mapLab.clear();
}

void labyrinthe::print() const
{
}