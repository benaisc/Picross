#ifndef __MATRICE_H__
#define __MATRICE_H__

#include "Case.h"


class Matrice
{
private:
	Case** mat;
	size_t n, m;
public:
	Matrice(size_t, size_t);
	~Matrice();

};
#endif