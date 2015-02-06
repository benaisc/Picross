#ifndef __MATRICE_H__
#define __MATRICE_H__
#include <string>
#include <iostream>
//enum class Color  {?, rouge, noir};

class Matrice
{
private:
  int** mat;
  size_t nbl;
  size_t nbc;
public:

  Matrice(size_t nbl, size_t nbc);
  ~Matrice();

  int** getMat()const;
  size_t getNbc()const;
  size_t getNbl()const;
  void affiche_ter(std::ostream& f)const;
};
#endif
