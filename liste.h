#ifndef __LISTE_H__
#define __LISTE_H__

#include "cell.h"
#include <iostream> //il sera utilisé par la suite
#include <stdlib.h>//pour exit

class Liste
{
private:
	Cell* tete;
	size_t longueur;

public:
	Liste();
	//1 si null
	bool isnull(Cell*) const;
	//Renvoi la tete de liste
	Cell* getPremier() const;
	size_t getLongueur() const;
	//sucre, L(1)=tete en temp constant
	Cell& operator()(size_t i);
	void ajoutFin(Cell&);
	//Affiche la liste
	void afficheL() const;
	
	int somElem()const;
	//Renvoi la somme des elements de la liste
};
#endif
