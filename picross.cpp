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
      if(!verif(Tab,n,i))
	{
	  poss=false;//il reste au moins une case noire entre(i et n) alors que la liste est vide
	}
      else
	{
	  poss=true;//il ne reste pas de case noire entre(i et n) alors que la liste est vide(fini)
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
      //voir Placer1bloc
      Placer1bloc(Tab,n,P->getVal(),i,poss);
      //J'ai reussi a placer mon bloc
      if(poss)
	{
  	  bool poss2=false;
	  //Je rapelle SLG avec mon tableau modifier, l'indice suivant, et la position correpodante a deux cases apres la fin de mon bloc
  	  SLG(Tab,n,P->getSuiv(),i+P->getVal()+1,poss2);
	  //La SLPG prenant comme point de depart en supposant mon i courant ne convient pas(cad: il reste au moins une case noire entre(la fin de mon dernier bloc et n) alors que la liste est vide
  	  if(!poss2)
	    {
	      if(Tab2[i]!=1)
		{
		  //Je rapelle SLG sur mon tableau sauvegarder pas celui modifier par Placer1Bloc et je retente ma chance en placant mon bloc courant un cran plus loin
		  SLG(Tab2,n,P,i+1,poss);
		}
	      else
		{
		  poss2=false;
		}
	    }
	}

      //Il n'y a pas la place directe en i pour placer mon bloc courant je tente un cran plus loin
      else{
	if(Tab[i]!=1)
	  {
	    SLG(Tab,n,P,i+1,poss);
	  }
	else
	  {
	    poss=false;
	  }
      }
    }
}
void Picross::Placer1bloc(int* Tab,size_t n,size_t val,size_t i,bool &poss)const
//voir docxygen et commentaire interne
{
  poss=true;
  if(i+val>n-1)
    {
      poss=false;
    }
  else if(Tab[i]==0)//si il y a un blanc en i
    {
      poss=false;
    }
  else if(i+val<n && Tab[i+val]==1)//si il y a un noir juste a la fin du bloc
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
	     if(i+val<n && j==i+val)
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

void Picross::SLPD(int* Tab, size_t n, Liste L)
{
  bool b=true;
  inverseTab(Tab,n);
  Liste Linv = inverseListe(L);
  SLG(Tab,n,Linv.getPremier(),0,b);
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
    size_t taille=mat.getNbc();//on traite une ligne donc on cree un tab de taille nbColonnes
    int* tab=initTab(taille);
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
    size_t taille=mat.getNbl();
    int* TG=initTab(taille);
    int nbcell=colonnes[ind].getLongueur();
    size_t cpt=0;
    size_t j=0;
    for(int i=1; i<=nbcell; i++)
    {
      taille=colonnes[ind](i).getVal();
      while(cpt<taille)
      {
        TG[j]=i;
        ++j;
        ++cpt;
      }
      ++j;
      cpt=0;
    }
    return TG;
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
    size_t taille=mat.getNbc();//on traite une ligne
    int nbcell=lignes[ind].getLongueur();
    int* tab=initTab(taille);
    size_t j=taille-1;//l'indice du tab
    size_t cpt=0;//boucle cases à noircir
    while(nbcell>0)//pour chaque cellule de la liste
    {
      taille=lignes[ind](nbcell).getVal();
      while(cpt<taille)//on part de la fin
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
    size_t taille=mat.getNbl();
    int* TD=initTab(taille);
    int nbcell=colonnes[ind].getLongueur();
    size_t j=taille-1;
    size_t cpt=0;
    while(nbcell>0)
    {
      taille=colonnes[ind](nbcell).getVal();
      while(cpt<taille)
      {
        TD[j]=nbcell;
        --j;
        ++cpt;
      }
      --j;
      --nbcell;
      cpt=0;
    }
    return TD;
  }break;
  default:
    return NULL;
    break;
  }
}
int* Picross::mergeTab(int *T1, int *T2, size_t n)
{
  int* T=initTab(n);

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
  delete [] T1;
  delete [] T2;
  return T;
}
void Picross::pushMat(size_t ind, int* T, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=mat.getNbc();
    for(size_t i=0; i<taille; i++)
    {
      if(T[i]==1)//pour n'y mettre que les cases sures
      {
        mat.getMat()[ind][i]=T[i];
      }
    }
    delete [] T;
  }break;
  case 1:
  {
    size_t taille=mat.getNbl();//nombre de colonnes
    for(size_t i=0; i<taille; i++)
    {
      if(T[i]==1)
      {
        mat.getMat()[i][ind]=1;
      }
    }
    delete [] T;
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
            pushMat(i,mergeTab(tabGauche(i,b),tabDroite(i,b),taille),b);
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
          pushMat(i,mergeTab(tabGauche(i,b),tabDroite(i,b),taille),b);
        }
      }
    }break;
    default:
    break;
  }
}


