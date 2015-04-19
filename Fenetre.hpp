#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtk/gtk.h>
#include <gtkmm.h>
#include<iostream>
#include <glib.h>
#include <string>
#include "picross.h"

class Fenetre : public Gtk::Window {
public:
  Fenetre();
  ~Fenetre();
  //Signals

  void cliquer_sur_btnOuvrir();
  void cliquer_sur_btnResolution();
  void cliquer_sur_btnDescription();

  // void ouverturePicross(Picross *P);
  void creerTabPicross(Picross *P,size_t nbl,size_t nbc);
  void creerTabRes(Picross *P,size_t nbl,size_t nbc);
  void afficherErreur();

  Glib::ustring file;
 
private:
  Gtk::Image image;
  Gtk::Table tableau;
  Gtk::Button btnQuitter;
  Gtk::Button btnOuvrir;
  Gtk::Button btnResolution;
  Gtk::Button btnDescription;
  
  Gtk::VButtonBox boiteV;
  Gtk::Label etiquette1;
  Gtk::Label etiquette2;
  
};


#endif
