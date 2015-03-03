#include "picross.h"
#include "liste.h"

using namespace std;

int main(int argc, char** argv)
{
  Liste L;
  L.putFin(2);
  L.putFin(1);
  L.putFin(1);

  Picross P(6,6);
  
  cout << "afficheL : ";
  L.afficheL(cout);

  int* ligne=P.getLigneMat(1);

  int* lsol = P.solGauche(ligne,L,0);
  
  for (size_t i=0; i<6; i++)
    {
      cout << lsol[i] << endl;
    }

  return 0;
}
