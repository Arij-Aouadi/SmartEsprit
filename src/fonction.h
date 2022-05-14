#include <gtk/gtk.h> 

typedef struct
{
	char id[50];
	char Pw[50];
}user;



typedef struct
{
	char jour[20];
	int  temps;
	char entree[50];
	char plat_principale[50];
	char dessert[50];
	int dechets;
}menu;


void affichermenu(GtkWidget *liste);

void vider_menu(GtkWidget *liste);

void ajout_menu(menu m);

void supprimer_menu(char jour[],int temps);

menu rechercher_menu(char jour[],int temps);

void modifier_menu(menu m);

void meilleur_menu(char best1[], char best2[],char best3[],char best4[]);

void Resultat(char jour[],int temps,char texte[]);

//void choix_temps(int choix,int temps);

int verif_user(char log[],char Pw[]);

//int verif_user(char log[],char Pw[]);
