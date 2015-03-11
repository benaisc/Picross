#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  ifstream f;
  //f.open(argv[1]);
  f.open("Fichiers\ Test/tipoisson.txt");

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

    P.solCasesSure(0);//on rempli les lignes des cases sures
    cout<<P;
    
    P.SLPG(P.getColonneMat(1),P.getMat().getNbl(),P.getColonnes()[1].getPremier());


  }
 f.close();

  return 0;
}
