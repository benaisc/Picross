#include "picross.h"
using namespace std;

int main(int argc, char** argv)
{
  ifstream f;
  //f.open(argv[1]);
  f.open("Fichiers\ Test/tipoisson.txt");

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
      
      //on rempli les lignes des cases sures
      P.solCasesSure(1);
      while(P.getColModif().getLongueur()!=0 && P.getLigModif().getLongueur()!=0)
	{
	  while(P.getLigModif().getLongueur()!=0)//appel sur les LignesModifier
	    {
	      //on appelera solcaseSure sur la ligne place a l'indice longueur-1 de la liste Ligmodif
	      P.getLigModif().cutTail();
	    }
	  while(P.getColModif().getLongueur()!=0)//appel sur les ColonnesModifier
	    {
	      //on appelera solcaseSure sur la colonne place a l'indice longueur-1 de la liste Colmodif
	      P.getColModif().cutTail();
	    }
	}
      cout<<P;
    }

  return 0;
}
