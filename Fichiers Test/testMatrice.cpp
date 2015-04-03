#include "matrice.h"

using namespace std;

int main(int argc, char** argv)
{
  Matrice M(5,5);
  cout<<"Nombre de lignes " <<M.getNbl()<<endl;
  cout<<"Nombre de colonnes "<<M.getNbc()<<endl;
  int T[5]={-1,1,1,1,-1};
  M.setColonne(0,T);
  M.setValue(4,4,1);
  cout << M;

  return 0;
}
