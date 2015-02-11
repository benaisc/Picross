#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  TabListe L(2);
  Cell a1(1);
  Cell a2(2);
  L[0].ajoutFin(a1);
  L[1].ajoutFin(a2);
  TabListe C(2);
  Cell b1(3);
  Cell b2(4);
  C[0].ajoutFin(b1);
  C[1].ajoutFin(b2);


  Matrice M(2,2);
  Picross P(M, L, C);
  cout<<"_|_|_"<<endl;
  cout << P;
  return 0;
}
