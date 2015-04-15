#ifndef __LISTE_H__
#define __LISTE_H__

/**
* \class Liste
* \brief Classe représentant la liste par une tete et son nombre de cellules
* Ainsi qu'un booleen indiquant si toutes les cellules ont été placées
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
	sint longueur;
	bool fini;

public:
	Liste(); /**< Constructeur par défaut, tete=NULL et longueur=0 */
	~Liste();
	/**
	* \fn isnull(Cell*) const
	* \brief 1 si la liste est vide, 0 sinon
	*/
	bool isnull(Cell*) const;	/**< \return 1 si vide, 0 sinon */
	Cell* getPremier() const;	/**< \return la tete de liste */
	sint getLongueur() const;	/**< \return le nombre de cellules de la liste */
	bool getFini() const; /**< \return le booleen indiquant si liste validee */
	void setFini(bool);
	/**
	* \fn putFin(sint)
	* \brief Ajout d'une cellule en queue de liste
	* \param Valeur de la cellule à placer
	*/
	void putFin(sint);
	/**
	* \fn add(sint)
	* \brief Ajout d'une cellule en tete de liste
	*/
	void add(sint);
	/** \fn cutHd();
	* \brief supprime la tete de la liste et renvoie sa valeur
	*/
	sint cutHd();
	/**
	* \fn operator()(sint i)
	* \brief Sucre syntaxique permettant l'accès aux éléments d'une liste
	* \param i "l'indice" de la cellule dans la liste; L(1)=tete
	* Si i>longueur, le programme s'arrête, évitant la seg fault
	* \return Un pointeur sur la cellule
	*/
	Cell* operator()(sint) const;
	/**
	* \fn operator=(const Liste&)
	* \brief Operateur par copie
	* Utilisation : L1=L2
	* \param Liste dont les valeurs doivent être copiées
	*/
	Liste& operator=(const Liste&);
	/**
	* \fn somCell()
	* \brief renvoie la valeur des blocs de cases à placer
	*/
	sint somCell() const;
	/**
	* \fn somElem()
	* \brief renvoie la valeur du bloc de cases à placer (avec 1 blanc entre chaque bloc)
	*/
	sint somElem() const;
	bool appartient(sint) const; 	/**< \return 1 si la valeur est dans la liste, 0 sinon */
	Liste* inverseL_cst() const;

	void afficheL(std::ostream&) const; /**< 1->2->... */
	std::string afficheListe() const;
	std::string afficheListeV() const;
};
std::ostream &operator<<(std::ostream &os, const Liste &Li);	/**< 1->2->... */
#endif
