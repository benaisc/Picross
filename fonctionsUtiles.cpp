
#include "fonctionsUtiles.h"
using namespace std;
void afftableau(int T[], int taille)
{
  int i;
  cout<<endl<<"T[";
  for (i=0; i<taille; i++)
    {
      cout<<T[i];
      if (i!=taille-1)
	cout<<", ";
    }
  cout<<"]"<<endl;
}
void creetableau(int T[],int taille)
{
    srand(time(NULL));
    int i=0;
    for (i=0; i<taille; i++)
        T[i]=rand()%2-1;
}
