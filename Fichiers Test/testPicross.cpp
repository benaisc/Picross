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
    P.solCasesSure(1);

    cout<<P;

    //on check si les listes sont verifiées dans mat
    P.setLignesFinies(0);
    P.setLignesFinies(1);

    //on check si le picross est fini sur toutes les listes
    cout << "isPicrossFini : " << P.isPicrossFini() << endl;

    //verification methode inverseTab
    int* T=new int [5];
    for(size_t i=0; i<5; i++)
    {
      T[i]=1;
    }
    T[4]=0;
    // afftableau(T,5);
    // cout << "inverseTab : " << endl;
    // P.inverseT(T,5);
    // afftableau(T,5);
    // delete [] T;

    Liste L;
    L.putFin(2);
    L.putFin(1);
    L.putFin(3);
    cout << "Liste L : " << L << endl;
    Liste* Linv = inverseL(L);
    cout << "inverseL : " << *Linv << endl;

    int* Tres=new int [12];
    for(size_t i=0; i<12; i++)
    {
      Tres[i]=1;
    }

    int Tg[12]={-1,1,1,0,2,-1,0,-1,3,3,3,-1};
    int Td[12]={-1,1,1,0,2,-1,0,-1,3,3,3,-1};
   
    afftableau(Tg,12);
    afftableau(Td,12);
    P.remplirCasesSureBl(Tres,Tg,Td,12,L);
    afftableau(Tres,12);
/*
    int * Test=P.getColonneMat(1);
    P.SLPG(Test,5,P.getColonnes()[1].getPremier());
    afftableau(Test,5);
*/
  }
  f.close();
  return 0;
}
