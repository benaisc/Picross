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
	cout << "L(2) : " << L(2)->getVal() << endl;

	cout << "appartient(1) : " << L.appartient(1) << endl;
	cout << "appartient(4) : " << L.appartient(4) << endl;

	Liste L2;
	L2=L;
	cout << "//test operator= : " << L2;
	cout << "longueur=" << L2.getLongueur() << endl;
	cout << "somElem : " << L.somElem() << endl;

	cout << "test suppression elements : " << endl;
	cout <<L.cutHd()<< endl;
	cout <<L.cutHd()<< endl;
	cout <<L.cutHd()<< endl;
	cout <<"Verification longueur de la liste : "<< L.getLongueur() << endl;

	return 0;
}
