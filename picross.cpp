#include "picross.h"
using namespace std;
//constructeur
Picross::Picross(size_t nbl, size_t nbc):mat(nbl,nbc),lignes(nbl),colonnes(nbc),colModif(),ligModif()
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

Liste Picross::getColModif()const
{
 return colModif;
}

Liste Picross::getLigModif()const
{
 return ligModif;
}

int* Picross::getLigneMat(size_t ind)const
{
  size_t taille=mat.getNbc();
  int* tab=new int[taille];
  for(size_t i =0; i<taille;i++)
    {
      tab[i]=mat.getMat()[ind][i];
    }
  return tab;
}
int* Picross::getColonneMat(size_t ind)const
{
  size_t taille=mat.getNbl();
  int* tab=new int[taille];
  for(size_t i =0; i<taille;i++)
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

void Picross::SLPD(int* T, size_t n, Liste &L)
{
  bool B=false;
  inverseT(T,n);
  Liste* Linv;
  Linv = inverseL(L);
  SLG(T,n,Linv->getPremier(),0,B);
  inverseT(T,n);
  delete Linv;
}
void Picross::SLPG(int* Tab, size_t n, Liste &L)
{
  bool Res=false;
  SLG(Tab,n,L.getPremier(),0,Res);
}
void Picross::SLG(int* Tab, size_t n, Cell* P, size_t i, bool &poss)
{
  if(P==NULL )
  {
    poss=Verification(Tab,i,n);
    if(poss)
      {
    for(size_t j=0;j<n;j++) { if(Tab[j]==0) {Tab[j]=-1; } }
      }
  }
  else
  {
    int* Tab2=new int [n];
    for(size_t j=0;j<n;j++)
    {
      Tab2[j]=Tab[j];
    }
    PlacerBloc(Tab,n,P->getVal(),i,poss);
    if(poss)
    {
      SLG(Tab,n,P->getSuiv(),i+P->getVal()+1,poss);
      if(!poss)
      {
        for(size_t j=0;j<n;j++)
        {
          Tab[j]=Tab2[j];
        }
	if (Tab[i]==1){poss =false;}
        else {SLG(Tab,n,P,i+1,poss);}
      }
    }
    else
    {
      if (Tab[i]==1){poss =false;}
      else {SLG(Tab,n,P,i+1,poss);}
    }
    delete [] Tab2;
  }
}
void Picross::PlacerBloc(int* Tab,size_t n,size_t val,size_t i,bool &poss)
{
  poss=true;
  if(i+val>n)
  {
    poss=false;
  }
  else
  {
    if(i+val<n && Tab[i+val]==1)
    {
      poss=false;
    }
    else
    {
      for(size_t j=i; j<i+val; j++)
      {
        if(Tab[j]==-1)
        {
          poss=false;
        }
      }
    }
  }
  if(poss)
  {
    for(size_t j=i; j<i+val; j++)
    {
      Tab[j]=1;
    }
  }
}
bool Picross::Verification(int *T, size_t ind, size_t n)
{
  for(size_t i=ind;i<n;i++)
  {
    if(T[i]==1)
    {
      return false;
    }
  }
  return true;
}

void Picross::Numeroter(int *T, size_t n)
{
  int cpt=1;
  for(size_t i=0; i<n; i++)
  {
    if(T[i]==1)
    {
      while(i<n && T[i]==1)
      {
        T[i]=cpt;
        ++i;
      }
      ++cpt;
    }
  }
}

void Picross::Fusion(int* Res, int *T1, int *T2, size_t n)
{
  for(size_t i=0; i<n; i++)
  {
    if(T1[i]==T2[i] && T1[i]>0)
    {
      Res[i]=T2[i];
    }
  }
  for(size_t i=0; i<n; i++)
  {
    if(Res[i]>1)
    {
      Res[i]=1;
    }
  }
}

void Picross::Push(int* T, size_t ind, bool b)
{
  switch(b)
  {
    case 0:
    {
      size_t taille=mat.getNbc();
      for(size_t i=0; i<taille; i++)
      {
        mat.getMat()[ind][i]=T[i];
      }
    }break;
    case 1:
    {
      size_t taille=mat.getNbl();
      for(size_t i=0; i<taille; i++)
      {
        mat.getMat()[i][ind]=T[i];
      }
    }break;
    default:
    break;
  }
}
void Picross::TINY_SOL_iter(size_t nbl, size_t nbc)
{
  size_t ind=0;
  while(ind<nbl)
  {
    if(lignes[ind].somElem()>nbc/2)
    {
      solLignes(nbc,ind);
    }
    ++ind;
  }
  ind=0;
  while(ind<nbc)
  {
    if(colonnes[ind].somElem()>nbl/2)
    {
      solColonnes(nbl,ind);
    }
    ++ind;
  }
  setLCFini();
}
void Picross::TINY_SOL(size_t nbl, size_t nbc, size_t ind)
{
  if(ind<nbl||ind<nbc)
  {
    if(ind<nbl && lignes[ind].somElem()>nbc/2)
    {
      solLignes(nbc,ind);
    }
    if(ind<nbc && colonnes[ind].somElem()>nbl/2)
    {
      solColonnes(nbl,ind);
    }
    TINY_SOL(nbl,nbc,ind+1);
  }
  else
  {
    setLCFini();
  }
}
void Picross::FAT_SOL(size_t nbIndLig, size_t nbl, size_t nbc)
{
  std::cout << "FAT_SOL : " << nbIndLig << std::endl;
  if(nbIndLig>0)
  {
    FAT_LIG(nbc);
    FAT_COL(nbl);
    FAT_SOL(ligModif.getLongueur(),nbl,nbc);
  }
  else
  {
    setLCFini();
  }
}

void Picross::FAT_LIG(size_t taille)
{
  std::cout << "FAT_LIG : " << std::endl;
  if(ligModif.getLongueur()>0)
  {
    size_t indice=this->ligModif.cutHd();
    std::cout << "on as cut l'indice : " << indice << std::endl;
    solLignes(taille,indice);
    std::cout << mat << std::endl;
    FAT_LIG(taille);
  }
}

void Picross::FAT_COL(size_t taille)
{
  std::cout << "FAT_COL : " << std::endl;
  if(colModif.getLongueur()>0)
  {
    size_t indice=this->colModif.cutHd();
    std::cout << "on as cut l'indice : " << indice << std::endl;
    solColonnes(taille,indice);
    std::cout << mat << std::endl;
    FAT_COL(taille);
  }
}

void Picross::solLignes(size_t taille, size_t ind)
{
  int* TG=new int[taille];
  int* TD=new int[taille];
  int* SAVE=new int[taille];
  for(size_t i =0; i<taille;i++)
  {
    TG[i]=TD[i]=SAVE[i]=mat.getValue(ind,i);
  }
  SLPG(TG,taille,lignes[ind]);
  SLPD(TD,taille,lignes[ind]);
  Numeroter(TG,taille);
  Numeroter(TD,taille);
  int* Merge=initTab(taille);
  //remplirCasesSureBl(Merge,TG, TD, taille,lignes[ind]);
  Fusion(Merge,TG,TD,taille);
  //CasesBlanches(Merge,taille,lignes[ind]);
  amodif(true, SAVE, Merge,taille);
  Push(Merge,ind,0);
  delete [] TG;
  delete [] TD;
  delete [] SAVE;
  delete [] Merge;
}
void Picross::solColonnes(size_t taille, size_t ind)
{
  int* TG=new int[taille];
  int* TD=new int[taille];
  int* SAVE=new int[taille];
  for(size_t i =0; i<taille;i++)
  {
    TG[i]=TD[i]=SAVE[i]=mat.getValue(i,ind);
  }
  SLPG(TG,taille,colonnes[ind]);
  SLPD(TD,taille,colonnes[ind]);
  Numeroter(TG,taille);
  Numeroter(TD,taille);
  int* Merge=initTab(taille);
  //remplirCasesSureBl(Merge,TG, TD, taille,colonnes[ind]);
  Fusion(Merge,TG,TD,taille);
  //CasesBlanches(Merge,taille,colonnes[ind]);
  amodif(false, SAVE,Merge,taille);
  Push(Merge,ind,1);
  delete [] TG;
  delete [] TD;
  delete [] SAVE;
  delete [] Merge;
}

//methode permettant de remplir les cases blanches "sures"
void Picross::remplirCasesSureBl(int* Res,int *Tg, int *Td,size_t n, Liste & L)
 {
   size_t maxD=0,minG=0,minD=0,min=0,max=0;
   int* Te=new int[n];
     for(size_t i=0; i<n; i++)
     {
       Te[i]=-1;
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
       while(maxD<n && (size_t)Td[maxD]==j)
	 {
	   maxD++;
	 }
       min=minG;
       max=maxD-1;
       for(size_t i=min; i<=max; i++)
	 {
	   Te[i]=(int)j;
	 }
     }
   for(size_t i=0; i<n; i++)
     {
       if (Te[i]==-1)
	  Res[i]=Te[i];
         }
         delete [] Te;
  }

void Picross::CasesBlanches(int* T, size_t n, Liste &L)
{
  size_t cpt=1;//l'indice du bloc
  size_t nbNoires=0;//le nombre de cases
  for(size_t i=0; i<n; i++)//on balaie la ligne
  {
    if(T[i]==1)//si on tombe sur un noir
    {
      ++nbNoires;
      ++i;
      while(i<n && T[i]==1)//on le(s) comptes
      {
        ++nbNoires;
        ++i;
      }
      if(L(cpt)->getVal()==nbNoires)//si le compte est bon pour le bloc
      {
        if(i<n)//on place le -1 après
        {
          T[i]=-1;
        }
        if(i-nbNoires-1>=0)//on place le -1 avant
        {
          T[i-nbNoires-1]=-1;
        }
      }
      nbNoires=0;
      ++cpt;
    }
  }
}
bool Picross::VerifMatrice(size_t ind, bool B) const
{
  if(!B)
  {
    size_t nbcell=lignes[ind].getLongueur();
    size_t cpt=lignes[ind].somCell();
    size_t nbNoires=0;
    size_t taille=mat.getNbc();
    for(size_t i=0; i<taille; i++)//on balaie la ligne
    {
      if(mat.getValue(ind,i)==1)//si on tombe sur un noir
      {
        ++nbNoires;
        ++i;
        while(i<taille && mat.getValue(ind,i)==1)//on le balaie
        {
          ++nbNoires;
          ++i;
        }
        --nbcell;//on decompte le nombre de cellules
      }
    }
    return ((cpt==nbNoires)&&(nbcell==0));
  }
  else
  {
    size_t nbcell=colonnes[ind].getLongueur();
    size_t cpt=colonnes[ind].somCell();
    size_t nbNoires=0;
    size_t taille=mat.getNbl();
    for(size_t i=0; i<taille; i++)//on balaie la ligne
    {
      if(mat.getValue(i,ind)==1)//si on tombe sur un noir
      {
        ++nbNoires;
        ++i;
        while(i<taille && mat.getValue(i,ind)==1)//on le balaie
        {
          ++nbNoires;
          ++i;
        }
        --nbcell;//on decompte le nombre de cellules
      }
    }
    return ((cpt==nbNoires)&&(nbcell==0));
  }
}
void Picross::setLCFini()
{
  size_t taille=lignes.getTaille();
  for(size_t i=0; i<taille; i++)
  {
    if(!lignes[i].getFini() && VerifMatrice(i,0))
    {
      lignes[i].setFini(true);
    }
  }
  taille=colonnes.getTaille();
  for(size_t i=0; i<taille; i++)
  {
    if(!colonnes[i].getFini() && VerifMatrice(i,1))
    {
      colonnes[i].setFini(true);
    }
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

void Picross::amodif(bool ligne, int* Av, int*Ap, size_t n)
{
  if(!ligne)
  {
    for(size_t i=0;i<n;i++)
    {
      if(Av[i]!=Ap[i] && !ligModif.appartient(i))
      {
        ligModif.putFin(i);
      }
    }
  }
  else
  {
    for(size_t i=0;i<n;i++)
    {
      if(Av[i]!=Ap[i] && !colModif.appartient(i))
      {
        colModif.putFin(i);
      }
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
std::ostream &operator<<(std::ostream& os, const Picross &P)
{
  P.afficheP(os);
  return os;
}

//fonctions diverses
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
int* initTab(size_t taille)
{
  int* init=new int [taille];
  for(size_t i=0; i<taille; i++){init[i]=0;}
  return init;
}
Liste* inverseL(const Liste& Lin)
{
  size_t taille=Lin.getLongueur();
  size_t temp=taille;
  Liste* Lout=new Liste();
  for(size_t i = 1; i<=taille; i++)
  {
    Lout->putFin(Lin(temp)->getVal());
    --temp;
  }
  return Lout;
}
void inverseT(int *Tab, size_t taille)
{
  size_t temp;
  for(size_t i=0;i<taille/2;i++)
  {
    temp=Tab[taille-1-i];
    Tab[taille-1-i]=Tab[i];
    Tab[i]=temp;
  }
}
