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

  void clicker_sur_btnOuvrir();
  void clicker_sur_btnResolution();

  void creerTabPicross(Picross *P,size_t nbl,size_t nbc);
  void creerTabRes(Picross *P,size_t nbl,size_t nbc);
 
  Glib::ustring file;
 
private:
  Picross *P;
  Gtk::Image image;
  Gtk::Table tableau;
  Gtk::Button btnQuitter;
  Gtk::Button btnOuvrir;
  Gtk::Button btnResolution;
  
  Gtk::VButtonBox boiteV;
  Gtk::Label etiquette1;
  
};


#endif
