#include "picross.h"
using namespace std;

//constructeur
Picross::Picross(size_t nbl, size_t nbc):mat(nbl,nbc),lignes(nbl),colonnes(nbc)
{}
void Picross::remplirTabListe(std::ifstream& f)
{
  size_t val,i=0;
  while(i<lignes.getTaille())
  {
    while(f.peek()!='\n')
    {
      f>>val; //je lit l'indice
      lignes[i].putFin(val); //je le rajoute a la liste
    }
    f.ignore(); //le '\n'
    i++;  //on change de ligne
  }
  i=0;
  while(i<colonnes.getTaille())
  {
    while(f.peek()!='\n')
    {
      f>>val;
      colonnes[i].putFin(val);
    }
    f.ignore();
    i++;
  }
}
//accesseur
TabListe Picross::getLignes() const
{
  return lignes;
}
TabListe Picross::getColonnes() const
{
  return colonnes;
}
Matrice Picross::getMat() const
{
  return mat;
}
int* Picross::getLigneMat(size_t ind)const
{
  size_t taille=mat.getNbc();
  int* tab=new int[taille];
  for(size_t i =0; i<mat.getNbc();i++)
    {
      tab[i]=mat.getMat()[ind][i];
    }
  return tab;
}
int* Picross::getColonneMat(size_t ind)const
{
  size_t taille=mat.getNbl();
  int* tab=new int[taille];
  for(size_t i =0; i<mat.getNbl();i++)
    {
      tab[i]=mat.getMat()[i][ind];
    }
  return tab;
}
void Picross::setLigneMat(size_t ind, int* Tab)
{
  for(size_t i =0; i<mat.getNbl();i++)
    {
      mat.getMat()[ind][i]=Tab[i];
    }
}
void Picross::setColonneMat(size_t ind, int* Tab)
{
  for(size_t i =0; i<mat.getNbc();i++)
    {
      mat.getMat()[i][ind]=Tab[i];
    }
}
void Picross::SLG(int* Tab,size_t n,Cell* P,size_t i,bool &poss)const
{
  if(P==NULL)
  {
    cout<<"je passe par verif tient il est "<<boolalpha<<verif(Tab,n,i)<<noboolalpha<<endl;
    if(!verif(Tab,n,i))
	  {
	     poss=false;
	  }
    else
	  {
	     poss=true;
	     afftableau(Tab,5);
	  }
  }
  else
  {
    int* Tab2=new int [n];
    for(size_t j=0;j<n;j++)
  	{
  	  Tab2[j]=Tab[j];
  	}
    int u;
    cout<<"on apelle : Placer1bloc(Tab,"<<n<<","<<P->getVal()<<","<<i<<","<<poss<<")"<<endl;
    cin>>u;
    Placer1bloc(Tab,n,P->getVal(),i,poss);
    afftableau(Tab,5);
    cout<<" Placer1bloc : Il renvoie poss a "<<boolalpha<<poss<<noboolalpha<<endl;
    if(poss)
	  {
  	  bool poss2=false;
  	  cout<<"on apelle : SLG(Tab,"<<n<<","<<P->getSuiv()<<","<<i+P->getVal()+1<<","<<poss2<<")"<<endl;
  	  cin>>u;
  	  SLG(Tab,n,P->getSuiv(),i+P->getVal()+1,poss2);
  	  cout<<"SLG : Il renvoie poss a "<<boolalpha<<poss2<<noboolalpha<<endl;
  	  if(!poss2)
  	  {
  	    cout<<"on apelle: SLG(Tab2,"<<n<<","<<P<<","<<i+1<<","<<poss<<")"<<endl;
  	    cin>>u;
  	    SLG(Tab2,n,P,i+1,poss);
  	    cout<<"SLG : Il renvoie poss a "<<boolalpha<<poss<<noboolalpha<<endl;
  	  }
    }
    else
	  {
  	  cout<<"on apelle: SLG(Tab,"<<n<<","<<P<<","<<i+1<<","<<poss<<")"<<endl;
  	  cin>>u;
  	  SLG(Tab,n,P,i+1,poss);
  	  cout<<"SLG : Il renvoie poss a "<<boolalpha<<poss<<noboolalpha<<endl;
    }
  }
}
void Picross::Placer1bloc(int* Tab,size_t n,size_t val,size_t i,bool &poss)const
{
  std::cout<<"n : "<<n<<" val : "<<val<<" i : "<<i<<std::endl;
  poss=true;
  if(i+val>n-1)
    {
      poss=false;
    }
  else if(Tab[i]==0)//si il y a un blanc en i
    {
      poss=false;
    }
  else if(Tab[i+val]==1)//si il y a un noir juste a la fin du bloc
    {
      poss=false;
    }
  else
  {
    for(size_t j=i;j<i+val;j++)//si il y a un blanc entre i et val+i
	  {
	     if(Tab[j]==-1)
	     {
	        poss=false;
	     }
	  }
  }
  if(poss)
  {
    for(size_t j=i;j<=i+val;j++)
    {
	     if(j==i+val)
	     {
	        Tab[j]=-1;
	     }
	     else
	     {
	        Tab[j]=1;
	     }
    }
  }
}
void Picross::SLPG(int* Tab,size_t n,Cell* L)const
{
  bool b=true;
  SLG(Tab,n,L,0,b);
}
bool Picross::verif(int *Tab,size_t n,size_t j)const
{
  for(size_t i=j+1;i<n;i++)
    {
      if(Tab[i]==1)
	{
	  return false;
	}
    }
      return true;
}

