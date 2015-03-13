#include "picross.h"
#include "liste.h"

using namespace std;

//Methode solution gauche
int* Picross::solGauche(int* ligne, Liste L, size_t i)
{
  Cell* ptr=L.getPremier();
  size_t numBloc=1, j=i;
  int* lsol = ligne;

  while(ptr!=NULL)
  {
    size_t valInd = ptr->getVal();
    if (j>=mat.getNbc())
    {
      std::cout <<"Il n'y a pas de solution gauche pour i="<<i<<std::endl;
      return NULL;
    }
    while(valInd!=0)
    {
      lsol[j]=numBloc;
      valInd--;
      j++;
    }
    j++;
    ptr=ptr->getSuiv();
    numBloc++;
  }
  return lsol;
}

int main(int argc, char** argv)
{
  Liste L;
  L.putFin(2);
  L.putFin(1);
  L.putFin(1);

  Picross P(6,6);

  cout << "afficheL : ";
  L.afficheL(cout);

  int* ligne=P.getLigneMat(1);

  int* lsol = P.solGauche(ligne,L,0);

  for (size_t i=0; i<6; i++)
    {
      cout << lsol[i] << endl;
    }

  return 0;
}
