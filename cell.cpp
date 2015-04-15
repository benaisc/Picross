#include "cell.h"


Cell::Cell() : val(0), suiv(NULL){}

Cell::Cell(sint v) : val(v), suiv(NULL){}

void Cell::setVal(sint v)
{
	val=v;
}

void Cell::setSuiv(Cell* c)
{
	suiv=c;
}

sint Cell::getVal() const
{
	return val;
}

Cell* Cell::getSuiv() const
{
	return suiv;
}

Cell& Cell::operator=(const Cell& c)
{
	if(this != &c)
	{
		suiv=c.getSuiv();
		val=c.getVal();
	}
	return *this;
}
