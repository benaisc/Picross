#include "liste.h"


Liste::Liste():tete(NULL), longueur(0), fini(false){}

Liste::~Liste()
{
  Cell* ptr=tete;
  while(!isnull(ptr))
  {
    ptr=ptr->getSuiv();
    delete tete;
    tete=ptr;
  }
  delete ptr;
}

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

bool Liste::getFini() const
{
  return fini;
}

void Liste::setFini(bool b)
{
  fini=b;
}

void Liste::putFin(size_t v)
{
  if(isnull(tete))
  {
    tete=new Cell(v);
  }
  else
  {
    Cell* ptr=tete;
    for(size_t j=1; j<longueur; j++)
    {
      ptr=ptr->getSuiv();
    }
    Cell* c=new Cell(v);
    ptr->setSuiv(c);
  }
  ++longueur;
}

void Liste::ajoutFin(Cell* c)
{
  if(longueur==0)
  {
    tete=c;
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
  Cell *ptr=c.getPremier();
  while(!isnull(ptr))
  {
    this->putFin(ptr->getVal());
    ptr=ptr->getSuiv();
  }
  this->setFini(c.getFini());
  return *this;
}

Cell& Liste::operator()(size_t i) const
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

std::ostream &operator<<(std::ostream &os, const Liste &L)
{
  L.afficheL(os);
  return os;
}
