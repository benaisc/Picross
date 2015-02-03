#include "cell.h"


Cell::Cell() : val(0), suiv(NULL){}

Cell::Cell(size_t v) : val(v), suiv(NULL){}

void Cell::setVal(size_t v)
{
	val=v;
}

void Cell::setSuiv(Cell& c)
{
	suiv=&c;
}

size_t Cell::getVal() const
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
		this->suiv=c.getSuiv();
		this->val=c.getVal();
	}
	return *this;
}
