#include "liste.h"


Liste::Liste():tete(NULL){}

Liste::~Liste()
{
  Cell* p=tete;
  while(!isnull(p))
  {
    tete=p->getSuiv();
    std::cout << "Dans le destructeur A, p=" << p->getVal() <<" tete="<< tete->getVal() << std::endl;
    delete p;
    p=tete;
    std::cout << "Dans le destructeur B, p=" << p->getVal() << std::endl;
  }
}

bool Liste::isnull(Cell* p) const
{
  return !p;
}

Cell* Liste::getPremier() const
{
  return tete;
}

void Liste::setSuivant(Cell* p, Cell* suiv)
{
  if(!isnull(p))
  {
    p->setSuiv(suiv);
  }
  else{tete=suiv;}
}

void Liste::affiche() const
{
  Cell* p=tete;
  std::string sep="";
  while(!isnull(p))
  {
    std::cout << sep << p->getVal();
    p=p->getSuiv();
    sep="->";
  }
  std::cout << std::endl;
}
