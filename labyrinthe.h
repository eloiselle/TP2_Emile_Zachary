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

using namespace std;

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
	labyrinthe(istream& input, ostream& output);
	~labyrinthe();

	//Get positions
	deplacement getPosDepart() const;
	deplacement getPosArriver() const;

	//Vérifications
	bool canMove(const deplacement& pos, deplacement& posToCheck) const;
	bool arrived(const deplacement& pos) const;

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

labyrinthe::labyrinthe(istream& input, ostream& output)
{
	string inputText;
	ifstream fichier;

	do
	{
		//
		output << "Nombre du fichier du labyrinthe : ";
		getline(input, inputText);

		//Reformat du nombre pour trouver le fichier
		inputText.insert(0, "maps/labyrinthe");
		inputText.append(".txt");

		fichier.open(inputText);

		if (!fichier)
			output << "Le fichier '" << inputText << "' n'a pas été trouvé." << endl;

		else
			break;
	} while (true);

	//Enregistre les coordonnées du début et de la fin
	_mapLab.init(fichier);
	fichier >> _posDepart.x() >> _posDepart.y()
		>> _posArrivee.x() >> _posArrivee.y();

	//Définie les orientations
	_posDepart.orientation() = 'N';
	_posArrivee.orientation() = 'A';

	fichier.close();
}

//	Constructeurs / Destructeur
//================================

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

//Vérifie si la case donnée est possible d'y bouger
bool labyrinthe::canMove(const deplacement& pos, deplacement& posToCheck) const
{
	//Check nord
	if (_mapLab.at(pos.x(), pos.y() - 1) == '0')
	{
		posToCheck.init(pos.x(), pos.y() - 1, 'N');
		return true;
	}

	//Check est
	if (_mapLab.at(pos.x() + 1, pos.y()) == '0')
	{
		posToCheck.init(pos.x() + 1, pos.y(), 'E');
		return true;
	}

	//Check sud
	if (_mapLab.at(pos.x(), pos.y() + 1) == '0')
	{
		posToCheck.init(pos.x(), pos.y() + 1, 'S');
		return true;
	}

	//Check ouest
	if (_mapLab.at(pos.x() - 1, pos.y()) == '0')
	{
		posToCheck.init(pos.x() - 1, pos.y(), 'O');
		return true;
	}

	//S'il ne peut pas bouger à l'emplacement
	return false;
}

//Vérifie si la position est celle d'arrivée
bool labyrinthe::arrived(const deplacement& pos) const
{
	if (pos.x() != getPosArriver().x() || pos.y() != getPosArriver().y())
		return false;

	return true;
}

//Obtient l'objet map du labyrinthe
customMap<char>& labyrinthe::getMap()
{
	return _mapLab;
}

//Clear le labyrinthe
void labyrinthe::clear()
{
	_mapLab.clear();
}

void labyrinthe::print() const
{
}