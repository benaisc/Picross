#include "cell.h"
#include "liste.h"
#include "tabListe.h"

using namespace std;


int main(int argc, char** argv)
{
  Liste L1;
  Cell a1(1);
  Cell b1(2);
  L1.ajoutFin(a1);
  L1.ajoutFin(b1);
  L1.afficheL();

  Liste L2;
  Cell a2(3);
  Cell b2(4);
  L2.ajoutFin(a2);
  L2.ajoutFin(b2);
  L2.afficheL();

  TabListe T(2);
  T[0]=L1;
  T[1]=L2;

  T.afficheT(cout);

  cout << T;

  return 0;
}
