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
      if(mat[i][j]>=0)
      {
        os<<"  "<<mat[i][j]<<" ";
      }
      else
      {
        os<<" "<<mat[i][j]<<" ";
      }
    }
  }
  os << std::endl;
}

size_t Matrice::estNoire()
{
  int nbrEstNoire =0;
  for(size_t i=0;i<nbc;i++)
    {
      for(size_t j=0;j<nbl;j++)
	{
	  if (mat[i][j]==1){
	    nbrEstNoire+=1;
	  }
	}
    }
return nbrEstNoire;
}



bool Matrice::lignesFinies()
{
  bool flag=true;
    for(size_t i=0;i<nbc;i++)
    {
      for(size_t j=0;j<nbl; j++)
	{
	  if( mat[i][j]!=0 ){}else{
	    flag=false;
	  }
	}
    }
std::cout<<flag;
 return 0;
}



std::ostream &operator<<(std::ostream &os, Matrice &M)
{
  M.afficheM(os);
  return os;
}
