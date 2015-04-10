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
  int* getLigneMat(size_t ind) const;
  int* getColonneMat(size_t ind) const;
  Matrice& getMatrice();
  Liste& getColModif();
  Liste& getLigModif();

  /**
  * \fn   void SLPG(int* Tab,size_t n,Cell* L)const;
  * \brief Fonction qui donne la solution la plus a gauche en fonction d'une liste L
  */
  void SLPG(int*, size_t, Liste&);
  void SLPD(int*, size_t, Liste&);
  /**
  * \fn SLG(int* Tab,size_t n,Cell* P,size_t i,bool &poss)const;
  * \brief Fonction recursive qui retourne la solution la plus a gauche de Tab
  */
  void SLG(int*, size_t, Cell*, size_t, bool&);
  /**
  * \fn PlacerBloc(int* Tab,size_t n,size_t val,size_t i,bool poss)const
  * \brief Fonction qui tente de placer le bloc val directement en i,
  * false si il y à un -1 génant ou un 1 au bout
  */
  void PlacerBloc(int*, size_t, size_t, size_t, bool&);
  /**
   * \fn Verification(int *Tab,size_t j,size_t n)const;
   * \brief verifie si les cases entre j et n sont non-noires
   * (false s'il y à un noir après le dernier bloc placé)
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
  * \fn remplirCasesSureBl(int* Res,int *Tg, int *Td, size_t n, Liste& L);
  * \brief TODO
  */
  void remplirCasesSureBl(int*,int*, int*, size_t, Liste&);
  /**
  * \fn isFini(int* Merge, size_t taille, Liste &L);
  * \brief appel chkSUM et met le booleen de la liste à true si T terminé
  */
  void isFini(int*, size_t, Liste&);
  /**
  * \fn chkSUM(int* T, Liste& L, size_t n);
  * \brief compte les cases noires et les blocs, true si le compte est bon
  */
  bool chkSUM(int*, Liste&, size_t);
  /**
  * \fn AMODIF(bool B, int* Av, int*Ap, size_t n);
  * \brief ajoute à ligModif|colModif les colonnes|lignes modifiées
  */
  void amodif(bool ligne, int* Av, int*Ap, size_t n);
  /**
  * \fn Push(int*,size_t,bool);
  * \brief brute push dans la matrice a l'indice ind, 0>ligne 1>colonne
  */
  void Push(int*,size_t,bool);
  /**
  * \fn solLignes(size_t taille, size_t ind);
  * \brief appel sur la ligneMat[ind] de SLPG SLPD Fusion CasesBlanches AMODIF & Push
  */
  void solLignes(size_t, size_t);
  void solColonnes(size_t, size_t);
  /**
  * \fn TINY_SOL_iter(size_t nbl, size_t nbc, size_t rec);
  * \brief appel sur toutes les lignes et colonnes de solLignes et
  * solColonnes dans le but d'initialiser ligModif et colModif pour FAT_SOL
  */
  void TINY_SOL_iter(size_t, size_t);
  /**
  * \fn FAT_SOL(size_t nbIndLig, size_t nbl, size_t nbc);
  * \brief appel recursif FATCOL&FATLIG tq colModif et ligModif contiennent des cell
  * càd tant que l'on modifie des lignes ou des colonnes
  */
  void FAT_SOL(size_t, size_t, size_t);
  /**
  * \fn FAT_LIG(size_t chk, size_t taille);
  * \brief appel recursif sur tout les indices de ligModif
  */
  void FAT_LIG(size_t);
  void FAT_COL(size_t);
  /** \fn VerifMatrice(size_t ind, bool B) const;
  * \brief false si la ligne ou colonne de matrice n'est pas correctement rempli
  * càd si le nombre de blocs noirs et le nombre de cases noirs est différent de celui attendu
  */
  bool VerifMatrice(size_t ind, bool B) const;
  /** \fn setLCFini();
  * \brief appel de VerifMatrice sur toutes les lignes et colonnes non finies
  * et pose à true les listes fini
  */
  void setLCFini();
  /** \fn isPicrossFini() const;
  * \brief false si la liste d'une ligne ou d'une colonne n'est pas à true
  */
  bool isPicrossFini() const;
  void afficheP(std::ostream&) const;
};
std::ostream& operator<<(std::ostream&, const Picross&);
void afftableau(const int*, int);
Liste* inverseL(const Liste&);
void inverseT(int*, size_t);
#endif
