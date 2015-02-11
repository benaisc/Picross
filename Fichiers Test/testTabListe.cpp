#include "cell.h"
#include "liste.h"
#include "tabListe.h"

using namespace std;


int main(int argc, char** argv)
{
  Cell a(1);
  Cell b(2);
  Cell c(3);
  TabListe T(1);

  cout << "//test operator[]" << endl;
  T[0].ajoutFin(a);
  T[0].ajoutFin(b);
  T[0].ajoutFin(c);
  T[0].afficheL(cout);
  cout << T[0];
  cout << "Premier élément par T[]()=" << T[0](1).getVal() << endl;

  cout << "//test operator<<" << endl;
  cout << T;

  /*
  cout << "//test operateur=" << endl;
  TabListe A(2);
  A=T;
  cout << A;
  */

  return 0;
}
