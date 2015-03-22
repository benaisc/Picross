/*
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
*/
