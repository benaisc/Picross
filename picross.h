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
  Picross(Matrice mat,TabListe lignes,TabListe colonnes);
  //accesseur
  TabListe getLignes()const;
  TabListe getColonnes()const;
  Matrice  getMat()const;
  //Methode
  void affiche_ter(std::ostream& f)const;
  
};
std::ostream& operator<<( std::ostream &flux, Picross const& picross );
#endif
