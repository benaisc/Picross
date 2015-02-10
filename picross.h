#ifndef __PICROSS_H__
#define __PICROSS_H__
#include "tabListe.h"
#include "matrice.h"

class Picross
{
 private:
  Matrice mat;
  TabListe lignes;
  TabListe colonnes;
 public:

  //constructeur
  Picross(Matrice,TabListe,TabListe);
  //accesseur
  TabListe getLignes()const;
  TabListe getColonnes()const;
  Matrice  getMat()const;
  //Methode
  void afficheP(std::ostream&)const;

};
std::ostream& operator<<(std::ostream&, Picross&);
#endif
