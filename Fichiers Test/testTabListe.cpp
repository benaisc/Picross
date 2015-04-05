#include "cell.h"
#include "liste.h"
#include "tabListe.h"

using namespace std;


int main(int argc, char** argv)
{
  TabListe T(1);

  cout << "//test operator[], affichage" << endl;
  T[0].putFin(1);
  T[0].putFin(2);
  T[0].putFin(3);
  T[0].putFin(4);
  T[0].putFin(5);
  cout << T;

  cout << "Premier élément de la liste par T[]()=" << T[0](1)->getVal() << endl;

  cout << "Premier élément de la liste par cutHd=" <<T[0].cutHd()<<endl;
  cout << "Premier élément de la liste par cutHd=" <<T[0].cutHd()<<endl;

  cout << T;

  cout << "//test error handler" << endl;
  cout << T[999];

  return 0;
}
