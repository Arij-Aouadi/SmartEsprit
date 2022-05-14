#include <stdlib.h>
#include <stdio.h>
#include "wael.h"
#include <string.h>
#include <gtk/gtk.h>

enum
{
	NOM,
	PRENOM,
	CIN,
	NIVEAU,
	COLUMNS
};
//////////////////////////////////////////////////////////////////////////////////////////////////////


void ajoutereleve(etudiant e)
{
FILE* f=NULL;
f=fopen("residents.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %d\n",e.nom,e.prenom,e.cin,e.niveau);
fclose(f);
}
else printf("le fichier n'existe pas");

}
////////////////////////////////////////////////////////////////////////////////////////////////////


void affichereleve(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;

	GtkTreeIter	iter;

	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char cin[8];
	int niveau;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",NIVEAU,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	
	f=fopen("residents.txt","r");
	if (f==NULL)
	return;
	else
	{f=fopen("residents.txt","a+");
			while(fscanf(f,"%s %s %s %d \n",nom,prenom,cin,&niveau)!=EOF)
		{
	gtk_list_store_append (store,&iter);

	gtk_list_store_set (store ,&iter ,NOM ,nom ,PRENOM ,prenom ,CIN ,cin ,NIVEAU ,niveau , -1);
		}
		fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}







}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void supprimereleve( char cin[8])
	{
	FILE *f=NULL, *f2=NULL;
	etudiant e;
	if (NULL == (f = fopen ("residents.txt", "r")))
	    {printf("Erreur dans l'ouverture du fichier");}
	if (NULL == (f2 = fopen ("utilisateurs.txt", "a+")))
		{printf("Erreur dans l'ouverture du fichier");}

	  while (fscanf (f, "%s %s %s %d",e.nom,e.prenom,e.cin,&e.niveau) == 4)
	    if (strcmp(e.cin,cin)!=0)
	      fprintf (f2, "%s %s %s %d \n",e.nom,e.prenom,e.cin,e.niveau );
	  fclose (f);
	  fclose (f2);
remove("residents.txt");
rename("utilisateurs.txt", "residents.txt");
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void rechercher(char cin[8])
{
etudiant e;
FILE *f=NULL;
f=fopen("residents.txt","r+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %d",e.nom,e.prenom,e.cin,&e.niveau)==4)
	{
	if(strcmp(e.cin,cin)==0)
	return e;
	
	}
}
fclose(f);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int nombre_par_niveau ()
{
etudiant e;
int p,d,t,q,c;
FILE *f=NULL;
f=fopen("residents.txt","r+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %d",e.nom,e.prenom,e.cin,&e.niveau)==4)
{
switch (e.niveau)
{
case 1:
p++;
break;
case 2:
d++;
break;
case 3:
t++;
case 4:
q++;
break;
case 5:
c++;
break;
}

}
}
}
////
void modifiereleve(etudiant e){
etudiant p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen("residents.txt","r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %s %s %d\n",p.nom,p.prenom,p.cin,&p.niveau)!=EOF)
	{
		if(strcmp(p.cin,e.cin)==0)
			fprintf(g,"%s %s %s %d\n",e.nom,e.prenom,e.cin,e.niveau);
		else
			fprintf(g,"%s %s %s %d\n",p.nom,p.prenom,p.cin,p.niveau);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove("residents.txt");
rename("dump.txt","residents.txt");
}
}
///////////////////////////////////////////
