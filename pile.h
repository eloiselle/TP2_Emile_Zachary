/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 5 novembre 2018
	Programme	: pile.h
	But			: Objet qui permet d'ajouter, enlever
				  et modifier l'element du dessus d'une pile.
==================================================================*/
/*
Auteur:		Émile Loiselle
Date:		1 novembre 2018
Programme:	pile.h
But:		Manipuler une pile de manière "First In First Out"
			avec des opérations de base.
*/

#pragma once
#include <iostream>
#include <assert.h>

template <class TYPE>
class pile
{
protected:
	struct cellule
	{
		TYPE element;	//élément ds la cellule
		cellule	*next; 	//pointeur vers prochaine cellule

		cellule(const TYPE& e, cellule * n)
		{
			element = e;
			next = n;
		}
	};

	cellule	*_top;	//1er élément de la pile
	int	_size;		//taille (nb. élément) de la pile

	//Copieur protégé
	pile(const pile<TYPE>& p);

public:

	//Constructeurs et destructeur
	pile();
	~pile();

	void push(const TYPE& e); //Ajoute un dessus
	void pop(); //Enlève un dessus

	const TYPE& top() const;
	TYPE& top();
	int size() const;

	bool isEmpty() const;
	void clear();

	//const pile<TYPE>& operator=(const pile& s);
	//bool operator==(const pile& s)const;
};

template<class TYPE>
pile<TYPE>::pile()
{
	_top = nullptr;
	_size = 0;
}

template<class TYPE>
pile<TYPE>::~pile()
{
	_top = nullptr;
	_size = 0;
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
	assert(_size > 0);
	_size--;

	cellule *temp = _top;
	_top = _top->next;

	delete temp;
}

template<class TYPE>
const TYPE & pile<TYPE>::top() const
{
	assert(_size > 0);
	return _top->element;
}

template<class TYPE>
TYPE & pile<TYPE>::top()
{
	assert(_size > 0);
	return _top->element;
}

template<class TYPE>
int pile<TYPE>::size() const
{
	return _size;
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

//template<class TYPE>
//const pile<TYPE>& pile<TYPE>::operator=(const pile& p)
//{
//	if (this == &src)
//		return *this;
//
//	clear();
//	if (!p.isEmpty())
//	{
//		cellule* tempI;
//		cellule* tempE = p._top;
//
//		tempI = _top = new cellule(tempE->element, nullptr);
//		tempE = tempE->next;
//
//		while (tempE != nullptr)
//		{
//			tempI = tempE->next = new cellule(tempE->element, nullptr);
//			tempE = tempE->next;
//		}
//
//		_size = p.size();
//	}
//	return  *this;
//}

//template<class TYPE>
//bool pile<TYPE>::operator==(const pile & p) const
//{
//	if (_size == p.size())
//	{
//		cellule* temp1 = p.top();
//		cellule* temp2 = top();
//
//		for (int i = 0; i < _size; i++)
//		{
//			if (temp1->element != temp2->element)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	return false;
//}

template<class TYPE>
pile<TYPE>::pile(const pile<TYPE>& p)
{
}
