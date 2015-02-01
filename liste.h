#ifndef __LISTE_H__
#define __LISTE_H__

#include "cell.h"
#include <iostream> //il sera utilisé par la suite

class Liste
{
private:
	Cell* tete;

public:
	Liste();
	//~Liste();useless ?

	//Renvoi un pointeur sur la tete de liste
	Cell* getPremier() const;
	//Prend une cellule et sa suivante
	void setSuivant(Cell*, Cell*);
	//Renvoi 0 si non nul, il faut tester !isnull
	bool isnull(Cell*) const;
	//Affiche la liste
	void afficheL() const;

};
#endif
