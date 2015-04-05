# include "matrice.h"

Matrice::Matrice(size_t nbl, size_t nbc) : nbl(nbl), nbc(nbc)
{
  if(nbc!=0 && nbl!=0)
  {
    mat=new int* [nbl];
    for(size_t i=0; i<nbl; i++)
    {
      mat[i]=new int [nbc];
      for(size_t j=0; j<nbc; j++)
      {
        mat[i][j]=0;
      }
    }
  }
}
//donc T[lignes][colonnes]
Matrice::~Matrice()
{
  for(size_t i=0;i<nbl;i++)
  {
    delete [] mat[i];
  }
  delete [] mat;
}

int** Matrice:: getMat()const
{
  return mat;
}
size_t Matrice:: getNbc()const
{
  return nbc;
}
size_t Matrice:: getNbl()const
{
  return nbl;
}
int Matrice::getValue(size_t nl, size_t nc) const
{
  int v=0;
  if(nl+nc<nbl+nbc)
  {
    v=mat[nl][nc];
  }
  return v;
}
void Matrice::setValue(size_t nl, size_t nc, size_t v)
{
  if(nl+nc<nbl+nbc)
  {
    mat[nl][nc]=v;
  }
}
void Matrice::setLigne(size_t nl, int* T)
{
  if(nl<nbl)
  {
    for(size_t i=0;i<nbc;i++)
    {
      mat[nl][i]=T[i];
    }
  }
}
void Matrice::setColonne(size_t nc, int* T)
{
  if(nc<nbc)
  {
    for(size_t i=0;i<nbl;i++)
    {
      mat[i][nc]=T[i];
    }
  }
}
void Matrice::afficheM(std::ostream &os)const
{
  for(size_t i=0; i<nbl;i++)
  {
    os << "\n" << "L|C[" << i << "] : ";
    for(size_t j=0;j<nbc;j++)
    {
      switch(mat[i][j])
      {
      case(-1):
        os<<" "<<"\u25A7"<<" ";
        break;
      case(0):
        os<<" "<<"\u25A1"<<" ";
        break;
      case(1):
        os<<" "<<"\u25A0"<<" ";
        break;
      default:
        os<<" "<<"\u25A3"<<" ";
        break;
      }
    }
  }
  os << std::endl;
}


std::ostream &operator<<(std::ostream &os, const Matrice &M)
{
  M.afficheM(os);
  return os;
}
