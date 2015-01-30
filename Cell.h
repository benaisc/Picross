#ifndef __CELL_H__
#define __CELL_H__


class Cell{
	private:
		Cell* suiv;
		size_t val;
  	public:
		Cell(size_t);
		
		size_t getVal() const;
		Cell* getSuiv() const;
		void setVal(size_t);
		void setSuiv(Cell*);
		Cell& operator=(const Cell&);
};
#endif
