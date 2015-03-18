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
    /* On lit le fichier texte et construit le Picross */
    size_t nbl, nbc;
    f>>nbl>>nbc;
    Picross P(nbl,nbc);
    f.ignore(); //le '\n'
    P.remplirTabListe(f);

    //on rempli les lignes des cases sures
    P.solCasesSure(0);

    //subterfuge pour finir tipoisson et valider le test des methodes
    int* T=new int [5];
    for(size_t i=0; i<5; i++)
    {
      T[i]=1;
    }
    P.pushMat(0, T, 1);

    cout<<P;

    //on check si les listes sont verifiées dans mat
    P.setLignesFinies(0);
    P.setLignesFinies(1);

    //on check si le picross est fini sur toutes les listes
    cout << "isPicrossFini : " << P.isPicrossFini() << endl;

    //verification methode inverseTab
    T[4]=0;
    afftableau(T,5);
    cout << "inverseTab : " << endl;
    P.inverseTab(T,5);
    afftableau(T,5);

    Liste L;
    L.putFin(1);
    L.putFin(2);
    L.putFin(3);
    cout << L;
    cout << P.inverseListe(L);
    int * Test=P.getColonneMat(1);
    P.SLPG(Test,5,P.getColonnes()[1].getPremier());
    afftableau(Test,5);
  }
  f.close();
  return 0;
}
