#include "fonction.h"
using namespace std;

Picross lecture(ifstream& f)
{
  size_t nbl;
  size_t nbc;
  f.clear();//remet les flags a default
  f.seekg(0,ios::beg);//se met debut du fichier
  f>>nbl>>nbc;//on lit la premiere ligne

  char virg;
  size_t valindice,i=0;
  Cell indice;
  int position,test;

  f.get(virg);
  if(virg!='\n')
    {
    cerr<<"syntax error in file(l1)"<<endl;
    }
  cout<<"nbl= "<<nbl<<" nbc= "<<nbc<<endl;
  Matrice matrice= Matrice(nbl,nbc);
  TabListe ligne= TabListe(nbl);
  TabListe colonne=TabListe(nbc);
cout<<"test1"<<endl;
cout<<"virg:"<<virg<<endl;
  while(virg!=';')
    {
      virg='?';
      while(virg!=',')
	{
	  position=f.tellg();//je memorise la position
	  f.get(virg);//je lit le caractere suivant
	  cout<<"virg:"<<virg<<endl;
	  cin>>test;
	  if(virg!=','&& virg!=';')
	    {
	      f.seekg(position,ios::beg);// je me remet a ma position enregistre
	      f>>valindice;//je lit l'indice
	      f.ignore(1);
	      cout<<"valindice:"<<valindice<<endl;
	      cin>>test;
	      indice=Cell(valindice);//je le tranforme en cell
	      colonne[i].ajoutFin(indice);//je le rajoute a la liste
	    }
	}

      if(virg!=';')
	{
	  i++;//on change de colonne du tableau car on a trouver un virgule
	  cout<<i<<endl;
	}   
    }
   i=0;
cout<<"test3"<<endl;
 f.get(virg);
  if(virg!='\n')
    {
    cerr<<"syntax error in file(l2)"<<endl;
    }
  //pareil pour ligne
 while(virg!=';')//
    {
      while(virg!=',')
	{
	  position=f.tellg();//je memorise la position
	  f.get(virg);//je lit le caractere suivant
	  if(virg!=','||virg!=';')
	    {
	      f.seekg(position,ios::beg);// je me remet a ma position enregistre
	      cin>>valindice;//je lit l'indice
	      indice=Cell(valindice);//je le tranforme en cell
	      ligne[i].ajoutFin(indice);//je le rajoute a la liste
	    }
	}
      if(virg!=';')
	{
	  i++;//on change de colonne du tableau car on a trouver un virgule
	}   
    }
 return Picross(matrice,ligne,colonne);

}
