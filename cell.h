#ifndef __CELL_H__
#define __CELL_H__

#include <string>//pour NULL et size_t

class Cell{
	private:
		size_t val;
		Cell* suiv;

  public:
		Cell();
		Cell(size_t);

		void setVal(size_t);
		void setSuiv(Cell*);
		size_t getVal() const;
		Cell* getSuiv() const;
		Cell& operator=(const Cell&);
};
#endif
