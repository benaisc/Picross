#ifndef __MATRICE_H__
#define __MATRICE_H__
#include <string>
#include <iostream>



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
    int getValue(size_t nl, size_t nc) const;
    void setValue(size_t nl, size_t nc, size_t v);
    void setLigne(size_t nl, int* T);
    void setColonne(size_t nc, int* T);

    void   afficheM(std::ostream&) const;
};
std::ostream &operator<<(std::ostream&, const Matrice&);
#endif
