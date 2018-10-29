/*	
	Auteur		: Émile Loiselle
	Date		: 29 octobre 2018
	Programme	: labyrinthe.h
	But			: Gère les opérations et les comparaisons entre la
				  carte du labyrinthe et le robot.
*/

#pragma once
#include <iostream>

using namespace std;

class labyrinthe
{
	private:
		
		map _map;
	
		int _nbCol;
		int _nbLin;
		
		int _posDepart;
		int _posArrivee;
		
	public:
	
		labytinthe();
		labytinthe(map m);
		~labyrinthe();
		
		print();
		
		bool canMove(); const
		bool arrived(); const
		
}

labyrinthe::labytinthe()
{
	_nbCol = 0;
	_nbLin = 0;
	_posDepart = null;
	_posArrivee = null;
	_map = null;
}

labyrinthe::labytinthe(map m)
{
	
}

labyrinthe::~labyrinthe();

bool labyrinthe::canMove() const
{
	
}

bool labyrinthe::arrived(deplacement d) const
{
	if (r.pos == _posArrivee)
		return true;
	else 
		return false;
}