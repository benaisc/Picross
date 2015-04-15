# include "matrice.h"

Matrice::Matrice(sint nbl, sint nbc) : nbl(nbl), nbc(nbc)
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

int** Matrice::getMat()const
{
  return mat;
}
sint Matrice::getNbc()const
{
  return nbc;
}
sint Matrice::getNbl()const
{
  return nbl;
}
int Matrice::getValue(sint nl, sint nc) const
{
  int v=0;
  if(nl+nc<nbl+nbc)
  {
    v=mat[nl][nc];
  }
  return v;
}
void Matrice::setValue(sint nl, sint nc, int v)
{
  if(nl+nc<nbl+nbc)
  {
    mat[nl][nc]=v;
  }
}
void Matrice::setLigne(sint nl, int* T)
{
  if(nl<nbl)
  {
    for(size_t i=0;i<nbc;i++)
    {
      mat[nl][i]=T[i];
    }
  }
}
void Matrice::setColonne(sint nc, int* T)
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
      case(1):
        os<<" "<<"\u25A0"<<" ";
        break;
      default:
        os<<" "<<"\u25A1"<<" ";
        break;
      }
    }
  }
  os << std::endl;
}

std::string Matrice::afficheMatrice(size_t i,size_t j)const//pour la Fenetre
{
 std::stringstream ss;
      switch(mat[i][j])
      {
      case(-1):
      {
	ss<<"Images/croix.png";
      }break;
      case(0):
      {
	ss<<"Images/carre_blanc.png";
      }break;
      case(1):
      {
        ss<<"Images/carre_noir.png";
      }break;
      default:
	ss<<"Images/carre_blanc.png";
      }
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Matrice &M)
{
  M.afficheM(os);
  return os;
}
