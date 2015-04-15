#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  ifstream f;
  f.open(argv[1]);
  //f.open("./hachure_big");

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

    P.TINY_SOL_iter();

    cout << P << endl;

    if(!P.isPicrossFini())
    {
      bool R;
      P.backtrack(R);
      cout<< P.getMatrice() << endl;
    }
  }
  f.close();
  return 0;
}
