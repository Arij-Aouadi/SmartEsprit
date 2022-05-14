#ifndef FONCTION_H_
#define FONCTION_H_
#include <stdio.h>
#include <gtk/gtk.h> 
typedef struct
{
int id;
char nom[20];
char prenom[20];
char cin_ou_passeport[20];
char classe[10];
char date_rec[30];
char details_reclamation[1000];
char type[20];
}rec;

typedef struct{
	char identifiant[20];
	char mot_de_passe[50];
	}login;


void ajouter(rec r,char fichier_reclamation[]);
void afficher(rec r,char fichier_reclamation[]);
void supprimer(int Id,char fichier_reclamation[]);
void modifier(int id ,rec r , char fichier_reclamation[]);
void chercher(int id,char fichier_reclamation[]);
int chercher_id();
void afficher_treev(GtkWidget *liste);
void recherche_treev(GtkWidget *liste, char id_rech[20]);
#endif

