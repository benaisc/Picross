#ifndef __PICROSS_H__
#define __PICROSS_H__
#include "tabListe.h"
#include "matrice.h"
#include <fstream>
#include <stdlib.h> //rand de creeTab

class Picross
{
 private:
  Matrice mat;
  TabListe lignes;
  TabListe colonnes;
  Liste colModif;
  Liste ligModif;
 public:
  //constructeur
  Picross(size_t, size_t);
  //les lignes puis les colonnes
  void remplirTabListe(std::ifstream& f);
  //accesseur
  TabListe getLignes() const;
  TabListe getColonnes() const;
  void setLigneMat(size_t ind, int* Tab);
  int* getLigneMat(size_t ind) const;
  void setColonneMat(size_t ind, int* Tab);
  int* getColonneMat(size_t ind) const;
  Matrice getMat() const;
  Liste getColModif()const;
  Liste getLigModif()const;
  /**
  * \fn tabGauche(size_t ind, bool b);
  * \param ind : l'indice de la liste; b : lignes ou colonnes
  * \return T rempli d'entiers identidiant leurs cellules
  */
  int* tabGauche(size_t ind, bool b);
  int* tabDroite(size_t ind, bool b);
  /**
  * \fn mergeTab(int *T1, int *T2, int n);
  * \param tabGauche, tabDroite, taille
  * \return T rempli de 1 là ou les id se chevauchent
  */
  int* mergeTab(int *T1, int *T2, size_t n);
  /**
  * \fn pushMat(size_t ind, int *T, bool b);
  * \brief place les blocs noirs de T dans la matrice
  */
  void pushMat(size_t ind, int *T, bool b);
  /**
  * \fn solCasesSure(bool b)
  * \brief appel sur les 0>lignes, 1>colonnes pour placer les blocs noirs sûrs
  */
  void solCasesSure(bool b);
  int* remplirCasesSure(int *Tg, int *Td, size_t n,const Liste& L);
  bool isLigneFinie(size_t ind, bool b) const;
  void setLignesFinies(bool b) const;
  bool isPicrossFini() const;
  void inverseTab(int *Tab, size_t taille);
  Liste inverseListe(const Liste& L);
  void afficheP(std::ostream&) const;
 /**
  * \fn   void SLPG(int* Tab,size_t n,Cell* L)const;
  * \brief Fonction qui donne la solution la plus a gauche en fonction d'une liste L
  * \param[in,out] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
 * \param[in]  n : Taille du dit tableau;
 * \param[in]  P : Premiere cellule de la liste des indices;
  */
  void SLPG(int* Tab,size_t n,Cell* L)const;
  /**
   * \fn   bool verif(int *Tab,size_t n,size_t j)const;
   * \brief Fonction verifie si les cases entre j et n sont non-noires
   * \param[in] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
   * \param[in]  n : Taille du dit tableau;
   * \param[in]  j : indice a partir duquel on verifie;
   * \return trivial a partir du brief
   */
  void SLPD(int* Tab, size_t n, Liste L);

  bool verif(int *Tab,size_t n,size_t j)const;
 /**
  * \fn Placer1bloc(int* Tab,size_t n,size_t val,size_t i,bool &poss)const
  * \brief Fonction qui tente de placer le bloc val directement en i et renvoi si cela est possible
  * \param[in,out] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
 * \param[in]  n : Taille du dit tableau;
 * \param[in]  val : Taille du bloc;
 * \param[in] i : indice a partir duquel on tente de placer le bloc;
 * \param[in,out] poss : retour de la fonction permettant de sa voir si je peux ou non le placer
  */
  void Placer1bloc(int* Tab,size_t n,size_t val,size_t i,bool &poss)const;
  /**
  * \fn SLG(int* Tab,size_t n,Cell* P,size_t i,bool &poss)const;
  * \brief Fonction recursive qui retourne la solution la plus a gauche de Tab en fonction de P
  * \param[in,out] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
 * \param[in]  n : Taille du dit tableau;
 * \param[in]  P : Premiere cellule de la liste des indices;
 * \param[in] i : indice a partir duquel on interagit avec Tab(voir Placer1bloc);
 * \param[in,out] poss : retour de la fonction permettant de sa voir si l'hypothese faite est la bonne
  */
 
 void SLG(int* Tab,size_t n,Cell* L,size_t i,bool &poss)const;
 void amodif(bool ligne, int* Av, int*Ap);
};
std::ostream& operator<<(std::ostream&, const Picross&);
void afftableau(const int*, int);
void creetableau(int*,int);
int* initTab(int);
Liste inverseL(const Liste&);
#endif
