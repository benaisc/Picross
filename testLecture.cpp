#include "fonction.h"

using namespace std;

int main(int argc, char **argv)
{
  ifstream f;
  f.open(argv[1]);

  if(!f.is_open())
  {
    cerr<<"probleme d'ouverture du fichier"<<endl;
    return 1;
  }
  else
  {
    lecture(f);
  }

  f.close();

  return 0;
}
