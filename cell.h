#ifndef __CELL_H__
#define __CELL_H__

/**
* \class Cell
* \brief Brique de base pour une liste
*
* Cell est un petit objet permettant de créer des Listes d'entiers.
*/

#include <string>	/**< \def Pour NULL et size_t */

typedef unsigned short int sint;

class Cell{
	private:
		sint val;	/**< size_t == short int (2 octets) */
		Cell* suiv;

  public:
		Cell();
		Cell(sint);

		void setVal(sint);
		void setSuiv(Cell*);
		sint getVal() const;
		Cell* getSuiv() const;
		Cell& operator=(const Cell&);
};
#endif
