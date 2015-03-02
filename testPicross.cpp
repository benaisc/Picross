#include "picross.h"
using namespace std;
void afftableau(int T[], int taille)
{
  int i;
  cout<<endl<<"T[";
  for (i=0; i<taille; i++)
    {
      cout<<T[i];
      if (i!=taille-1)
	cout<<", ";
    }
  cout<<"]"<<endl;
}
void creetableau(int T[],int taille)
{
    srand(time(NULL));
    int i=0;
    for (i=0; i<taille; i++)
        T[i]=rand()%2-1;
}
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
    
 int* T=P.getLigneMat(1);
    cout<<"Test getLigneMat(1) :";
    afftableau(T,nbc);
    cout<<"On modifie le tableau :";
    creetableau(T,nbc);
    afftableau(T,nbc);
    P.setLigneMat(1,T);
    cout<<"On copie dans la matrice et on affiche la matrice :"<<P;

    T=P.getColonneMat(1);
    cout<<"Test getColonneMat(1) :";
    afftableau(T,nbl);
    cout<<"On modifie le tableau :";
    creetableau(T,nbl);
    afftableau(T,nbl);
    P.setColonneMat(1,T);
    cout<<"On copie dans la matrice et on affiche la matrice :"<<P;
    delete[] T;
  }
 f.close();

  return 0;
}
