#include <iostream>
#include "cell.h"

using namespace std;

int main(int argc, char** argv)
{
	Cell c;
	Cell cc(10);

	//test constructeurs
	cout<<"Val c="<<c.getVal()<<endl;
	cout<<"Val cc="<<cc.getVal()<<endl;

	//test operateur par copie
	Cell d=cc;
	cout<<"Val d par copie de cc : "<<d.getVal()<<endl;

	//test getter et setter
	c.setVal(5);
	cout<<"Nouvelle Val c="<<c.getVal()<<endl;

	c.setSuiv(&cc);
	cout<<"Le suivant de c :"<<c.getSuiv()<<endl;
	cout<<"Verification, &cc="<<&cc<<endl;



	return 0;
}
