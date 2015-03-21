#include <iostream>
#include "cell.h"

using namespace std;

int main(int argc, char** argv)
{
	Cell* c=new Cell(9);
	Cell cc(10);

	//test constructeurs
	cout << "Val c=" << c->getVal() << endl;
	cout << "Val cc=" << cc.getVal() << endl;

	//test operateur par copie
	Cell d=cc;
	cout << "Val d par copie de cc : " << d.getVal() << endl;

	//test getter et setter
	c->setVal(5);
	cout << "Nouvelle Val c=" << c->getVal() << endl;

	cc.setSuiv(c);
	cout << "Le suivant de cc :" << cc.getSuiv() << endl;
	cout << "Verification : &c=" << c << endl;

	delete c;

	return 0;
}
