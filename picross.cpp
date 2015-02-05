#include "picross.h"

//constructeur
Picross::Picross(Matrice mat, TabListe lignes, TabListe colonnes) : mat(mat), lignes(lignes), colonnes(colonnes){}
//accesseur
TabListe Picross::getLignes()const{
  return lignes;
}
TabListe Picross::getColonnes()const{
  return colonnes;
}
Matrice Picross::getMat()const{
  return mat;
}
//Methode
void Picross::affiche_ter()const{
  lignes.affiche_ter();
  colonnes.affiche_ter();
  mat.affiche_ter();
}

//operateur d'affichage
std::ostream& operator<<( std::ostream &flux, Picross const& picross )
{
  picross.affiche_ter();
    return flux;
}
