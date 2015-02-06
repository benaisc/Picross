#ifndef __MATRICE_H__
#define __MATRICE_H__

//enum class Color  {?, rouge, noir};

class Matrice
{
private:
  int** mat;
  size_t nbc, nbl;
public:
  //accesseurs
  Matrice(size_t, size_t);
  //methode
  int** getMat()const;
  size_t getNbc()const;
  size_t getNbl()const;
  void affiche_ter()const;
};
#endif
