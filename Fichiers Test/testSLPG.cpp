#include "picross.h"
using namespace std;


int main(int argc, char** argv)
{
  Picross P(5,5);
  //la liste qui sert d'exemple
  Liste L;
  L.putFin(1);

  //les tableaux, normalement issus de la ligne de matrice traitée
  int TG[10]={1,0,0,0,0,0,0,0,0,0};
  int TD[10]={1,0,0,0,0,0,0,0,0,0};
  cout << "avant" << endl;
  afftableau(TG,10);

  //on appel les solutions les + a gauches|droites
  //on place l'indice des cellules dans les cases noires
  cout << "SLPG" << endl;
  P.SLPG(TG,10,L);
  P.Numeroter(TG,10);
  afftableau(TG,10);
  cout << "SLPD" << endl;
  P.SLPD(TD,10,L);
  P.Numeroter(TD,10);
  afftableau(TD,10);

  //on fusionne les cases identiques
  int* Result=initTab(10);
  P.Fusion(Result,TG,TD,10);
  afftableau(Result,10);

  //on est prêts à push Result dans la matrice
  //à ce point Result correspond à la ligne de la matrice traitée + les blocs noirs 'surs'
  //calculés avec SLPG et SLPD
  //on peut donc la brute push sans en vérifier le contenu
  delete [] Result;
  return 0;
}
