#include "liste.h"


Liste::Liste():tete(NULL), longueur(0){}

bool Liste::isnull(Cell* p) const
{
  return !p;
}

Cell* Liste::getPremier() const
{
  return tete;
}

size_t Liste::getLongueur() const
{
  return longueur;
}

Cell& Liste::operator()(size_t i)
{
  if(i>longueur)
  {
    exit(EXIT_FAILURE);
  }
  else
  {
    if(i<=1)
    {
      return *tete;
    }
    else
    {
      Cell* ptr=tete;
      for(size_t j=1; j<i; j++)
      {
        ptr=ptr->getSuiv();
      }
      return *ptr;
    }
  }
}

void Liste::ajoutFin(Cell& c)
{
  if(longueur==0)
  {
    tete=&c;
  }
  else
  {
    Cell* ptr=tete;
    for(size_t j=1; j<longueur; j++)
    {
      ptr=ptr->getSuiv();
    }
    ptr->setSuiv(c);
  }
  ++longueur;
}

void Liste::afficheL() const
{
  Cell* ptr=tete;
  std::string sep="";
  while(!isnull(ptr))
  {
    std::cout << sep << ptr->getVal();
    ptr=ptr->getSuiv();
    sep="->";
  }
  std::cout << std::endl;
}
