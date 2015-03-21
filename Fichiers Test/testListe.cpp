#include "cell.h"
#include "liste.h"

using namespace std;


int main(int argc, char** argv)
{
	Liste L;

	L.putFin(1);
	L.putFin(2);
	L.putFin(3);

	cout << "longueur=" << L.getLongueur() << endl;

	cout << "//test operator<< : " << L << endl;

	cout << "//test operator() : " << endl;
	cout << "L(2) : " << L(2).getVal() << endl;

	Liste L2;
	L2=L;
	cout << "//test operator= : " << L2 << endl;
	cout << "longueur=" << L2.getLongueur() << endl;
	cout << "somElem : " << L.somElem() << endl;


	return 0;
}
