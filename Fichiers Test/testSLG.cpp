#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  Picross P =Picross(15,15);
  int test[15]={1,1,0,0,-1,0,-1,0,0,0,-1,0,0,0,0}; 
  afftableau(test,15);
  bool b=true;
  Liste L;
  L.putFin(3);
  L.putFin(1);
  L.putFin(2);
  L.putFin(2);
  cout<<L<<endl;
  Cell *c=L.getPremier();
  P.SLG(test,15,c,(size_t)0,b);
  if(b)
    {
      afftableau(test,15);
    }
  else{cout<<"impossible"<<endl;;}
  return 0;
}
