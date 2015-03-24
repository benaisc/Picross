#include "picross.h"
using namespace std;


int main(int argc, char** argv)
{
  Picross P(5,5);
  //la liste qui sert d'exemple
  Liste L;
  L.putFin(3);

  //les tableaux, normalement issus de la ligne de matrice traitée
  int TG[5]={0,0,0,0,0};
  int TD[5]={0,0,0,0,0};
  afftableau(TG,5);

  //on appel les solutions les + a gauches|droites
  //on place l'indice des cellules dans les cases noires
  P.SLPG(TG,5,L);
  P.Numeroter(TG,5);
  afftableau(TG,5);

  P.SLPD(TD,5,L);
  P.Numeroter(TD,5);
  afftableau(TD,5);

  //on fusionne les cases identiques
  int* Result=initTab(5);
  P.Fusion(Result,TG,TD,5);
  afftableau(Result,5);

  //on est prêts à push Result dans la matrice
  //à ce point Result correspond à la ligne de la matrice traitée + les blocs noirs 'surs'
  //calculés avec SLPG et SLPD
  //on peut donc la brute push sans en vérifier le contenu
  delete [] Result;
  return 0;
}
