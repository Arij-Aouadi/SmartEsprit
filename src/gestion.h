#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>

typedef struct capteur{char id[20];char type[20];int etage;char bloc[10];int valmin;int valmax;int etat;}capteur;
typedef struct appuser{char uname[20];char pw[20];char idesprit[10];}appuser;
void ajoutcap (capteur c);
void modifcap (capteur c);
void suppcap (capteur c);
void recherchcap (capteur c);
void affichcap (GtkWidget *liste);
void vidercap (GtkWidget *liste);
void defect (capteur c,capteur T[]);

void ajoutuser (appuser u);

