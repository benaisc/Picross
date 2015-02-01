#ifndef __TABLISTE_H__
#define __TABLISTE_H__

#include "liste.h"


class TabListe
{
private:
	size_t taille;
	Liste* tab;

public:
	TabListe(size_t);
	~TabListe();

	size_t getTaille() const;
	void afficheT() const;
	TabListe& operator[](const TabListe& T);


};
#endif
