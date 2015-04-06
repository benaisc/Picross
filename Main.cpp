#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  ifstream f;
  //f.open(argv[1]);
  f.open("Tests/waf");

  if(!f.is_open())
  {
    cerr<<"probleme d'ouverture du fichier"<<endl;
    return 1;
  }
  else
  {
    /* On lit le fichier texte et construit le Picross */
    size_t nbl, nbc;
    f>>nbl>>nbc;
    Picross P(nbl,nbc);
    f.ignore(); //le '\n'
    P.remplirTabListe(f);

    P.TINY_SOL_iter(nbl,nbc);

    cout << P << endl;

    if(!P.isPicrossFini())
    {
      cout << P.getLigModif() << endl;
      cout << P.getColModif() << endl;
      P.FAT_SOL(P.getLigModif().getLongueur(),nbl,nbc);
      cout << P << endl;
    }

    cout << boolalpha << P.isPicrossFini() << noboolalpha << endl;
  }

f.close();
return 0;
}
