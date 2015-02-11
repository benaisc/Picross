#ifndef __TABLISTE_H__
#define __TABLISTE_H__

/**
* \class TabListe
* \brief Classe représentant un tableau de listes de cellules
*/

#include "liste.h"

class TabListe
{
private:
	size_t taille;
	Liste* tab;

public:
	TabListe(size_t);
	~TabListe();
	size_t getTaille() const;
	/**
	* \fn error()
	* \brief Stratagème pour sortir du programme avec élégance
	* Affiche problèmes sur terminal en cas d'erreur
	*/
	void error() const;
	/**
	* \fn operator[](size_t)
	* \brief Sucre syntaxique évitant les seg. fault
	*
	* \param i l'indice de la liste dans le tableau[O..taille-1]
	* \return tab[i]
	*/
	Liste &operator[](size_t);
	/**
	* \fn operator=()
	* \brief Surcharge opérateur
	*/
	//TabListe &operator=(TabListe&);
	//Liste& operator=(const Liste&);
	void afficheT(std::ostream&) const;
};
/**
* \fn operator<<(&ostream, &TabListe)
* \brief Sucre syntaxique permettant l'affichage d'un tabListe
* \param os un flux, L le tabListe
* \return Affichage
*/
std::ostream &operator<<(std::ostream&, TabListe&); /**< T[0]=1->1->.. */

#endif
