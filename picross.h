#ifndef __PICROSS_H__
#define __PICROSS_H__
#include "tabListe.h"
#include "matrice.h"
#include <fstream>

class Picross
{
 private:
  Matrice mat;
  TabListe lignes;
  TabListe colonnes;
 public:

  //constructeur
  Picross(size_t, size_t);
  void remplirTabListe(std::ifstream& f);
  //accesseur
  TabListe getLignes() const;
  TabListe getColonnes() const;
  Matrice getMat() const;
  //Methode
  int* tabGauche(size_t ind, bool b);
  int* tabDroite(size_t ind, bool b);
  int* mergeTab(int *T1, int *T2, int n);
  void remplirMat(size_t ind, int* T, bool b);

  void afficheP(std::ostream&) const;
};
std::ostream& operator<<(std::ostream&, Picross&);
#endif
