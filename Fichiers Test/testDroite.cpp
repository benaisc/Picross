#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  int tab[5]={0,0,0,0,0};
//for(size_t i=0;i<5;i++ ){tab[i]=0;} 

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
 cout<<"Test methode solution plus a droite "<<endl;
 cout << P<<endl;
 size_t indice=0;
 while(indice<5){
P.solutionPaD(tab, 5, indice,true);
 cout<<"tab["<<indice<<"] :   ";	
for(size_t i=0;i<5;i++)
{
cout<<tab[i]<<"   ";
} 
cout<<endl;
 indice++;
 }

}
f.close();
return 0;
}
