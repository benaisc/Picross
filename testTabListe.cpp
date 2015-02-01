#include "cell.h"
#include "liste.h"
#include "tabListe.h"

using namespace std;


int main(int argc, char** argv)
{
  Liste L1;
  Cell a1(1);
  Cell b1(2);
  L1.setSuivant(L1.getPremier(), &a1);
  L1.setSuivant(&a1, &b1);
  L1.afficheL();

  Liste L2;
  Cell a2(3);
  Cell b2(4);
  L2.setSuivant(L2.getPremier(), &a2);
  L2.setSuivant(&a2, &b2);
  L2.afficheL();

  TabListe T(2);
  T[0]=L1;
  T[1]=L2;

  T.afficheT();

  return 0;
}
