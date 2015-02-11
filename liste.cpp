#include "liste.h"


Liste::Liste():tete(NULL), longueur(0){}

bool Liste::isnull(Cell* p) const
{
  return !p;
}

Liste& Liste::operator=(const Liste& c)
{
  tete=NULL;
  Cell *ptr=c.getPremier();
  for(size_t i=0; i<c.getLongueur();i++)
  {
    Cell a=Cell(ptr->getVal());
    this->ajoutFin(a);
  }
  return *this;
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

size_t Liste::somElem() const
{
    int som = 0;
    Cell* ptr=tete;
    while (!isnull(ptr))
      {
        som += ptr->getVal();
        ptr = ptr->getSuiv();
      }
    return som+longueur-1;
}

std::ostream &operator<<(std::ostream &os, Liste &Li)
{
  Cell* ptr=Li.getPremier();
  std::string sep="";
  size_t i=1;
  while(i<=Li.getLongueur())
  {
    std::cout << sep << ptr->getVal();
    ptr=ptr->getSuiv();
    sep="->";
    i++;
  }
  std::cout << std::endl;
  return os;
}
