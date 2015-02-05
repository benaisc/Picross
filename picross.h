#ifndef __PICROSS_H__
#define __PICROSS_H__
#include "tabListe.h"
#include "matrice.h"
class Picross
{
 private:
  Matrice mat;
  Tabliste lignes;
  Tabliste colonnes;
 public:

  //constructeur
  Picross(Matrice mat,Tabliste lignes,Tabliste colonnes);
  //accesseur
  Tabliste getLignes()const;
  Tabliste getColonnes()const;
  Matrice  getMat()const;
  
  //Methode
  void affiche_ter()const;
  
}
ostream& operator<<( ostream &flux, Picross const& picross );
#endif
