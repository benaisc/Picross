#include "cell.h"
#include "liste.h"

using namespace std;


int main(int argc, char** argv)
{
	Cell a(1);
	Cell b(2);
	Cell c(3);
	Liste L;

	L.ajoutFin(a);
	L.ajoutFin(b);
	L.ajoutFin(c);

	cout << "longueur=" << L.getLongueur() << endl;

	cout << "afficheL : ";
	L.afficheL(cout);

	cout << "//test operator<< : " << L << endl;

	cout << "//test operator() : " << endl;
	cout << "L(2) : " << L(2).getVal() << endl;

	Liste L2=L;
	cout << "//test operator= : " << L2 << endl;

	cout << "somElem : " << L.somElem() << endl;


	return 0;
}
