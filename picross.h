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
  void remplirCasesSureBl(int* Res,int *Tg, int *Td, size_t n, Liste& L);
  bool isLigneFinie(size_t ind, bool b) const;
  void setLignesFinies(bool b) const;
  bool isPicrossFini() const;
  void afficheP(std::ostream&) const;
  /**
  * \fn   void SLPG(int* Tab,size_t n,Cell* L)const;
  * \brief Fonction qui donne la solution la plus a gauche en fonction d'une liste L
  * \param[in,out] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
  * \param[in]  n : Taille du dit tableau;
  * \param[in]  L : Premiere cellule de la liste des indices;
  */
  void SLPG(int*, size_t, Liste&);
  void SLPD(int*, size_t, Liste&);
  /**
  * \fn SLG(int* Tab,size_t n,Cell* P,size_t i,bool &poss)const;
  * \brief Fonction recursive qui retourne la solution la plus a gauche de Tab en fonction de P (tableau rempli uniquement de -1 et 1)
  * \param[in,out] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non egalement utiliser comme tableau de retour;
  * \param[in]  n : Taille du dit tableau;
  * \param[in]  P : Premiere cellule de la liste des indices;
  * \param[in] i : indice a partir duquel on interagit avec Tab(voir Placer1bloc);
  * \param[in,out] poss : retour de la fonction permettant de sa voir si l'hypothese faite est la bonne
  */
  void SLG(int*, size_t, Cell*, size_t, bool);
  /**
  * \fn PlacerBloc(int* Tab,size_t n,size_t val,size_t i,bool poss)const
  * \brief Fonction qui tente de placer le bloc val directement en i et renvoi si cela est possible
  * \param[in,out] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
  * \param[in]  n : Taille du dit tableau;
  * \param[in]  val : Taille du bloc;
  * \param[in] i : indice a partir duquel on tente de placer le bloc;
  * \param[in,out] poss : retour de la fonction permettant de sa voir si je peux ou non le placer
  */
  void PlacerBloc(int*, size_t, size_t, size_t, bool&);
  /**
   * \fn Verification(int *Tab,size_t j,size_t n)const;
   * \brief verifie si les cases entre j et n sont non-noires
   * \param[in] Tab : Tableau representant une ligne/colonne avec des cases existante(valeur -1,1) ou non;
   * \param[in]  n : Taille du dit tableau;
   * \param[in]  j : indice a partir duquel on verifie;
   * \return trivial a partir du brief
  */
  bool Verification(int* , size_t, size_t);
  /**
  * \fn Numeroter(int*, size_t);
  * \brief identifie les blocs de cases noires (1..2..)
  */
  void Numeroter(int*, size_t);
  /**
  * \fn Fusion(int*, int*, int*, size_t);
  * \brief Fusion simple entre TG et TD là ou les valeures sont égales
  */
  void Fusion(int*, int*, int*, size_t);
  /**
  * \fn Push(int*,size_t,bool);
  * \brief brute push dans la matrice a l'indice ind, 0>ligne 1>colonne
  */
  void Push(int*,size_t,bool);
  /**
  * \fn TINY_SOL(size_t nbl, size_t nbc, size_t rec);
  * \brief appel recursif sur toutes les lignes et colonnes de solLignes et
  * solColonnes dans le but d'initialiser ligModif et colModif pour FAT_SOL
  */
  void TINY_SOL(size_t, size_t, size_t);
  /**
  * \fn FAT_SOL(size_t nbIndLig, size_t nbIndCol, size_t nbl, size_t nbc);
  * \brief appel recursif FATCOL&FATLIG tq colModif et ligModif contiennent des cell
  * càd tant que l'on modifie des lignes ou des colonnes
  */
  void FAT_SOL(size_t, size_t, size_t, size_t);
  /**
  * \fn FAT_LIG(size_t chk, size_t taille);
  * \brief appel recursif sur tout les indices de ligModif
  */
  void FAT_LIG(size_t, size_t);
  void FAT_COL(size_t, size_t);
  void solLignes(size_t, size_t);
  void solColonnes(size_t, size_t);
 void amodif(bool ligne, int* Av, int*Ap);
};
std::ostream& operator<<(std::ostream&, const Picross&);
void afftableau(const int*, int);
void creetableau(int*,int);
int* initTab(size_t);
Liste* inverseL(const Liste&);
void inverseT(int*, size_t);
#endif
