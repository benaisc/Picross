#include "liste.h"

Liste::Liste():tete(NULL), longueur(0), fini(false){}

Liste::~Liste()
{
  Cell* ptr=tete;
  while(!isnull(tete))
  {
    ptr=ptr->getSuiv();
    delete tete;
    tete=ptr;
  }
  longueur=0;
  fini=false;
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

bool Liste::getFini() const
{
  return fini;
}

void Liste::setFini(bool b)
{
  fini=b;
}
void Liste::add(Cell* c)
{
  if(isnull(tete))
  {
    tete=c;
  }
  else
  {
    this->operator()(longueur)->setSuiv(c);
  }
  ++longueur;
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

size_t Liste::somCell() const
{
  size_t som = 0;
  Cell* ptr=tete;
  while(!isnull(ptr))
  {
    som += ptr->getVal();
    ptr = ptr->getSuiv();
  }
  return som;
}

Liste& Liste::operator=(const Liste& c)
{
  if(!isnull(tete))
  {
    this->~Liste();
  }
  Cell *ptr=c.getPremier();
  while(!isnull(ptr))
  {
    this->putFin(ptr->getVal());
    ptr=ptr->getSuiv();
  }
  this->setFini(c.getFini());
  return *this;
}

Cell* Liste::operator()(size_t i) const
{
  if(i>longueur)
  {
    exit(EXIT_FAILURE);
  }
  else
  {
    if(i<=1)
    {
      return tete;
    }
    else
    {
      Cell* ptr=tete;
      for(size_t j=1; j<i; j++)
      {
        ptr=ptr->getSuiv();
      }
      return ptr;
    }
  }
}
size_t Liste::cutHd()
{
  size_t val=0;
  if(!isnull(tete))
  {
    val=tete->getVal();
    Cell* ptr=tete->getSuiv();
    delete tete;
    tete=ptr;
    --longueur;
  }
  return val;
}
size_t Liste::cutTl()
{
  size_t val=0;
  if(!isnull(tete))
  {
    if(longueur>1)
    {
      Cell* ptr=tete;
      Liste list;
      for(size_t j=1; j<longueur; j++)
      {
        list.putFin(ptr->getVal());
        ptr=ptr->getSuiv();
      }
      val=ptr->getVal();
      *this=list;
    }
    else
    {
      val=tete->getVal();
      this->~Liste();
      longueur=0;
    }
  }
  return val;
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
/*void Liste::cutTail()
{
  if(longueur!=0)
    {
      if(longueur==1)
	{
	  tete=NULL;
	  longueur--;
	}
    }
  else
    {
      Liste L=*this;
      L(longueur-2).setSuiv(NULL);
      longueur--;
      *this=L;
    }
}*/

std::ostream &operator<<(std::ostream &os, const Liste &L)
{
  L.afficheL(os);
  return os;
}
bool Liste::appartient(size_t val) const
{
  Cell* ptr = tete;
  while (!isnull(ptr) && ptr->getVal() != val)
    {
      ptr = ptr->getSuiv();
    }
  return !isnull(ptr);
}
