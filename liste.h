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

class Liste
{
private:
	Cell* tete;
	size_t longueur;

public:
	Liste(); /**< Constructeur par défaut, tete=NULL et longueur=0 */
	/**
	* \fn isnull(Cell*) const
	* \brief Test de liste nulle
	*
	* \param Pointeur sur une Cellule
	* \return 1 si la liste est vide, 0 sinon
	*/
	bool isnull(Cell*) const;
	Cell* getPremier() const;	/**< Renvoi la tete de liste */
	size_t getLongueur() const;	/**< return le nombre de cellules de la liste */
	/**
	* \fn operator()(size_t i)
	* \brief Sucre syntaxique permettant l'accès aux éléments d'une liste
	* L(1)=tete
	* \param i "l'indice" de la cellule dans la liste
	* Si i>longueur, le programme s'arrête, évitant la seg fault
	* \return L'adresse de la cellule
	*/
	Cell& operator()(size_t i);
	/**
	* \fn ajoutFin(Cell&)
	* \brief Ajout d'une cellule en queue de liste
	* , en tete de liste si tete==NULL
	* \param l'adresse de la cellule à placer
	*/
	void ajoutFin(Cell&);
	void afficheL() const;	/**< Affiche la liste : 1->2->.. */
};
#endif
