#ifndef __MATRICE_H__
#define __MATRICE_H__
#include <string>
#include <iostream>
#include "cell.h"
#include "liste.h"

//enum class Color  {?, rouge, noir}; ! ! !

class Matrice
{
  private:
    size_t nbl;
    size_t nbc;
    int** mat;

  public:
    Matrice(size_t nbl, size_t nbc);
    ~Matrice();

    int**  getMat() const;
    size_t getNbc() const;
    size_t getNbl() const;
    void   afficheM(std::ostream&) const;
    size_t estNoire();
    bool   lignesFinies( Liste &L, Cell& c);
};
std::ostream &operator<<(std::ostream&, Matrice&);
#endif
