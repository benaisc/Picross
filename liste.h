#ifndef __LISTE_H__
#define __LISTE_H__

/**
* \class Liste
* \brief Classe représentant la liste par une tete et son nombre de cellules
*
* Elle sera utilisée via un Tableau de listes
*/

#include "cell.h"
#include <iostream>	/**< \def Pour l'affichage,il sera utilisé par la suite */
#include <stdlib.h>	/**< \def Pour la fonction exit() sortant du programme proprement */
#include <sstream>

class Liste
{
private:
	Cell* tete;
	size_t longueur;
	bool fini;

public:
	Liste(); /**< Constructeur par défaut, tete=NULL et longueur=0 */
	~Liste();
	/**
	* \fn isnull(Cell*) const
	* \brief Test de liste nulle
	*
	* \param Pointeur sur une Cellule
	* \return 1 si la liste est vide, 0 sinon
	*/
	bool isnull(Cell*) const;	/**< \return 1 si vide, 0 sinon */
	Cell* getPremier() const;	/**< \return la tete de liste */
	size_t getLongueur() const;	/**< \return le nombre de cellules de la liste */
	bool getFini() const; /**< \return le booleen indiquant si liste validee */
	void cutTail();
	size_t cutHd(); /**< \brief supprime le premier element de la liste et renvoie sa valeur */
	size_t cutTl(); /**< \brief supprime le dernier element de la liste et renvoie sa valeur */
	void setFini(bool);
	/**
	* \fn putFin(Cell&)
	* \brief Ajout d'une cellule en queue de liste
	* \param Valeur de la cellule à placer
	*/
	void putFin(size_t);
	/**
	* \fn putFin(Cell&)
	* \brief Ajout d'une cellule en tete de liste
	*/
	void add(size_t);
	/**
	* \fn ajoutFin(Cell&)
	* \brief Ajout d'une cellule en queue de liste
	* \param Cellule à placer
	*/
	void ajoutFin(Cell*);
	/**
	* \fn operator()(size_t i)
	* \brief Sucre syntaxique permettant l'accès aux éléments d'une liste
	* L(1)=tete
	* \param i "l'indice" de la cellule dans la liste
	* Si i>longueur, le programme s'arrête, évitant la seg fault
	* \return Un pointeur sur la cellule
	*/
	Cell* operator()(size_t) const;
	/**
	* \fn operator=(const Liste&)
	* \brief Operateur par copie
	* Utilisation : L1=L2
	* \param Liste dont les valeurs doivent être copiées
	*/
	Liste& operator=(const Liste&);
	/**
	* \fn somCell()
	* \brief renvoie la valeur des blocs de case à placer
	*/
	size_t somCell() const;
	/**
	* \fn somElem()
	* \brief renvoie la valeur du bloc de cases à placer (avec blancs)
	*/
	size_t somElem() const;
	bool appartient(size_t) const; 	/**< \return 1 si la valeur est dans la liste, 0 sinon */
	Liste* inverseL_cst() const;

	void afficheL(std::ostream&) const; /**< 1->2->... */
	std::string afficheListe() const;
	std::string afficheListeV() const;
};
std::ostream &operator<<(std::ostream &os, const Liste &Li);	/**< 1->2->... */
#endif
