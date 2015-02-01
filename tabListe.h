#ifndef __TABLISTE_H__
#define __TABLISTE_H__

#include "liste.h"
#include <stdlib.h>//pour exit

class TabListe
{
private:
	size_t taille;
	Liste* tab;

public:
	TabListe(size_t);
	~TabListe();

	size_t getTaille() const;
	//affichage des listes du tab
	void afficheT() const;
	//permet T[i] dans le main
	Liste& operator[](size_t);

	//stratagème pour sortir du programme
	void error() const;
};
#endif
