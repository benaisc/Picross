#include "cell.h"
#include "liste.h"
#include "tabListe.h"

using namespace std;


int main(int argc, char** argv)
{
  Cell* a = new Cell(1);
  TabListe T(1);

  cout << "//test operator[], affichages" << endl;
  T[0].ajoutFin(a);
  T[0].putFin(2);
  T[0].putFin(3);
  T[0].afficheL(cout);
  cout << T;
  cout << "Premier élément de la liste par T[]()=" << T[0](1).getVal() << endl;

  cout << "//test error handler" << endl;
  cout << T[999];

  return 0;
}