//Methode
int* Picross::tabGauche(size_t ind, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=colonnes.getTaille();//on traite une ligne donc on cree un tab de taille nbColonnes
    int* tab=new int [taille];
    int nbcell=lignes[ind].getLongueur();//nbcell dans la liste
    size_t j=0;//l'indice du tab
    size_t cpt=0;//boucle cases à noircir
    for(int i=1; i<=nbcell; i++)//pour chaque cellule de la liste
    {
      taille=lignes[ind](i).getVal();
      while(cpt<taille)//on remplit getVal cases
      {
        tab[j]=i;//avec le numero de la cell dans la liste
        ++j;
        ++cpt;
      }
      ++j;//la case blanche
      cpt=0;//on remet a 0 le nombre de cases à remplir
    }
    return tab;
  }break;
  case 1:
  {
    size_t taille=lignes.getTaille();
    int* tab=new int [taille];
    int nbcell=colonnes[ind].getLongueur();
    size_t cpt=0;
    size_t j=0;
    for(int i=1; i<=nbcell; i++)
    {
      while(cpt<colonnes[ind](i).getVal())
      {
        tab[j]=i;
        ++j;
        ++cpt;
      }
      ++j;
      cpt=0;
    }
    return tab;
  }break;
  default:
    return NULL;
    break;
  }
}
int* Picross::tabDroite(size_t ind, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=colonnes.getTaille();//on traite une ligne
    int nbcell=lignes[ind].getLongueur();
    int* tab=new int [taille];
    size_t j=taille-1;//l'indice du tab
    size_t cpt=0;//boucle cases à noircir
    while(nbcell>0)//pour chaque cellule de la liste
    {
      while(cpt<lignes[ind](nbcell).getVal())//on part de la fin
      {
        tab[j]=nbcell;
        --j;
        ++cpt;
      }
      --j;//la case blanche
      --nbcell;
      cpt=0;
    }
    return tab;
  }break;
  case 1:
  {
    size_t taille=lignes.getTaille();
    int* tab=new int [taille];
    int nbcell=colonnes[ind].getLongueur();
    size_t j=taille;
    size_t cpt=0;
    while(nbcell>0)
    {
      while(cpt<colonnes[ind](nbcell).getVal())
      {
        tab[j]=nbcell;
        --j;
        ++cpt;
      }
      --j;
      --nbcell;
      cpt=0;
    }
    return tab;
  }break;
  default:
    return NULL;
    break;
  }
}
int* Picross::mergeTab(int *T1, int *T2, size_t n)
{
  int* T=new int [n];

  for(size_t i=0; i<n; i++)
  {
    /* On à mis l'indice de la cellule dans la liste en valeur dans les T
    On passe sur les 0 qui s'entrecroisent,
    on ne peut les determiner par cette methode que pour les lignes pleines */
    if(T1[i]!=0 && T1[i]==T2[i])
    {
      T[i]=1;
    }
  }
  return T;
}
void Picross::pushMat(size_t ind, int* T, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=colonnes.getTaille();//nombre de lignes
    for(size_t i=0; i<taille; i++)
    {
      mat.getMat()[ind][i]=T[i];
    }
  }break;
  case 1:
  {
    size_t taille=lignes.getTaille();//nombre de colonnes
    for(size_t i=0; i<taille; i++)
    {
      mat.getMat()[i][ind]=T[i];
    }
  }break;
  default:
    break;
  }
}
//methode permettant de remplir les cases "sures"
//rempli la matrice de la fusion de solGauche et solDroite
//a utiliser sur matrice vide
void Picross::solCasesSure(bool b)
{
  switch(b)
  {
    case 0://ligne
    {
      size_t taille=mat.getNbc();
      size_t nbl=lignes.getTaille();
        for(size_t i=0; i<nbl; i++)//pour toutes les lignes
        {
          if(lignes[i].somElem()>=(taille/2)+1)//si le bloc est valide
          {
            int* T=mergeTab(tabGauche(i,b),tabDroite(i,b),taille);
            pushMat(i,T,b);
          }
        }
    }break;
    case 1://colonne
    {
      size_t taille=mat.getNbl();
      size_t nbc=colonnes.getTaille();
      for(size_t i=0; i<nbc; i++)
      {
        if(colonnes[i].somElem()>=(taille/2)+1)
        {
          int* T=mergeTab(tabGauche(i,b),tabDroite(i,b),taille);
          pushMat(i,T,b);
        }
      }
    }break;
    default:
    break;
  }
}

void Picross::afficheP(std::ostream &os) const
{
  os<<"Lignes : "<<std::endl;
  lignes.afficheT(os);
  os<<"Colonnes : "<<std::endl;
  colonnes.afficheT(os);
  os<<"Matrice : "<<std::endl;
  mat.afficheM(os);
}

//operateur d'affichage
std::ostream &operator<<(std::ostream& os, Picross &P)
{
  P.afficheP(os);
  return os;
}
