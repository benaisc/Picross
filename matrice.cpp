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
      {
        os<<" "<<"\u25A7"<<" ";
      }break;
      case(0):
      {
	os<<" "<<"\u25A1"<<" ";
      }break;
      case(1):
      {
        os<<" "<<"\u25A0"<<" ";
      }break;
      default:
	os<<" "<<"\u25A3"<<" ";
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
