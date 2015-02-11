#include "tabListe.h"

TabListe::TabListe(size_t v) : taille(v), tab(new Liste [taille]){}

TabListe::~TabListe()
{
  if(taille != 0)
  {
    delete [] tab;
  }
}

size_t TabListe::getTaille() const
{
  return taille;
}

void TabListe::error() const
{
  std::cerr << "Attention i>taille" << std::endl;
  exit(EXIT_FAILURE);
}

Liste& TabListe::operator[](size_t i)
{
  if(i>taille)
  {
    error();
  }
  return tab[i];
}
/*
Cette fonction seg_fault mais est à priori inutile
TabListe& TabListe::operator=(TabListe &L)
{
  if(taille != 0)
  {
    delete [] this->tab;
  }
  taille=L.getTaille();
  this->tab=new Liste [taille];
  for(size_t i=0; i<taille; i++)
  {
    this->tab[i]=L[i];
  }
  return *this;
}
*/
/*
Liste& TabListe::operator=(const Liste& L)
{
  this=NULL;
  this.setLongueur(L.getLongueur());
  Cell *ptr=L.getPremier();
  while(!isnull(ptr))
  {
    Cell a(ptr->getVal());
    this.ajoutFin(a);
    ptr=ptr->getSuiv();
  }
  return *this;
}
*/
void TabListe::afficheT(std::ostream &os) const
{
  for(size_t i=0; i<taille; i++)
  {
    os << "tab[" << i << "] : ";
    this->tab[i].afficheL(os);
  }
}

std::ostream &operator<<(std::ostream &os, TabListe &T)
{
  T.afficheT(os);
  return os;
}
