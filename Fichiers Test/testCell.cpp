#include <iostream>
#include "cell.h"

using namespace std;

int main(int argc, char** argv)
{
	Cell* c=new Cell(10);

	//test constructeurs
	cout << "Val c=" << c->getVal() << endl;

	//test operateur par copie
	Cell* d=c;
	cout << "Val d par copie de c : " << d->getVal() << endl;

	//test getter et setter
	c->setVal(5);
	cout << "Nouvelle Val c=" << c->getVal() << endl;

	c->setSuiv(d);
	cout << "Le suivant de cc :" << c->getSuiv() << endl;
	cout << "Verification : &d=" << d << endl;

	delete c;

	return 0;
}
