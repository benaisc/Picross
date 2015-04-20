#include "Fenetre.hpp"

using namespace std;
//Pour exécutér ces fichiers il faut télécharger apt-get install libgtkmm-3.0-dev 

Fenetre::Fenetre():
  image("Images/im_picross.png"),
  tableau(3,3),
  
  btnQuitter(Gtk::Stock::QUIT),
  btnOuvrir(Gtk::Stock::OPEN),
  btnResolution("Resolution"),
  btnDescription("Description"),
  boiteV(Gtk::BUTTONBOX_START,10),
  
  etiquette1(),
  etiquette2()
  
{
	
  set_title("Solveur de picross");
  set_icon_from_file("Images/im_picross.png");
  set_default_size(900,600);
  set_position(Gtk::WIN_POS_CENTER);
  set_border_width(15);

  btnQuitter.set_can_focus(false);
  btnQuitter.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit)); 

  btnDescription.set_can_focus(false);
  btnDescription.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::cliquer_sur_btnDescription)); 

  btnOuvrir.set_can_focus(false);
  btnOuvrir.set_focus_on_click(false);
  btnOuvrir.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::cliquer_sur_btnOuvrir) );
  
  btnResolution.set_can_focus(false);
  btnResolution.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::cliquer_sur_btnResolution));
 
  boiteV.pack_start(image);
  boiteV.pack_start(btnDescription);
  boiteV.pack_start(btnOuvrir);
  boiteV.pack_start(btnResolution);
  boiteV.pack_start(btnQuitter);
  
  // Les coordonnées d'un objet sur tableau  
  // 	 (0,1,0,1) (1,2,0,1) (2,3,0,1) 
  // 	 (0,1,1,2) (1,2,1,2) (2,3,1,2)
  //     (0,1,2,3) (1,2,2,3) (2,3,2,3)
 
  tableau.attach(boiteV,0,1,0,1, Gtk::FILL, Gtk::FILL, 10, 10); 
  tableau.attach(etiquette1, 1, 2, 0, 1, Gtk::SHRINK, Gtk::SHRINK); 
  tableau.attach(etiquette2, 1, 2, 2, 3, Gtk::FILL, Gtk::FILL, 0, 5); 
  
  add(tableau);  
 
  show_all();
 
}

Fenetre::~Fenetre(){}


void Fenetre::creerTabPicross(Picross &P,size_t nbl,size_t nbc )
{  
  etiquette1.set_text(" ");
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
    etiquettesH[i]->set_text(P.getLignes()[i].afficheListe());
  }
  for (size_t j=0;j<nbc;j++){
    etiquettesV[j]->set_text(P.getColonnes()[j].afficheListeV());
  }

  for (size_t i=1;i<=nbc; i++){
    for (size_t j=1;j<=nbl; j++){  
      images[i-1][j-1]=manage(new Gtk::Image("Images/carre_blanc.png"));      
      tabPicross->attach(*images[i-1][j-1], i, i+1, j, j+1,Gtk::SHRINK, Gtk::SHRINK);
    }
  }
  
  tableau.attach(*tabPicross, 1, 2, 0, 1, Gtk::FILL, Gtk::FILL, 70, 0);
  show_all();

}

void Fenetre::creerTabRes(Picross &P,size_t nbl,size_t nbc )
{  
  etiquette1.set_text(" ");
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
    etiquettesH[i]->set_text(P.getLignes()[i].afficheListe());
  }
  for (size_t j=0;j<nbc;j++){
    etiquettesV[j]->set_text(P.getColonnes()[j].afficheListeV());
  }

  for (size_t i=1;i<=nbc; i++){
    for (size_t j=1;j<=nbl; j++){  
      images[i-1][j-1]=manage(new Gtk::Image(P.getMatrice().afficheMatrice(j-1,i-1)));
      tabPicross->attach(*images[i-1][j-1], i, i+1, j, j+1,Gtk::SHRINK, Gtk::SHRINK);
    }
  }
  
  tableau.attach(*tabPicross, 1, 2, 0, 1,  Gtk::FILL, Gtk::FILL, 70, 0);
  show_all();

 
}


void Fenetre::cliquer_sur_btnOuvrir(){
  if  (btnOuvrir.get_focus_on_click()==false){
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
      etiquette2.set_justify(Gtk::JUSTIFY_CENTER);
      etiquette2.set_text(file);
      const char * fichier = file.c_str();   
      std::ifstream f; 

      f.open(fichier);
      size_t nbl, nbc;
      f>>nbl>>nbc;
      Picross P(nbl,nbc);
      
      f.ignore();
      P.remplirTabListe(f);

      //Je créé un tableau Picross vide
      creerTabPicross(P,nbl,nbc); 
      btnOuvrir.set_focus_on_click(true);
      	  
    }
      break;
    default:
      break;	}

  }

}


void Fenetre::cliquer_sur_btnResolution(){
  if (btnOuvrir.get_focus_on_click()==true){
    std:: ifstream f;
    const char * fichier = file.c_str();
    f.open(fichier);
    size_t nbl, nbc;
    f>>nbl>>nbc;
    Picross P(nbl,nbc); 
    f.ignore();
    P.remplirTabListe(f);
    P.TINY_SOL_iter();

    cout << P << endl;

    if(!P.isPicrossFini())
      {
	 bool R;
          P.backtrack(R);
          cout<<"On fini avec Res Ã  : "<<boolalpha<<R<<noboolalpha<<endl;
	  creerTabRes(P,nbl,nbc);
	  cout<< P.getMatrice() << endl;
      }
    //Je créé un tableau Picross final
    creerTabRes(P,nbl,nbc); 
  }else{ 
    afficherErreur(); 
  }

}
void Fenetre::cliquer_sur_btnDescription(){
  if (btnOuvrir.get_focus_on_click()==false){
    etiquette1.set_justify(Gtk::JUSTIFY_CENTER);
    etiquette1.set_markup("<span font='11.5' style='oblique' face='Comic sans MS'><b>Solveur de picross </b>\n  Le Picross est un casse-tête qui consiste à retrouver une figure à partir d’indices.\nLa figure à découvir est une grille dans laquelle chaque case est de couleur noire ou blanche.\n Pour chacune des lignes et colonnes on dispose d’un indice qui est une séquence de nombres\n représentant les longueurs des blocs de cases noires contigües de la ligne/colonne. Les blocs\n de cases noires sont séparées par au moins une case blanche.</span>  ");

  }
}

void Fenetre::afficherErreur() {
  Gtk::MessageDialog dialogue(*this, "Erreur!", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
  dialogue.set_title("Erreur");
  dialogue.set_secondary_text(" D'abord veuillez cliquer sur le bouton \"Ouvrir!\"");
  dialogue.run();
  dialogue.hide();
}
