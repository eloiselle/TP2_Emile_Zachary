/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 5 novembre 2018
	Programme	: pile.h
	But			: Objet qui permet d'ajouter, enlever
				  et modifier l'element du dessus d'une pile.
==================================================================*/
#pragma once
#include <assert.h>

using namespace std;

template <class TYPE>
class pile
{
private:
	struct cellule
	{
		TYPE element;	// élément ds la cellule
		cellule *next; 	// pointeur vers prochaine cellule

		cellule(const TYPE& e, cellule * n)
		{
			element = e;
			next = n;
		}
	};
	cellule  *_top;				// 1er élément de la pile
	int  	  _size;			// taille (nb. élément) de la pile
public:
	pile();						// constructeurr & destructeurr
	~pile();

	void push(const TYPE& e);	//ajoute un nouveau dessus
	TYPE pop();					//enlève le dessus

	const TYPE& top() const;	//retourne le dessus, mais dépile pas
	TYPE& top();				//retourne le dessus, mais en setteur
	int size()const;			//retourne le nb d’élément

	bool empty() const;			//si la pile est vide
	void clear();				//vide la pile

	const pile& operator=(const pile& s);	//affectateur
	bool operator==(const pile& s)const;	//comparaison de 2 piles
};

//Constructeur
template <class TYPE>
pile<TYPE>::pile()
{
	next = nullptr;
	_size = 0;
}

//Deconstructeur
template <class TYPE>
pile<TYPE>::~pile()
{
	clear();
}

//Ajoute un nouveau dessus
template <class TYPE>
void pile<TYPE>::push(const TYPE& e)
{
	next = new cellule(e, premier);
}

//Enlève le dessus
template <class TYPE>
TYPE pile<TYPE>::pop()
{
	assert(!empty());
	TYPE valeur = _top->element;
	cellule *aDetruire = _top;
	_top = _top->next;
	delete aDetruire;
	return valeur;
}

//Si la pile est vide
template <class TYPE>
bool pile<TYPE>::empty() const
{
	return _top == nullptr;
}

//Vide la pile
template <class TYPE>
void pile<TYPE>::clear()
{
	while (!empty())pop();
}

//Retourne le dessus, mais dépile pas
template <class TYPE>
const TYPE& pile<TYPE>::top() const
{
	assert(!empty());
	return _top->element;
}

//Retourne le dessus, mais en setteur
template<class TYPE>
TYPE& pile<TYPE>::top()
{
	assert(!empty());
	return _top->element;
}

//Retourne le nb d’élément
template <class TYPE>
int pile<TYPE>::size() const
{
	return _size;
}

//Affectateur
template <class TYPE>
const pile<TYPE>& pile<TYPE>::operator=(const pile& s)
{
	if (this == &src)
	{
		return *this;		//autoallocation
	}

	clear();

	if (!s.empty())
	{
		cellule* 	tempI, tempE = p._top;

		tempI = _top = new cellule(tempE->element, nullptr);
		tempE = tempE->next;

		while (tempE != nullptr)
		{
			tempI = tempE->next = new cellule(tempE->element, nullptr);
			tempE = tempE->next;
		}
	}
	return *this;		//retour
}

//Comparaison de 2 piles
template<class TYPE>
bool pile<TYPE>::operator==(const pile & s) const
{
	return false;
}
