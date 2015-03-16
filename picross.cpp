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
//voir docxygen et commentaire interne
{
  if(P==NULL)
  {
    cout<<"je passe par verif tient il est "<<boolalpha<<verif(Tab,n,i)<<noboolalpha<<endl;
    if(!verif(Tab,n,i))
	  {
	    poss=false;//il reste au moins une case noire entre(i et n) alors que la liste est vide
	  }
    else
	  {
	     poss=true;//il ne reste pas de case noire entre(i et n) alors que la liste est vide(fini)
	     afftableau(Tab,5);
	  }
  }
  else
  {
   //je fais une copie de Tab
    int* Tab2=new int [n];
    for(size_t j=0;j<n;j++)
  	{
  	  Tab2[j]=Tab[j];
  	}
 

    int u;
    cout<<"on apelle : Placer1bloc(Tab,"<<n<<","<<P->getVal()<<","<<i<<","<<poss<<")"<<endl;
    cin>>u;
    //voir Placer1bloc
    Placer1bloc(Tab,n,P->getVal(),i,poss);
    afftableau(Tab,5);
    cout<<" Placer1bloc : Il renvoie poss a "<<boolalpha<<poss<<noboolalpha<<endl;

    //J'ai reussi a placer mon bloc
    if(poss)
	  {
  	  bool poss2=false;
  	  cout<<"on apelle : SLG(Tab,"<<n<<","<<P->getSuiv()<<","<<i+P->getVal()+1<<","<<poss2<<")"<<endl;
  	  cin>>u;
	  //Je rapelle SLG avec mon tableau modifier, l'indice suivant, et la position correpodante a deux cases apres la fin de mon bloc
  	  SLG(Tab,n,P->getSuiv(),i+P->getVal()+1,poss2);
  	  cout<<"SLG : Il renvoie poss a "<<boolalpha<<poss2<<noboolalpha<<endl;

	  //La SLPG prenant comme point de depart en supposant mon i courant ne convient pas(cad: il reste au moins une case noire entre(la fin de mon dernier bloc et n) alors que la liste est vide
  	  if(!poss2)
  	  {
  	    cout<<"on apelle: SLG(Tab2,"<<n<<","<<P<<","<<i+1<<","<<poss<<")"<<endl;
  	    cin>>u;
	    //Je rapelle SLG sur mon tableau sauvegarder pas celui modifier par Placer1Bloc et je retente ma chance en placant mon bloc courant un cran plus loin
  	    SLG(Tab2,n,P,i+1,poss);
  	    cout<<"SLG : Il renvoie poss a "<<boolalpha<<poss<<noboolalpha<<endl;
  	  }
    }

    //Il n'y a pas la place directe en i pour placer mon bloc courant je tente un cran plus loin
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
//voir docxygen et commentaire interne
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

  //il n'y a pas de contrindication je peux placer mon bloc
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
void Picross::SLPG(int* Tab,size_t n,Cell* L)const//voir docxygen
{
  bool b=true;
  SLG(Tab,n,L,0,b);
}
bool Picross::verif(int *Tab,size_t n,size_t j)const//voir docxygen
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
//On donne a manger l'indice d'une ligne ou colonne de TabListe
//Amelioration possible : garder en memoire la somme des cellules d'une liste
bool Picross::isLigneFinie(size_t ind, bool b)//0 ligne, 1 colonne comme dhab
{
  switch(b)
  {
    case 0://ligne
    {
      size_t nbcell=lignes[ind].getLongueur();
      size_t i=1;//l'indice de la cellule ds la liste
      size_t cpt=0;
      while(i<=nbcell)//on compte le nombre de blocs noirs à placer
      {
        cpt+=lignes[ind](i).getVal();
        ++i;
      }
      size_t taille=mat.getNbc();//la longueur d'une ligne de matrice
      size_t nbNoires=0;
      for(i=0; i<taille; i++)//on balaie la ligne
      {
        if(mat.getMat()[ind][i]==1)//si le bloc est noir
        {
          ++nbNoires;
        }
      }
      return cpt==nbNoires;
    }break;
    case 1://colonne
    {
      size_t nbcell=colonnes[ind].getLongueur();
      size_t i=1;
      size_t cpt=0;
      while(i<=nbcell)
      {
        cpt+=colonnes[ind](i).getVal();
        ++i;
      }
      size_t taille=mat.getNbl();
      size_t nbNoires=0;
      for(i=0; i<taille; i++)
      {
        if(mat.getMat()[i][ind]==1)
        {
          ++nbNoires;
        }
      }
      return cpt==nbNoires;
    }break;
    default:
      return 0;
      break;
  }
}
//on donne a manger un booleen pour balayer lignes ou colonnes
void Picross::setLignesFinies(bool b)
{
  switch(b)
  {
    case 0://ligne
    {
      size_t taille=lignes.getTaille();//nombre de lignes
      for(size_t i=0; i<taille; i++)
      {
        //si la ligne n'est pas a true alors qu'elle est terminee
        if(!lignes[i].getFini() && isLigneFinie(i,0))
        {
          lignes[i].setFini(true);//on met le booleen a vrai
        }
      }
    }break;
    case 1:
    {
      size_t taille=colonnes.getTaille();
      for(size_t i=0; i<taille; i++)
      {
        if(!colonnes[i].getFini() && isLigneFinie(i,1))
        {
          colonnes[i].setFini(true);
        }
      }
    }break;
    default:
    break;
  }
}
//methode indiquant si le picross est correctement rempli
bool Picross::isPicrossFini()
{
  size_t taille=lignes.getTaille();
  for(size_t i=0; i<taille; i++)
  {
    if(!lignes[i].getFini())
    {
      return false;
    }
  }
  taille=colonnes.getTaille();
  for(size_t i=0; i<taille; i++)
  {
    if(!colonnes[i].getFini())
    {
      return false;
    }
  }
  return true;
}


void Picross::inverseTab(int *Tab, size_t taille){
  size_t  temp;  
  if(taille%2 ==0){
    for(size_t i=0;i<taille/2;i++){
      temp=Tab[taille-1-i];
      Tab[taille-1-i]=Tab[i];
      Tab[i]=temp;
    }
  }else   {
    for(size_t i=0;i<(taille-1)/2;i++){
      temp=Tab[taille-1-i];
      Tab[taille-1-i]=Tab[i];
      Tab[i]=temp;
    }
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
