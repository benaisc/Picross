#include "fonction.h"


void remplirTabListe(std::ifstream& f, TabListe& T)
{
  size_t val,i=0;
  while(i<T.getTaille())
  {
    while(f.peek()!='\n')
    {
      f>>val; //je lit l'indice
      T[i].putFin(val); //je le rajoute a la liste
    }
    f.ignore(); //le '\n'
    i++;  //on change de ligne
  }
}

void lecture(std::ifstream& f)
{
  size_t nbl, nbc;
  f>>nbl>>nbc;
  std::cout << nbl << " " << nbc << std::endl;
  f.ignore(); //le '\n'

  TabListe ligne(nbl);
  std::cout << "----------Maintenant remplissons Lignes----------" << std::endl;
  remplirTabListe(f, ligne);
  std::cout << "----------Lignes remplies avec succes------------" << std::endl;
  std::cout << ligne;

  TabListe colonne(nbc);
  std::cout << "----------Maintenant remplissons Colonnes--------" << std::endl;
  remplirTabListe(f,colonne);
  std::cout << "----------Colonnes remplies avec succes----------" << std::endl;
  std::cout << colonne;

  //Matrice matrice(nbl,nbc);
  //return Picross(matrice,ligne,colonne);
}
