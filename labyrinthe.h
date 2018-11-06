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

//Default Librairies
#include <string>

//Custom Librairies
#include "map.h"
#include "deplacement.h"
#include "robot.h"

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

	//Get positions
	deplacement getPosDepart() const;
	deplacement getPosArriver() const;

	//Vérifications
	bool canMove() const;
	bool arrived(deplacement pos) const;

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
		fichier >> _posDepart.x() >> _posDepart.y() >> _posArrivee.x() >> _posArrivee.y();
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

deplacement labyrinthe::getPosDepart() const
{
	return _posDepart;
}

deplacement labyrinthe::getPosArriver() const
{
	return _posArrivee;
}

bool labyrinthe::canMove() const
{
	return false;
}

bool labyrinthe::arrived(deplacement pos) const
{
	if (pos.x() == getPosArriver().x() && pos.y() == getPosArriver().y())
		return true;

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