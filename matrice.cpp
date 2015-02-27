# include "matrice.h"

Matrice::Matrice(size_t nbl, size_t nbc) : nbl(nbl), nbc(nbc)
{
  if(nbc!=0 && nbl!=0)
  {
    mat=new int* [nbc];
    for(size_t i=0; i<nbc; i++)
    {
      mat[i]=new int [nbl];
      for(size_t j=0; j<nbl; j++)
      {
        mat[i][j]=0;
      }
    }
  }
}

Matrice::~Matrice()
{
  for(size_t i=0;i<nbc;i++)
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
  for(size_t i=0; i<nbc;i++)
  {
    os << "\n" << "L|C[" << i << "] : ";
    for(size_t j=0;j<nbl;j++)
    {
      os<<mat[i][j];
    }
  }
  os << std::endl;
}

size_t Matrice::estNoire()
{
  int nbrEstNoire =0;
  Cell c;
  for(size_t i=0;i<nbc;i++)
    {
      for(size_t j=0;j<nbl;j++)
	{
	  if (c.getVal()==-1){ 
	    nbrEstNoire+=1;
	  }
	  return nbrEstNoire;
	}
    }
}


bool Matrice::lignesFinies( Liste &L, Cell& c)
{
  for(size_t i=0;i<nbc;i++)
    {    
      for(size_t j=0;j<nbl; j++)
	{
	  if (c.getVal()!=0 && L.somElem()==estNoire()){
	    return true;
	  }else
	    return false;
	}
    }
}

std::ostream &operator<<(std::ostream &os, Matrice &M)
{
  M.afficheM(os);
  return os;
}
