#ifndef __CELL_H__
#define __CELL_H__

/**
* \class Cell
* \brief Brique de base pour une liste
*
* Cell est un petit objet permettant de créer des Listes d'entiers.
*/

#include <string>	/**< \def Pour NULL et size_t */

class Cell{
	private:
		size_t val;	/**< size_t == short int (2 octets) */
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
