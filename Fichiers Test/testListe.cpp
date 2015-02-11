#include "cell.h"
#include "liste.h"

using namespace std;


int main(int argc, char** argv)
{
	Liste L;
	Cell a(1);
	Cell b(2);
	Cell c(3);

	L.ajoutFin(a);
	L.ajoutFin(b);
	L.ajoutFin(c);
	cout << L;	//test operator<<
	cout << "L(2) : "<<L(2).getVal() << endl;	//test operator()


	Liste L2=L;	//test operator=
	cout << L2;


	cout <<"somElem : "<< L.somElem() << endl;

	return 0;
}
