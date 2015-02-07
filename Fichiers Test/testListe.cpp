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
	L.afficheL();

	Cell d(9);
	L.ajoutFin(d);
	cout << L(4).getVal() << endl;//test sucre
	L.afficheL();
	
	cout << L.somElem() << endl;

	return 0;
}
