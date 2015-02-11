#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{

  Liste L1;
  Cell a1(1);
  Cell b1(2);
  L1.ajoutFin(a1);
  L1.ajoutFin(b1);

  Liste L2;
  Cell a2(3);
  Cell b2(4);
  L2.ajoutFin(a2);
  L2.ajoutFin(b2);

  TabListe T(2);
  T[0]=L1;
  T[1]=L2;

  Matrice M(2,2);
  cout<<"test"<<endl;
  Picross P(M, T, T);
  cout<<"test2"<<endl;
  cout << P;
  return 0;
}
