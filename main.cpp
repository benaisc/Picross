#include "cell.h"
#include "liste.h"

using namespace std;


int main(int argc, char** argv)
{
	Liste L;
	Cell a(1);
	Cell b(2);
	Cell c(3);

	L.setSuivant(L.getPremier(), &a);
	L.setSuivant(&a, &b);
	L.setSuivant(&b, &c);
	L.affiche();


	//Probleme dans le destructeur arrivé à delete p; 

	return 0;
}
