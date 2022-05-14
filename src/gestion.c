#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "gestion.h"
#include<gtk/gtk.h>

enum{
ID,TYPE,ETAGE,BLOC,VALMIN,VALMAX,ETAT,COLUMNS};




void ajoutcap(capteur c)
{
int error=0;
FILE *f=NULL;
f=fopen("data.txt","a");
if (f!=NULL)
{
c.etat=1;
fprintf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",c.id,c.type,c.etage,c.bloc,c.valmin,c.valmax,c.etat);
fclose(f);}
else
{
error=1;
}
}







void modifcap(capteur c)
{
capteur s;
int error=0;
FILE *f=NULL;
FILE *F=NULL;
f=fopen("data.txt","a+");
F=fopen("tempo.txt","a+");
if (f!=NULL&&F!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&s.id,&s.type,&s.etage,&s.bloc,&s.valmin,&s.valmax,&s.etat);
if(strcmp(s.id,c.id)==0)
{
strcpy(s.type,c.type);
s.etage=c.etage;
strcpy(s.bloc,c.bloc);
s.valmin=c.valmin;
s.valmax=c.valmax;
s.etat=c.etat;

}

fprintf(F,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",s.id,s.type,s.etage,s.bloc,s.valmin,s.valmax,s.etat);
}
while(!feof(f));
fclose(f);
fclose(F);
remove("data.txt");
rename("tempo.txt","data.txt");

}
else
{error=1;}}





void suppcap(capteur c)
{
capteur s;
int error=0;
FILE *f=NULL;
FILE *F=NULL;
f=fopen("data.txt","a+");
F=fopen("temp.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&s.id,&s.type,&s.etage,&s.bloc,&s.valmin,&s.valmax,&s.etat);
if(strcmp(s.id,c.id)!=0)
{
fprintf(F,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",s.id,s.type,s.etage,s.bloc,s.valmin,s.valmax,s.etat);
}

}
while(!feof(f));
fclose(f);
fclose(F);
remove("data.txt");
rename("temp.txt","data.txt");

}
else
{error=1;}}


void recherchcap(capteur c)
{
capteur s;
int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("data.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&s.id,&s.type,&s.etage,&s.bloc,&s.valmin,&s.valmax,&s.etat);
if(strcmp(s.id,c.id)==0)
{
strcpy(c.type,s.type);
c.etage=s.etage;
strcpy(c.bloc,s.bloc);
c.valmin=s.valmin;
c.valmax=s.valmax;
c.etat=s.etat;
trouve=1;
}

}
while(!feof(f)||trouve==0);

if (trouve==0)
{error=2;}
fclose(f);
}
else
{error=1;}
}


void affichcap (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[20];
	char type[20];
	int etage;
	char bloc[10];
	int valmin;
	int valmax;
	int etat;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("bloc",renderer,"text",BLOC,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("valmin",renderer,"text",VALMIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("valmax",renderer,"text",VALMAX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	
	f=fopen("data.txt","a+");
	if (f==NULL){
	return;}
	else
	{f=fopen("data.txt","a+");
			while(fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&id,&type,&etage,&bloc,&valmin,&valmax,&etat)!=EOF)
		{
	gtk_list_store_append (store,&iter);

	gtk_list_store_set (store ,&iter, ID, id, TYPE, type, ETAGE, etage, BLOC, bloc, VALMIN, valmin, VALMAX, valmax, ETAT, etat, -1);
	
		}
		fclose(f);
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}


void vidercap (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[20];
	char type[20];
	int etage;
	char bloc[10];
	int valmin;
	int valmax;
	int etat;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("bloc",renderer,"text",BLOC,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("valmin",renderer,"text",VALMIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("valmax",renderer,"text",VALMAX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	gtk_list_store_append(store, &iter);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
  //g_object_unref (store);

}


void defect (capteur c,capteur T[])
{
int error=0;
int nb=0,i=0;
FILE *f=NULL;
f=fopen("data.txt","a+");
if (f!=NULL)
{
printf("capteurs defectueux \n");
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&c.id,&c.type,&c.etage,&c.bloc,&c.valmin,&c.valmax,&c.etat);
if(c.etat==0)
{
T[i]=c;
i++;
nb++;
}

}
while(!feof(f));
if (nb==0)
{printf("aucun capteur defectueux ! ");}
fclose(f);
}
else
{error=1;}}







void ajoutuser (appuser u)
{
int error=0;
FILE *f=NULL;
f=fopen("users.txt","a");
if (f!=NULL)
{
fprintf(f,"%s \t %s \t %s \n",u.uname,u.pw,u.idesprit);
fclose(f);}
else
{
error=1;
}
}


