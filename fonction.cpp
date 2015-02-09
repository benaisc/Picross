#include "fonction.h"
using namespace std;
char carsuiv(ifstream &f)
{
  int position=f.tellg();//je memorise la position
  char retour;
  f.get(retour);//je lit le caractere suivant
  f.seekg(position,ios::beg);// je me remet a ma position enregistre
  f.clear();//remet les flags a default
  return retour;
}
void remplirTabListe(ifstream& f, TabListe& colonne)
{
  size_t valindice,i=0,j=0;
  Cell indice;
  int test;
 while(carsuiv(f)!=';')
   {
  
     while(carsuiv(f)!=',' && carsuiv(f)!=';')
       {
	 
	 f>>valindice;//je lit l'indice
	 f.ignore();
	 indice=Cell(valindice);//je le tranforme en cell
	 cout<<"indice:"<<indice.getVal()<<" suivindice:"<<indice.getSuiv()<<endl;
	 colonne[i].ajoutFin(indice);//je le rajoute a la liste
	 // cout<<"ajout a la liste reussit"<<endl;
	 cout<<"colonne["<<i<<"]("<<j<<") :"<<colonne[i](j).getVal()<<endl;
	 j++;
       }
     i++;//on change de colonne du tableau car on a trouver une virgule
     cout<<"i:"<<i<<endl;
     if(carsuiv(f)!=';')
       {
     f.ignore();
       }
     j=0;
   }
}

Picross lecture(ifstream& f)
{
  size_t nbl;
  size_t nbc;
  f.clear();//remet les flags a default
  f.seekg(0,ios::beg);//se met debut du fichier
  f>>nbl>>nbc;//on lit la premiere ligne

  char suiv;
  f.get(suiv);
  if(suiv!='\n')
    {
      cerr<<"syntax error in file(l1)"<<endl;
    }

  cout<<"nbl= "<<nbl<<" nbc= "<<nbc<<endl;
  Matrice matrice= Matrice(nbl,nbc);
  TabListe ligne= TabListe(nbl);
  TabListe colonne=TabListe(nbc);
  cout<<"suiv:"<<carsuiv(f)<<endl;
  cout<<"-----------------Maintenant remplisons Colonne-----------------------------"<<endl;
  remplirTabListe(f,colonne);
  cout<<"----------------Colonne remplie avec succes-----------------------------"<<endl;
  f.get(suiv);
  f.get(suiv);
  if(suiv!='\n')
    {
      cerr<<"syntax error in file(l1)"<<endl;
    }
  cout<<"-----------------Maintenant remplisons ligne-----------------------------"<<endl;
  remplirTabListe(f,ligne);
  cout<<"----------------ligne remplie avec succes-----------------------------"<<endl;
  cout<<"test";

  return Picross(matrice,ligne,colonne);
}
