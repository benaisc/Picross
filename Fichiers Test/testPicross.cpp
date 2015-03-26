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
    afftableau(T,5);
    cout << "inverseTab : " << endl;
    P.inverseTab(T,5);
    afftableau(T,5);
    delete [] T;

    Liste L;
    L.putFin(1);
    L.putFin(2);
    L.putFin(2);
    // L.putFin(3);
    cout << "Liste L : " << L << endl;
    Liste* Linv = inverseL(L);
    cout << "inverseL : " << endl;
    // affliste(Linv);  provoque erreur de segmentation 
    
    int Tg[10]={1,0,2,2,0,3,3,0,0,0};
    int Td[10]={1,0,0,0,0,2,2,0,3,3};

    afftableau(Tg,10);
    afftableau(Td,10);
    afftableau(P.remplirCasesSure(Tg,Td,10,L),10);
/*
    int * Test=P.getColonneMat(1);
    P.SLPG(Test,5,P.getColonnes()[1].getPremier());
    afftableau(Test,5);
*/
  }
  f.close();
  return 0;
}
