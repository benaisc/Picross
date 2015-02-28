#include "matrice.h"
int main(int argc, char** argv)
{
   Matrice M(5,5);
  std::cout << M;
  std::cout<<"Nombre elem noire " <<M.estNoire()<<endl;
  std::cout<<"Lignes sont finies ";
  M.lignesFinies();
  std::cout<<endl;



  return 0;
}
