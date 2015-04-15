#include "Fenetre.hpp"
#include<vector>

using namespace std;
//Pour exécutér ces fichiers il faut télécharger apt-get install libgtkmm-3.0-dev 
// J'utilise cette commande pour compiler g++ *.cpp -Wall -ansi -pedantic -o Main `pkg-config gtkmm-3.0 --cflags --libs`
//Il y a quelques warning, mais ça marche.

Fenetre::Fenetre():
  P(),
  image("Images/Hanjie.jpg"),
  tableau(3,3),
  
  btnQuitter(Gtk::Stock::QUIT),
  btnOuvrir(Gtk::Stock::OPEN),
  btnResolution("Resolution"),

  boiteV(Gtk::BUTTONBOX_END,20),
  
  etiquette1()
  
{

  set_title("Picross");
  set_icon_from_file("Images/picross.png");
  set_default_size(900,600);
  set_position(Gtk::WIN_POS_CENTER);
  set_border_width(15);
 
  btnQuitter.set_can_focus(false);
  btnQuitter.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit)); 

  btnOuvrir.set_can_focus(false);
  btnOuvrir.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::clicker_sur_btnOuvrir) );
  
  btnResolution.set_can_focus(false);
  btnResolution.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::clicker_sur_btnResolution));
 
  boiteV.pack_start(btnOuvrir);
  boiteV.pack_start(btnResolution);
  boiteV.pack_start(btnQuitter);
  // Les coordonnées d'un objet sur tableau  
  // 	 (0,1,0,1) (1,2,0,1) (2,3,0,1) 
  // 	 (0,1,1,2) (1,2,1,2) (2,3,1,2)
  //     (0,1,2,3) (1,2,2,3) (2,3,2,3)
 
  tableau.attach(image,0,1,0,1, Gtk::FILL, Gtk::FILL, 25, 10); 
  tableau.attach(boiteV,0,1,1,2, Gtk::SHRINK, Gtk::SHRINK); 
  tableau.attach(etiquette1, 1, 2, 2, 3, Gtk::SHRINK, Gtk::SHRINK); 
  
  add(tableau);  
 
  show_all();
 
}

Fenetre::~Fenetre(){}

void Fenetre::creerTabPicross(Picross *P,size_t nbl,size_t nbc )
{  
  Gtk::Image *images[nbl][nbc];  
 // std::vector<Glib::RefPtr<Gtk::Image>> images;
 // Glib::RefPtr<Gtk::Image> im (new Gtk::Image("Images/carre_blanc.png"));

  Gtk::Table *tabPicross;
  Gtk::Label *etiquettesH[nbl];
  Gtk::Label *etiquettesV[nbc];
  tabPicross=manage(new Gtk::Table(nbl,nbc));

  for (size_t i=1;i<=nbl; i++)  {
    etiquettesH[i-1]=manage(new Gtk::Label(" "));
    tabPicross->attach(*etiquettesH[i-1], 0, 1, i, i+1,Gtk::SHRINK, Gtk::SHRINK);}
  for (size_t i=1;i<=nbc; i++)  {
    etiquettesV[i-1]=manage(new Gtk::Label(" "));
    tabPicross->attach(*etiquettesV[i-1], i, i+1, 0, 1,Gtk::SHRINK, Gtk::SHRINK);
  }
  
  for (size_t i=0;i<nbl;i++){
  etiquettesH[i]->set_text(P->getLignes()[i].afficheListe());
  }
  for (size_t j=0;j<nbc;j++){
  etiquettesV[j]->set_text(P->getColonnes()[j].afficheListeV());
  }

  for (size_t i=1;i<=nbc; i++){
    for (size_t j=1;j<=nbl; j++){  
      images[i-1][j-1]=manage(new Gtk::Image("Images/carre_blanc.png"));      
      tabPicross->attach(*images[i-1][j-1], i, i+1, j, j+1,Gtk::SHRINK, Gtk::SHRINK);
    }
  }
  
  tableau.attach(*tabPicross, 1, 2, 0, 1, Gtk::SHRINK, Gtk::SHRINK);
  show_all();

}

void Fenetre::creerTabRes(Picross *P,size_t nbl,size_t nbc )
{  
  Gtk::Image *images[nbl][nbc];  
  Gtk::Table *tabPicross;
  Gtk::Label *etiquettesH[nbl];
  Gtk::Label *etiquettesV[nbc];
  tabPicross=manage(new Gtk::Table(nbl,nbc));

  for (size_t i=1;i<=nbl; i++)  {
    etiquettesH[i-1]=manage(new Gtk::Label(" "));
    tabPicross->attach(*etiquettesH[i-1], 0, 1, i, i+1,Gtk::SHRINK, Gtk::SHRINK);}
  for (size_t i=1;i<=nbc; i++)  {
    etiquettesV[i-1]=manage(new Gtk::Label(" "));
    tabPicross->attach(*etiquettesV[i-1], i, i+1, 0, 1,Gtk::SHRINK, Gtk::SHRINK);
  }
  
  for (size_t i=0;i<nbl;i++){
  etiquettesH[i]->set_text(P->getLignes()[i].afficheListe());
  }
  for (size_t j=0;j<nbc;j++){
  etiquettesV[j]->set_text(P->getColonnes()[j].afficheListeV());
  }

  for (size_t i=1;i<=nbc; i++){
    for (size_t j=1;j<=nbl; j++){  
       images[i-1][j-1]=manage(new Gtk::Image(P->getMatrice().afficheMatrice(j-1,i-1)));
      tabPicross->attach(*images[i-1][j-1], i, i+1, j, j+1,Gtk::SHRINK, Gtk::SHRINK);
    }}

  
  tableau.attach(*tabPicross, 1, 2, 0, 1, Gtk::SHRINK, Gtk::SHRINK);
  show_all();

 
}


void Fenetre::clicker_sur_btnOuvrir(){
  Gtk::FileChooserDialog dialog("Ouvrir un fichier *.txt", Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.add_button (Gtk::Stock::OPEN, Gtk::RESPONSE_ACCEPT);
  dialog.add_button (Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  Glib::RefPtr<Gtk::FileFilter> filter =
    Gtk::FileFilter::create();
  filter->set_name("txt");
  filter->add_pattern("*.txt");
  dialog.add_filter(filter);

  const int response = dialog.run();
  dialog.hide();
  switch (response)
    {
    case Gtk::RESPONSE_ACCEPT:{

      file = Glib::filename_to_utf8(dialog.get_filename());
       etiquette1.set_text(file);


      const char * fichier = file.c_str();   
      std::ifstream f; 

      f.open(fichier);
      size_t nbl, nbc;
      f>>nbl>>nbc;
      Picross P(nbl,nbc);
      
      f.ignore();// le '\n' l'affichage d'indice
        P.remplirTabListe(f);

 //Je créé un tableau Picross vide
    creerTabPicross(&P,nbl,nbc); 
      	  
    }
      break;
    default:
      break;	}



}




void Fenetre::clicker_sur_btnResolution(){
  
std:: ifstream f;
const char * fichier = file.c_str();
f.open(fichier);
 size_t nbl, nbc;
 f>>nbl>>nbc;
 Picross P(nbl,nbc); 
 f.ignore();// le '\n' l'affichage d'indice
 P.remplirTabListe(f);
	P.TINY_SOL_iter(nbl,nbc);

    cout << P << endl;

    if(!P.isPicrossFini())
    {
      bool R;
      P.backtrack(R);
      cout<< P<< endl;
    }
 //Je créé un tableau Picross final
       	creerTabRes(&P,nbl,nbc); 
	
}
