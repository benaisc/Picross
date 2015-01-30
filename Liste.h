#ifndef __LISTE_H__
#define __LISTE_H__

#include "Cell.h"


class Liste
{
private:
	Cell* tete;
	Cell* queue;
public:
	Liste();
	~Liste();

	size_t valeur() const;
	size_t longueur() const;
	void setSuivant(Cell* p, Cell* suiv){p->setSuiv(suiv);};

};
#endif
