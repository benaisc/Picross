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

void Liste::setLongueur(size_t i)
{
  longueur=i;
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

Liste& Liste::operator=(const Liste& c)
{
  this->tete=NULL;
  longueur=c.getLongueur();
  Cell *ptr=c.getPremier();
  while(!isnull(ptr))
  {
    Cell a(ptr->getVal());
    this->ajoutFin(a);
    ptr=ptr->getSuiv();
  }
  return *this;
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

void Liste::afficheL(std::ostream &os) const
{
  Cell* ptr=tete;
  std::string sep="";
  while(!isnull(ptr))
  {
    os << sep << ptr->getVal();
    ptr=ptr->getSuiv();
    sep="->";
  }
  os << std::endl;
}

std::ostream &operator<<(std::ostream &os, Liste &L)
{
  L.afficheL(os);
  return os;
}
