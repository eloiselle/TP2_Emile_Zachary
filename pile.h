/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 5 novembre 2018
	Programme	: pile.h
	But			: Objet qui permet d'ajouter, enlever
				  et modifier l'element du dessus d'une pile.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once

//Default Librairies
#include <assert.h>

using namespace std;

//================================
//			Déclarations
//================================

template <class TYPE>
class pile
{
protected:

	struct cellule
	{
		TYPE element;			//Élément dans la cellule
		cellule	*next; 			//Pointeur vers la prochaine cellule

		cellule(const TYPE& e, cellule * n)		//Constructeur avec 2 paramètres
		{
			element = e;
			next = n;
		}
	};

	cellule	*_top;			//1er élément de la pile
	int	_size;				//Nombre d'élément de la pile

	pile(const pile<TYPE>& p) {};		//Copieur protégé

public:

	//Constructeurs et destructeur
	pile();
	~pile();

	void push(const TYPE& e);	//Ajoute un dessus
	void pop();					//Enlève un dessus

	const TYPE& top() const;	//Obtient la valeure au dessus de la pile
	TYPE& top();				//Obtient la valeure au dessus de la pile (const)
	int size() const;			//Obtient la grandeur de la pile

	bool isEmpty() const;		//Vérifie si la pile est vide
	void clear();				//Vide la pile

	//Opérateurs
	const pile<TYPE>& operator=(const pile& s);
	bool operator==(const pile& s)const;
};

//================================
//			Définitions
//================================

template<class TYPE>
pile<TYPE>::pile()
{
	_top = nullptr;
	_size = 0;
}

template<class TYPE>
pile<TYPE>::~pile()
{
	clear();
}

template<class TYPE>
void pile<TYPE>::push(const TYPE & e)
{
	_size++;
	_top = new cellule(e, _top);
}

//Enlève le premier élément dans la pile
template<class TYPE>
void pile<TYPE>::pop()
{
	assert(!isEmpty());
	_size--;

	cellule *temp = _top;
	_top = _top->next;

	delete temp;
}

template<class TYPE>
const TYPE & pile<TYPE>::top() const
{
	assert(!isEmpty());
	return _top->element;
}

template<class TYPE>
TYPE & pile<TYPE>::top()
{
	assert(!isEmpty());
	return _top->element;
}

template<class TYPE>
int pile<TYPE>::size() const
{
	int compteur = 0;

	cellule* tempE = _top;

	//Tant qu'on ne revient pas au début
	while (tempE != nullptr)
	{
		tempE = tempE->next;
		compteur++;
	}
	return compteur;
}

template<class TYPE>
bool pile<TYPE>::isEmpty() const
{
	return _top == nullptr;
}

template<class TYPE>
void pile<TYPE>::clear()
{
	while (!isEmpty())
		pop();
}

//			Opérateurs
//================================

//Copie le contenu d'une pile vers une autre
template<class TYPE>
const pile<TYPE>& pile<TYPE>::operator=(const pile& p)
{
	//Si les 2 piles sont déjà identiques
	if (this == &p)
		return *this;

	clear();
	if (!p.isEmpty())
	{
		cellule* tempI = nullptr;
		cellule* tempE = p._top;

		//Copie un élément de la pile source en tant que première case dans la pile cible
		tempI = _top = new cellule(tempE->element, nullptr);
		tempE = tempE->next;

		//Tant qu'on ne revient pas au début
		while (tempE != nullptr)
		{
			//Copie un élément de la pile source en tant que nouvelle case dans la pile cible
			tempI = tempI->next = new cellule(tempE->element, nullptr);
			tempE = tempE->next;
		}

		//Copie la grandeur
		_size = p.size();
	}
	return *this;
}

//Compare deux piles
template<class TYPE>
bool pile<TYPE>::operator==(const pile & p) const
{
	//2 piles de grandeur égale
	if (_size == p.size())
	{
		//Marqueurs sur les 2 piles à comparer
		cellule* tempExp = p._top;
		cellule* tempImp = _top;

		//Tant qu'on a pas fait le tour de la pile
		while (tempExp != nullptr)
		{
			//Si l'élément n'est pas égale à l'autre
			if (tempExp->element != tempImp->element)
			{
				//Un élément n'est pas égal à l'autre
				return false;
			}

			//Passe aux prochaines cases
			tempExp = tempExp->next;
			tempImp = tempImp->next;
		}

		//Tous les éléments sont identiques
		return true;
	}

	//Les 2 piles ne sont pas de grandeur égales
	return false;
}