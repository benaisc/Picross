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
  void setLigneMat(size_t ind, int* Tab);
  int* getLigneMat(size_t ind)const;
  void setColonneMat(size_t ind, int* Tab);
  int* getColonneMat(size_t ind)const;
  Matrice getMat() const;
  //Methode
  void afficheP(std::ostream&) const;
  int* solGauche(int* ligne, Liste L, size_t i);
  void solutionPaD(int* tab, int taille,int indice, bool lig);

};
std::ostream& operator<<(std::ostream&, Picross&);
#endif