//methode permettant de remplir les cases blanches "sures" 
int* Picross::remplirCasesSure(int *Tg, int *Td, size_t n,const Liste & L)
{
  // int* T=initTab(n);
  size_t maxD=0,minG=0,minD=0,min=0,max=0;
  int* T=new int[n];
  int* Ten=new int[n];
 for(size_t i=0; i<n; i++)
    {
      T[i]=0;
    }
  for(size_t i=0; i<n; i++)
    {
      Ten[i]=-1;
    }
  for(size_t j=1; j<L.getLongueur()+1 ;j++)
    {//j=numerodubloc 1.2.3...
     while( (size_t)Tg[minG]!=j)
	{
	  minG++;
	}
      while(  (size_t)Td[minD]!=j)
	{
	  minD++;
	}
      maxD=minD;
      while(  (size_t)Td[maxD]==j)
	{
	  maxD++;
	}
      min=minG;
      max=maxD-1;
 cout<<"min :"<<min<<endl<<"max :"<<max<<endl<<"Ten:";
      for(size_t i=min; i<=max; i++)
	{ 
	  Ten[i]=(int)j;
	}
afftableau(Ten,5);
    } 
 afftableau(T,5);
      for(size_t i=0; i<n; i++)
	{ 
	  if (Ten[i]==-1)
	 T[i]=Ten[i];
	}
  return T;
}


//Amelioration possible : garder en memoire la somme des cellules d'une liste
bool Picross::isLigneFinie(size_t ind, bool b) const//0 ligne, 1 colonne comme dhab
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
void Picross::setLignesFinies(bool b) const
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
bool Picross::isPicrossFini() const
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
  size_t temp;
  if(taille%2==0){
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

Liste Picross::inverseListe(const Liste& L)
{
  Liste Linv = L;
  size_t temp, taille;
  taille = L.getLongueur();
  if (taille % 2 == 0){
    for (size_t i = 1; i<= (taille/2); i++){
      temp=Linv(i).getVal();
      Linv(i).setVal(Linv(taille-i+1).getVal());
      Linv(taille-i+1).setVal(temp);
    }
  }
  else {
    for (size_t i = 1; i<=(taille-1)/2; i++){
      temp=Linv(i).getVal();
      Linv(i).setVal(Linv(taille-i+1).getVal());
      Linv(taille-i+1).setVal(temp);
    }
  }
  return Linv;
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
std::ostream &operator<<(std::ostream& os, const Picross &P)
{
  P.afficheP(os);
  return os;
}
void afftableau(const int T[], int taille)
{
  std::cout<<"T[";
  for(int i=0; i<taille; i++)
  {
    std::cout<<T[i];
    if(i!=taille-1){std::cout<<", ";}
  }
  std::cout<<"]"<<std::endl;
}
void creetableau(int T[],int taille)
{
  srand(time(NULL));
  for(int i=0; i<taille; i++){T[i]=rand()%2-1;}
}
int* initTab(int taille)
{
  int* init=new int [taille];
  for(int i=0; i<taille; i++){init[i]=0;}
  return init;
}
Liste inverseL(const Liste& Lin)
{
  Liste Lout;
  size_t taille=Lin.getLongueur();
  size_t temp=taille;
  for(size_t i = 1; i<=taille; i++)
  {
    Lout.putFin(Lin(temp).getVal());
    --temp;
  }
  return Lout;
}
