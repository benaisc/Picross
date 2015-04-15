/*

void Liste::ajoutFin(Cell* c)
{
if(longueur==0)
{
tete=c;
}
else
{
Cell* ptr=tete;
for(size_t j=1; j<longueur; j++)
{
ptr=ptr->getSuiv();
}
ptr->setSuiv(c);
}
++longueur;
}
size_t Liste::cutTl()
{
size_t val=0;
if(!isnull(tete))
{
if(longueur>1)
{
Cell* ptr=tete;
Liste list;
for(size_t j=1; j<longueur; j++)
{
list.putFin(ptr->getVal());
ptr=ptr->getSuiv();
}
val=ptr->getVal();
*this=list;
}
else
{
val=tete->getVal();
this->~Liste();
longueur=0;
}
}
return val;
}
#include <stdlib.h> //rand de creeTab
void creetableau(int T[],int taille)
{
srand(time(NULL));
for(int i=0; i<taille; i++){T[i]=rand()%2-1;}
}
Cette fonction seg_fault mais est à priori inutile
TabListe& TabListe::operator=(TabListe &L)
{
if(taille != 0)
{
delete [] this->tab;
}
taille=L.getTaille();
this->tab=new Liste [taille];
for(size_t i=0; i<taille; i++)
{
this->tab[i]=L[i];
}
return *this;
}
*/
/*
Liste& TabListe::operator=(const Liste& L)
{
this=NULL;
this.setLongueur(L.getLongueur());
Cell *ptr=L.getPremier();
while(!isnull(ptr))
{
Cell a(ptr->getVal());
this.ajoutFin(a);
ptr=ptr->getSuiv();
}
return *this;
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
On à mis l'indice de la cellule dans la liste en valeur dans les T
On passe sur les 0 qui s'entrecroisent,
on ne peut les determiner par cette methode que pour les lignes pleines
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
*/
