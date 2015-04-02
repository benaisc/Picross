#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  ifstream f;
  //f.open(argv[1]);
  f.open("Fichiers\ Test/spirale.txt");

  if(!f.is_open())
  {
    cerr<<"probleme d'ouverture du fichier"<<endl;
    return 1;
  }
  else
  {
    /* On lit le fichier texte et construit le Picross */
    size_t nbl, nbc;
    f>>nbl>>nbc;
    Picross P(nbl,nbc);
    f.ignore(); //le '\n'
    P.remplirTabListe(f);

    for(size_t i=0;i<nbl;i++) P.solLignes(nbl,i);
    for(size_t i=0;i<nbc;i++) P.solColonnes(nbc,i);
       
    cout << P;


    /*
    TODO:
    solLignes et solColonnes sont un exemple d'utilisation des méthodes;
    y implémenter une méthode remplissant les cases blanches aux extrémités
    des blocs noirs terminés

    Question : On veut implémenter une methode qui liste les lignes modifiées;
    lorsque l'on modifie une ligne en y placant un noir,
    s'est l'indice de sa colonne associée qu'il faut conserver
    on utilisera alors une fonction recursive qui s'appelera
    tant que des colonnes auront été modifiées de la sorte
    
    Il va falloir rentrer de nouveaux picross tests !
    */
  }
f.close();
return 0;
}
