#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  ifstream f;
  //f.open(argv[1]);
  f.open("picrosstype.txt");

  if(!f.is_open())
  {
    cerr<<"probleme d'ouverture du fichier"<<endl;
    return 1;
  }
  else
  {
    size_t nbl, nbc;
    f>>nbl>>nbc;
    Picross P(nbl,nbc);
    f.ignore(); //le '\n'

    P.remplirTabListe(f);
    cout << P;
  }



  f.close();
  return 0;
}
