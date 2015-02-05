# include "matrice.h"

Matrice::Matrice(size_t nbl, size_t nbc) : nbl(nbl), nbc(nbc){
 
 if(nbc=!0 && mbl=!0)
   {
  mat=new int*[nbc];
  for(size_t i=0;i<nbc;i++)
    {
    mat[i]=new int[nbl];
    for(size_t j=0;j<nbl;i++)
      {
	mat[i][j]=0;
      }
    }
   }
 else
   {
     mat==NULL;
   }

}

int** Matrice:: getMat()const
{
  return mat;
}
size_t Matrice:: getNbc()const
{
  return Nbc;
}
size_t Matrice:: getNbl()const
{
  return Nbl;
}
