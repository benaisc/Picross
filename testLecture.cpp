#ifndef __TESTLECTURE_H__
#define __TESTLECTURE_H__
#include "picross.h"
#include "fonction.h"
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
  ifstream fichier(argv[1]);
  if(!fichier)
    {
      cerr<<"probleme d'ouverture du fichier"<<endl;
      return 1;
    }

  Picross picross=lecture(fichier);
  fichier.close();
  cout<<picross;
  return 0;
} 
#endif
