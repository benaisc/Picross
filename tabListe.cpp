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

void TabListe::afficheT() const
{
  for(size_t i=0; i<taille-1; i++)
  {
    std::cout <<"Ligne n°" << i << " : ";
    this->tab[i].afficheL();
    std::cout << std::endl;
  }
}

TabListe& TabListe::operator[](const TabListe& T)
{
  std::cout << "TO DO";
  return *this;
}
