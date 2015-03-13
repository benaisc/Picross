#include "picross.h"
using namespace std;

void Picross::solutionPaD(int* tab, size_t taille, int indice, bool lig){
  size_t l=0;
  size_t k=lignes[indice].getLongueur();
  // bool place=false;
  if(lig)
  {
    if(lignes[indice].somElem()<=taille)
    {
      for(size_t i=0;i<k;i++)
      {
        /*
        while(!place)
      {
      while(m<=lignes[indice](k-i).getVal()+1)
    {
    if(tab[taille-1-l-m]==0)
  {
  m++;
}
else
{
m=0;
l=l+m+1;
}
}
} */
for(size_t j=0;j<lignes[indice](k-i).getVal();j++)
{
  tab[taille-l-1]=k;
  l++;
}
tab[taille-l-1]=0;
l++;
k--;
}
}
}
}

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
