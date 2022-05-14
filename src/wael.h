#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <gtk/gtk.h>
typedef struct etudiant
{ char nom[20];
  char prenom[20];
  char cin[8];
  int niveau;
}etudiant;
void ajoutereleve(etudiant e);
void supprimereleve(char cin[8]);
void modifiereleve();
void affichereleve(GtkWidget *liste);
void rechercher();
#endif
