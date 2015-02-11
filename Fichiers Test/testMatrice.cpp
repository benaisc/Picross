#include "matrice.h"


int main(int argc, char** argv)
{
  Matrice M(2,2);

  M.afficheM(std::cout);
  std::cout << M;

  return 0;
}
