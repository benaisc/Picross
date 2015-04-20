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
TabListe& Picross::getLignes() 
{
  return lignes;
}
TabListe& Picross::getColonnes() 
{
  return colonnes;
}
Matrice& Picross::getMatrice()
{
  return mat;
}

Liste& Picross::getColModif()
{
 return colModif;
}

Liste& Picross::getLigModif()
{
 return ligModif;
}

void Picross::SLPD(int* T, size_t n, Liste &L)
{
  bool B=false;
  inverseT(T,n);
  Liste* Linv=L.inverseL_cst();
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
  if(P && i<n)
  {
    int* Tab2=new int [n];
    for(size_t j=0;j<n;j++)
    {
      Tab2[j]=Tab[j];
    }
    PlacerBloc(Tab,n,P->getVal(),i,poss);
    if(poss)//si j'ai placer mon bloc
    {
      SLG(Tab,n,P->getSuiv(),i+P->getVal()+1,poss);//bloc suivant
      if(!poss)
      {
        for(size_t j=0;j<n;j++)
        {
          Tab[j]=Tab2[j];
        }
	      if(Tab[i]==1){poss=false;}
        else{SLG(Tab,n,P,i+1,poss);}
      }
    }
    else
    {
      if(Tab[i]==1){poss=false;}
      else{SLG(Tab,n,P,i+1,poss);}
    }
    delete [] Tab2;
  }
  else
  {
    poss=Verification(Tab,i,n);
    if(poss)
    {
	    for(size_t i=0; i<n; i++){if(Tab[i]==0){Tab[i]=-1;}}
    }
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
    if(T1[i]==T2[i] && T2[i]>0)
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

void Picross::isFini(int* T, size_t n, Liste &L)
{
  if(chkSUM(T,L,n))
  {
    L.setFini(true);
  }
}
bool Picross::chkSUM(int *T, Liste &L, size_t n)
{
  sint nbcell=L.getLongueur();
  sint cpt=L.somCell();
  sint nbNoires=0;
  for(size_t i=0; i<n; i++)//on balaie la ligne
  {
    if(T[i]==1)//si on tombe sur un noir
    {
      while(i<n && T[i]==1)//on le balaie
      {
        ++nbNoires;
        ++i;
      }
      --nbcell;//on decompte le nombre de cellules
    }
  }
  return ((cpt==nbNoires)&&(nbcell==0));
}

void Picross::amodif(bool ligne, int* Av, int*Ap, size_t n)
{
  if(!ligne)
  {
    for(size_t i=0;i<n;i++)
    {
      if(Av[i]!=Ap[i] && !ligModif.appartient(i))
      {
        ligModif.add(i);
      }
    }
  }
  else
  {
    for(size_t i=0;i<n;i++)
    {
      if(Av[i]!=Ap[i] && !colModif.appartient(i))
      {
        colModif.add(i);
      }
    }
  }
}

void Picross::Push(int* T, size_t ind, bool b)
{
  if(!b)
  {
    mat.setLigne(ind,T);
  }
  else
  {
    mat.setColonne(ind,T);
  }
}

void Picross::solLignes(size_t ind)
{
  if(!lignes[ind].getFini())
  {
    size_t taille=getNbColonnes();
    int* TG=new int[taille];
    int* TD=new int[taille];
    int* SAVE=new int[taille];
    int* Merge=new int[taille];
    for(size_t i=0; i<taille; i++)
    {
      TG[i]=TD[i]=SAVE[i]=Merge[i]=mat.getValue(ind,i);
    }
    SLPG(TG,taille,lignes[ind]);
    SLPD(TD,taille,lignes[ind]);
    Numeroter(TG,taille);
    Numeroter(TD,taille);
    Fusion(Merge,TG,TD,taille);
    remplirCasesSureBl(Merge,TG, TD, taille, lignes[ind]);
    isFini(Merge, taille, lignes[ind]);
    amodif(true, SAVE, Merge,taille);
    Push(Merge,ind,0);
    delete [] TG;
    delete [] TD;
    delete [] SAVE;
    delete [] Merge;
  }
}
void Picross::solColonnes(size_t ind)
{
  if(!colonnes[ind].getFini())
  {
    size_t taille=getNbLignes();
    int* TG=new int[taille];
    int* TD=new int[taille];
    int* SAVE=new int[taille];
    int* Merge=new int[taille];
    for(size_t i=0; i<taille;i++)
    {
      TG[i]=TD[i]=SAVE[i]=Merge[i]=mat.getValue(i,ind);
    }
    SLPG(TG,taille,colonnes[ind]);
    SLPD(TD,taille,colonnes[ind]);
    Numeroter(TG,taille);
    Numeroter(TD,taille);
    Fusion(Merge,TG,TD,taille);
    remplirCasesSureBl(Merge,TG, TD, taille, colonnes[ind]);
    isFini(Merge, taille, colonnes[ind]);
    amodif(false, SAVE,Merge,taille);
    Push(Merge,ind,1);
    delete [] TG;
    delete [] TD;
    delete [] SAVE;
    delete [] Merge;
  }
}

void Picross::TINY_SOL_iter()
{
  sint ind=0;
  sint nbl=getNbLignes();
  sint nbc=getNbColonnes();
  while(ind<nbl)
  {
    sint SUM=lignes[ind].somElem();
    if(SUM==0)
    {
      for(size_t i=0; i<nbc; i++)
      {
        mat.setValue(ind,i,-1);
      }
      lignes[ind].setFini(true);
    }
    else if(SUM>nbc/2)
    {
      solLignes(ind);
    }
    ++ind;
  }
  ind=0;
  while(ind<nbc)
  {
    size_t SUM=colonnes[ind].somElem();
    if(SUM==0)
    {
      for(size_t i=0; i<nbl; i++)
      {
        mat.setValue(i,ind,-1);
      }
      colonnes[ind].setFini(true);
    }
    else
    {
      solColonnes(ind);
    }
    ++ind;
  }
}

void Picross::FAT_SOL(sint nbIndLig)
{
  if(nbIndLig>0)
  {
    FAT_LIG();
    FAT_COL();
    FAT_SOL(ligModif.getLongueur());
  }
  else
  {
    setLCFini();
  }
}

void Picross::FAT_LIG()
{
  if(ligModif.getLongueur()>0)
  {
    sint indice=ligModif.cutHd();
    solLignes(indice);
    FAT_LIG();
  }
}

void Picross::FAT_COL()
{
  if(colModif.getLongueur()>0)
  {
    sint indice=colModif.cutHd();
    solColonnes(indice);
    FAT_COL();
  }
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
  for(size_t j=1; j<(unsigned)L.getLongueur()+1 ;j++)
  {//j=numerodubloc 1.2.3...
    while(minG<n && (size_t)Tg[minG]!=j)
    {
      minG++;
    }
    while(minD<n && (size_t)Td[minD]!=j)
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
    if(Te[i]==-1)
  	   Res[i]=Te[i];
  }
  delete [] Te;
}

bool Picross::VerifMatrice(size_t ind, bool B) const
{
  if(!B)
  {
    sint nbcell=lignes[ind].getLongueur();
    sint cpt=lignes[ind].somCell();
    sint nbNoires=0;
    sint taille=mat.getNbc();
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
    sint nbcell=colonnes[ind].getLongueur();
    sint cpt=colonnes[ind].somCell();
    sint nbNoires=0;
    sint taille=mat.getNbl();
    for(size_t i=0; i<taille; i++)
    {
      if(mat.getValue(i,ind)==1)
      {
        ++nbNoires;
        ++i;
        while(i<taille && mat.getValue(i,ind)==1)
        {
          ++nbNoires;
          ++i;
        }
        --nbcell;
      }
    }
    return ((cpt==nbNoires)&&(nbcell==0));
  }
}
void Picross::setLCFini()
{
  sint taille=lignes.getTaille();
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

bool Picross::isPicrossFini() const
{
  sint taille=lignes.getTaille();
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

sint Picross::getNbLignes() const
{
  return mat.getNbl();
}
sint Picross::getNbColonnes() const
{
  return mat.getNbc();
}

int** Picross::copieMat() const
{
  sint nbL=getNbLignes();
  sint nbC=getNbColonnes();
  int** save=new int* [nbL];
  for(sint i=0; i<nbL; i++)
  {
    save[i]=new int [nbC];
    for(sint j=0; j<nbC; j++)
    {
      save[i][j]=mat.getValue(i,j);
    }
  }
  return save;
}

void Picross::recopieMat(int** save)
{
  sint nbL=getNbLignes();
  sint nbC=getNbColonnes();
  for(sint i=0; i<nbL; i++)
  {
    for(sint j=0; j<nbC; j++)
    {
      mat.setValue(i,j,save[i][j]);
    }
  }
}

void Picross::premiereCaseLibre(bool &poss, sint &nl, sint &nc) const
{
  poss=false;
  sint i=0,j=0;
  sint nbL=getNbLignes();
  sint nbC=getNbColonnes();
  while(i<nbL && !poss)
  {
    while(j<nbC && !poss)
    {
      if(mat.getValue(i,j)==0)
      {
        nl=i;
        nc=j;
        poss=true;
      }
      ++j;
    }
    ++i;
    j=0;
  }
}

void Picross::Placer1noir(bool &poss, sint &nl, sint &nc)
{
  premiereCaseLibre(poss,nl,nc);
  if(poss)
  {
    mat.setValue(nl,nc,1);
    ligModif.add(nl);
    colModif.add(nc);
  }
}
void Picross::Placer1blanc(sint &nl, sint &nc)
{
  mat.setValue(nl,nc,-1);
  ligModif.add(nl);
  colModif.add(nc);
}

void Picross::copieBool(bool* L, bool* C)
{
  int nbL=getNbLignes();
  for(int i=0; i<nbL; i++)
  {
    L[i]=lignes[i].getFini();
  }
  int nbC=getNbColonnes();
  for(int i=0; i<nbC; i++)
  {
    C[i]=colonnes[i].getFini();
  }
}

void Picross::recopieBool(bool* L, bool* C)
{
  int nbL=getNbLignes();
  for(int i=0; i<nbL; i++)
  {
    lignes[i].setFini(L[i]);
  }
  int nbC=getNbColonnes();
  for(int i=0; i<nbC; i++)
  {
    colonnes[i].setFini(C[i]);
  }
}

void Picross::backtrack(bool &poss)
{
  FAT_SOL(ligModif.getLongueur());
  if(!isPicrossFini())
  {
    int** SAVE=copieMat();
    bool* TL=new bool [getNbLignes()];
    bool* TC=new bool [getNbColonnes()];
    copieBool(TL,TC);
    sint i=0,j=0;
    Placer1noir(poss,i,j);
    if(poss)
    {
      backtrack(poss);
      if(!poss)
      {
        recopieMat(SAVE);
        recopieBool(TL,TC);
        Placer1blanc(i,j);
        backtrack(poss);
      }
    }
    for(sint k=0; k<getNbLignes(); k++)
    {
      delete [] SAVE[k];
    }
    delete [] SAVE;
    delete [] TL;
    delete [] TC;
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
