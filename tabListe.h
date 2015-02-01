#ifndef __TABLI_H__
#define __TABLISTE_H__

#include "Liste.h"


class TabListe
{
private:
	Liste* tab;
	size_t taille;
public:
	TabListe(size_t);
	~TabListe();

};
#endif