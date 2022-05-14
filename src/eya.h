
                       

#include <gtk/gtk.h>
#include <string.h>
typedef struct {
	int jour;
	int heure;
	int num;
	int val;
}capt;

typedef struct
{
  char firstname [100];
  char lastname [100];
  char cin [10];
  char email [200];
  char phone [50];
  char adress [300];
  char password [100];
}eya;

                          

void add_etudiant (eya e);
void aff_etudiant (GtkWidget* list,char ch[]);
int del_etudiant (char cin[]);
void upd_etudiant (eya e1);
int check_etudiant (char cin []);
void alarme();
void affiche_alarm(GtkWidget* liste);


