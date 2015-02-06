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
void Picross::affiche_ter(std::ostream& f)const{
  lignes.affiche_ter(f);
  colonnes.affiche_ter(f);
  mat.affiche_ter(f);
}

//operateur d'affichage
std::ostream& operator<<( std::ostream& flux, Picross const& picross )
{
  picross.affiche_ter(flux);
    return flux;
}
