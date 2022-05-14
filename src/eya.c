
#include <string.h>
#include "eya.h"
#include <stdio.h>
enum A
{
CIN,FIRSTNAME,LASTNAME,ADRESS,PHONE,EMAIL,PASSWORD,COLUMNS
};
enum B{
	JOUR,
	HEURE,
	NUM,
	VAL,
	CCOLUMNS
};
void add_etudiant (eya e){
  FILE* f = fopen("db_etudiant.txt","a+");
  fprintf (f,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password);
  fclose (f);
}


void aff_etudiant (GtkWidget* list,char ch[]){
  GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;
  eya e ;
  store = NULL;

  FILE *f;
  store = gtk_tree_view_get_model(list);

  if (store==NULL)
  {
    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" PRENOM",renderer,"text",FIRSTNAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" NOM",renderer,"text",LASTNAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" ADRESSE",renderer,"text",ADRESS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" TELEPHONE",renderer,"text",PHONE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" EMAIL",renderer,"text",EMAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" MOTDEPASSE",renderer,"text",PASSWORD,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f = fopen(ch,"r");

    if (f==NULL)
    {
      return;
    }
    else{
      f = fopen(ch,"a+");
      while (fscanf(f,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password)!=EOF){
        gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,CIN,e.cin,FIRSTNAME,e.firstname,LASTNAME,e.lastname,ADRESS,e.adress,PHONE,e.phone,EMAIL,e.email,PASSWORD,e.password, -1);

      }
      fclose(f);
      gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
		  g_object_unref(store);

    }
  }




}


int del_etudiant (char cin[10])
{
  eya e ,e1;
  FILE *f ,*fcpy;

    f = fopen ("db_etudiant.txt","a+");
    fcpy = fopen ("db_etudiantcpy.txt","a+");
    while (fscanf(f,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password)!=EOF){
      if (strcmp(cin,e.cin) != 0){
        fprintf (fcpy,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password);
      }
    }

  fclose(f);
  fclose(fcpy);

  remove("db_etudiant.txt");
  rename("db_etudiantcpy.txt","db_etudiant.txt");
  return 1 ;
}



void upd_etudiant (eya e1){
  eya e;
  FILE *f ,*fcpy;
  f = fopen ("db_etudiant.txt","a+");
  fcpy = fopen ("db_etudiantcpy.txt","a++");
  while (fscanf(f,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password)!=EOF){
    if (strcmp(e1.cin , e.cin)==0){
      fprintf (fcpy,"%s %s %s %s %s %s %s \n",e1.cin,e1.firstname,e1.lastname,e1.adress,e1.phone,e1.email,e1.password);
    }
    else {

    fprintf (fcpy,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password);
  }

  }
  fclose (f);
  fclose (fcpy);
  remove("db_etudiant.txt");
  rename("db_etudiantcpy.txt","db_etudiant.txt");

}
int check_etudiant (char cin []){

  eya e;
  FILE *f ;
 
  int R = 0;
  f = fopen ("db_etudiant.txt","a+");
  while (fscanf(f,"%s %s %s %s %s %s %s \n",e.cin,e.firstname,e.lastname,e.adress,e.phone,e.email,e.password)!=EOF){
    if (strcmp(e.cin , cin)){
      R=1;
      return R ;
    }
  }
  fclose (f);
  return R;
}
void affiche_alarm(GtkWidget* liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  capt c;
  store=NULL;
  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

 	 renderer = gtk_cell_renderer_text_new ();
 	 column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
  	 gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new ();
  	column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",HEURE,NULL);
  	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new ();
 	 column = gtk_tree_view_column_new_with_attributes("numero",renderer,"text",NUM,NULL);
  	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new ();
  	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VAL,NULL);
  	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

    }
store =gtk_list_store_new(CCOLUMNS, G_TYPE_INT,G_TYPE_INT, G_TYPE_INT,G_TYPE_INT);

f=fopen("alarme.txt","r");
	if (f==NULL) 
	{
	return;
	}
	else 
	{
	  
	  while (fscanf(f,"%d %d %d %d\n",&c.jour,&c.heure,&c.num,&c.val)!=EOF)
	  {
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,JOUR,c.jour,HEURE,c.heure,NUM,c.num,VAL,c.val,-1);
	  }
	  fclose(f);
	  gtk_tree_view_set_model(GTK_TREE_VIEW(liste) , GTK_TREE_MODEL(store));
	  g_object_unref(store);
	}
}
void alarme(){
	FILE *f,*g,*h;
	capt c;
	f=fopen("mouvement.txt","r");
	g=fopen("fumee.txt","r");
	h=fopen("alarme.txt","a+");
	if(f!=NULL && g!=NULL && h!=NULL){
		while(fscanf(f,"%d %d %d %d\n",&c.jour,&c.heure,&c.num,&c.val)!=EOF){
			if((c.heure>=0 && c.heure<=6 && c.val==1 )||(c.heure==24 && c.val==1)){
				fprintf(h,"%d %d %d %d\n",c.jour,c.heure,c.num,c.val);
			}
		}
		while(fscanf(g,"%d %d %d %d",&c.jour,&c.heure,&c.num,&c.val)!=EOF){
			if((c.heure>=0 && c.heure<=6 && c.val==1 )||(c.heure==24 && c.val==1)){
				fprintf(h,"%d %d %d %d\n",c.jour,c.heure,c.num,c.val);
			}
		}
	}
	fclose(f);
	fclose(g);
	fclose(h);
}




