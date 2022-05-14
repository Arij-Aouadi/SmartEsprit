#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h> 

enum{
	EID,
	ENOM,
	EPRENOM,
	ECIN,
	ECLASSE,
	EDATE,
	ERECLAMATION,
	EDEPARTEMENT,
	COLUMNS,
	};

//ajout

void ajouter(rec r,char fichier_reclamation[])
{
FILE *f=NULL;
f=fopen("reclamation.txt","a");
if (f!=NULL){
fprintf(f,"%d %s %s %s %s %s %s %s \n",r.id,r.nom,r.prenom,r.cin_ou_passeport,r.classe,r.date_rec,r.details_reclamation,r.type);
fclose(f);}
}


// affichage

void afficher(rec r,char fichier_reclamation[])
{

FILE *f=NULL;
f=fopen("reclamation.txt","r");
if (f!=NULL){
char c=fgetc(f);
while(c != EOF)
{ printf("%c",c);
 c=fgetc(f);}

}

else
printf("impossible d'ouvrir le fichier reclamation.txt \n");
fclose(f);

}


void chercher(int id,char fichier_reclamation[])
{
rec r;
FILE *f=NULL;
f=fopen("reclamation.txt","r");
if (f!=NULL)
{

while(fscanf(f,"%d %s %s %s %s %s %s %s \n",&(r.id),r.nom,r.prenom,r.cin_ou_passeport,r.classe,r.date_rec,r.details_reclamation,r.type)!=EOF)
{
if ((r.id)==id)
printf("%d %s %s %s %s %s %s %s",r.id,r.nom,r.prenom,r.cin_ou_passeport,r.classe,r.date_rec,r.details_reclamation,r.type);
}
}
fclose(f);
}

//suppression

void supprimer(int id,char fichier_reclamation[])
{
int a;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20];
FILE *f=NULL;
FILE *f1=NULL;
f=fopen("reclamation.txt","r");
f1=fopen("tmp.txt","a");
if (f==NULL)
printf("erreur");
else
{
if (f1==NULL)
printf("erreur");
else
{
while(fscanf(f,"%d %s %s %s %s %s %s %s \n",&a,ch1,ch2,ch3,ch4,ch5,ch6,ch7)!=EOF)
{
if (a !=id)
fprintf(f1,"%d %s %s %s %s %s %s %S \n",a,ch1,ch2,ch3,ch4,ch5,ch6,ch7);
}

fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("tmp.txt","reclamation.txt");
}

}
}

// modifier

void modifier(int id2 ,rec r2 , char fichier_reclamation[])

{    FILE *f;
     FILE *f2;
    rec r;
     f=fopen("reclamation.txt","r");
    f2=fopen("fsupp.txt","w+");

     while(fscanf(f,"%d %s %s %s %s %s %s %s \n",&(r.id),r.nom,r.prenom,r.cin_ou_passeport,r.classe,r.date_rec,r.details_reclamation,r.type)!=EOF)
       {
           if  (id2 != r.id)
               { fprintf(f2,"%d %s %s %s %s %s %s %s \n",r.id,r.nom,r.prenom,r.cin_ou_passeport,r.classe,r.date_rec,r.details_reclamation,r.type);
}

               else

                 {
                      fprintf(f2,"%d %s %s %s %s %s %s %s \n",r.id,r2.nom,r2.prenom,r2.cin_ou_passeport,r2.classe,r2.date_rec,r2.details_reclamation,r.type);
}

                      }


               fclose(f);
               fclose(f2);

               remove("reclamation.txt");
        rename("fsupp.txt","reclamation.txt");

        }

        //find last id

        int chercher_id()
{
    rec r;
	r.id=0;
FILE *f=NULL;
f=fopen("reclamation.txt","r");
if (f!=NULL)
{

while(fscanf(f,"%d %s %s %s %s %s %s %s \n",&(r.id),r.nom,r.prenom,r.cin_ou_passeport,r.classe,r.date_rec,r.details_reclamation,r.type)!=EOF)
;
}

else {fclose(f);
    return(0);}
fclose(f);
return (r.id);
}


		//affichage
void afficher_treev(GtkWidget *liste)
{GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;
 FILE *f;
char id[20];
char nom[20];
char prenom[20];
char cin_ou_passeport[20];
char classe[10];
char date_rec[20];
char details_reclamation[1000]; 
char departement[20];
store=NULL;

store=gtk_tree_view_get_model(liste);

if(store==NULL){

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("id",renderer, "text", EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("nom",renderer, "text", ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer, "text", EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("cin",renderer, "text", ECIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("classe",renderer, "text", ECLASSE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("date",renderer, "text", EDATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("reclamation",renderer, "text", ERECLAMATION, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("departement",renderer, "text", EDEPARTEMENT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
}

store= gtk_list_store_new (COLUMNS, G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING);


f=fopen("reclamation.txt","r");

if (f==NULL) {	return;}

else{
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",id,nom,prenom,cin_ou_passeport,classe,date_rec,details_reclamation,departement)!=EOF)

{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EID, id,ENOM, nom,EPRENOM, prenom,ECIN, cin_ou_passeport,ECLASSE, classe,EDATE, date_rec,ERECLAMATION, details_reclamation,departement, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}

}



		//recherche
void recherche_treev(GtkWidget *liste, char id_rech[20])
{GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;
 FILE *f;
char id[20];
char nom[20];
char prenom[20];
char cin_ou_passeport[20];
char classe[10];
char date_rec[20];
char details_reclamation[1000]; 
char departement[20];
store=NULL;

store=gtk_tree_view_get_model(liste);

if(store==NULL){

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("id",renderer, "text", EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("nom",renderer, "text", ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("prenom",renderer, "text", EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("cin",renderer, "text", ECIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("classe",renderer, "text", ECLASSE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("date",renderer, "text", EDATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("reclamation",renderer, "text", ERECLAMATION, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("departement",renderer, "text", EDEPARTEMENT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
}

store= gtk_list_store_new (COLUMNS, G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING);


f=fopen("reclamation.txt","r");

if (f==NULL) {	return;}

else{
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",id,nom,prenom,cin_ou_passeport,classe,date_rec,details_reclamation,departement)!=EOF)

{ if (!(strcmp (id, id_rech))){
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EID, id,ENOM, nom,EPRENOM, prenom,ECIN, cin_ou_passeport,ECLASSE, classe,EDATE, date_rec,ERECLAMATION, details_reclamation,departement, -1);
	}}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);
}

}

