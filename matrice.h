#ifndef __MATRICE_H__
#define __MATRICE_H__
#include "liste.h"



//enum class Color  {?, rouge, noir}; ! ! !

class Matrice
{
  private:
    sint nbl;
    sint nbc;
    int** mat;

  public:
    Matrice(sint nbl, sint nbc);
    ~Matrice();

    int**  getMat() const;
    sint getNbc() const;
    sint getNbl() const;
    int getValue(sint nl, sint nc) const;
    void setValue(sint nl, sint nc, int v);
    void setLigne(sint nl, int* T);
    void setColonne(sint nc, int* T);

    void   afficheM(std::ostream&) const;
    std::string afficheMatrice(size_t i,size_t j)const;
};
std::ostream &operator<<(std::ostream&, const Matrice&);
#endif
