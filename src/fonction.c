#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fonction.h"
#include <gtk/gtk.h>
enum
{
	JOUR,
	TEMPS,
	ENTREE,
	PLAT_PRINCIPALE,
	DESSERT,
	DECHETS,
	COLUMNS
};

///////////////////////////////////////////////////////////////////////
int verif_user(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}

///////////////////////////////////////////////////////////////

/*
int verif(menu m,char nom_fichier[])
{
FILE *f=NULL;
        char ch1[200],ch2[200],ch3[200],ch4[200];
        int a,b,test=1;
        strcpy(nom_fichier,"menu.txt");
        f=fopen(nom_fichier,"r");
        if(f!=NULL)
        {

            while(fscanf(f,"%s %d %s %s %s %d\n",ch1,&a,ch2,ch3,ch4,&b)!=EOF)
            {
                 if (strcmp(m.jour,ch1)==0&&m.temps==a&&strcmp(m.entree,ch2)==0&&strcmp(m.plat_principale,ch3)==0&&strcmp(m.dessert,ch4)==0&&m.dechets==b)
{
test=0;
}
            }
        }

        fclose(f);
return test;
    }
*/


//////////////////////////////////////////////////////////////////
void ajout_menu(menu m)
{
FILE *f;
f=fopen("menu.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %d %s %s %s %d\n",m.jour,m.temps,m.entree,m.plat_principale,m.dessert,m.dechets);
fclose(f);
}
}

/*
printf("call successful");
    FILE *f;

f=fopen("menu.txt","a+");
printf("opening file success");
if(verif(m,"menu.txt")==0)
{
printf("start of boucle");
fprintf(f,"%s %d %s %s %s %d \n", m.jour, m.temps, m.entree, m.plat_principale, m.dessert, m.dechets);
fclose(f);
}
}

////////////////////////////
do
{
    printf(" donner le jour,le temps,l'entree,le plat principale,le dessert et le dechets\n");
    scanf("%s %d %s %s %s %d",m.jour,&m.temps,m.menu.entree,m.menu.plat_principale,m.menu.dessert,&m.dechets );
}while(verif(m,nom_fichier)==0);
    strcpy(nom_fichier,"menu.txt");
    f=fopen(nom_fichier,"a");
    fprintf(f,"%s %d %s %s %s %d \n",m.jour,m.temps,m.entree,m.plat_principale,m.dessert,m.dechets  );
    fclose(f);*/




/////////////////////////////////////////////////////////////////////////////
/*
void modifier_menu(char jour[],int temps)
     {
        FILE *f=NULL;
        FILE *mo=NULL;
        menu m;
        char ch1[200],ch2[200],ch3[200],ch4[200];
        int a,b,test=0;
        f=fopen("menu.txt","r");
        mo=fopen("mod.txt","a");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %d %s %s %s %d \n",ch1,&a,ch2,ch3,ch4,&b)!=EOF)
            {

                if (strcmp(ch1,jour)!=0||a!=temps)
                {
                    fprintf(mo,"%s %d %s %s %s %d \n",ch1,a,ch2,ch3,ch4,b);
                }
                else
                {
		   test=1;
 		   printf(" donner le jour,le temps,l'entree,le plat principale,le dessert et le dechets\n");
                   scanf("%s %d %s %s %s %d",m.jour,&m.temps,m.entree,m.plat_principale,m.dessert,&m.dechets );
                   fprintf(mo,"%s %d %s %s %s %d\n",m.jour,m.temps,m.dessert,m.entree,m.plat_principale,m.dechets );
                }
            }
        }

        fclose(f);
        fclose(mo);
        remove("menu.txt");
        rename("mod.txt","menu.txt");
if (test==0)
{
printf("le menu n'existe pas\n");
}
     }
*/
///////////////////////////////////////////////
void modifier_menu(menu m)
{
menu m2;
int error=0;
FILE *f=NULL;
FILE *F=NULL;
f=fopen("menu.txt","a+");
F=fopen("tempo.txt","a+");
if (f!=NULL&&F!=NULL)
{
do
{
fscanf(f,"%s %d %s %s %s %d\n",&m2.jour,&m2.temps,&m2.entree,&m2.plat_principale,&m2.dessert,&m2.dechets);
if((strcmp(m2.jour,m.jour)==0)&&(strcmp(m2.temps,m.temps)==0))
{
strcpy(m2.entree,m.entree);
strcpy(m2.plat_principale,m.plat_principale);
strcpy(m2.dessert,m.dessert);

}

fprintf(F,"%s %d %s %s %s %d\n",m2.jour,m2.temps,m2.entree,m2.plat_principale,m2.dessert,m2.dechets);
}
while(!feof(f));
fclose(f);
fclose(F);
remove("menu.txt");
rename("tempo.txt","menu.txt");

}
else
{error=1;}}



/////////////////////////////////////////////////////////////////////////////
menu rechercher_menu(char jour[],int temps) 
    {
        FILE *f=NULL;
        menu m;
        char ch1[200],ch2[200],ch3[200],ch4[200]; 
        int a,b;
        f=fopen("menu.txt","r");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %d %s %s %s %d \n",ch1,&a,ch2,ch3,ch4,&b)!=EOF)



                if (strcmp(ch1,jour)==0 && a==temps)
                {
                    strcpy(m.jour,ch1);
                    m.temps=a;
                    strcpy(m.entree,ch2);
                    strcpy(m.plat_principale,ch3);
                    strcpy(m.dessert,ch4);
                    m.dechets=b;
            }
        }
         fclose(f);
return m;
/*
char ch[50];
strcpy(ch,m.jour);
strcat(ch," ");

sprint(ch, "%d", m.temps);
strcat(ch,m.jour);
strcat(ch," ");
*/


         

    }





/////////////////////////////////////////////////////////////////////////////
/*
void affichermenu(GtkWidget *liste){


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char jour[20];
	int  temps;
	char entree[50];
	char plat_principale[50];
	char dessert[50];
	int dechets;
	store =NULL;
	
	FILE *f;

	store =gtk_tree_view_get_model(liste);
	
	if (store==NULL)
	{
		

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_V 11111111111111111111111111111111111111111111111111111111111111111111 11111111||
			while(fscanf(f,"%s %d %s %s %s %d \n",jour,temps,entree,plat_principale,dessert,dechets)!=EOF)
		{
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter, EJOUR, jour, ETEMPS, temps, EENTREE, entree, EPLAT, plat_principale, EDESSERT,  dessert, EDECHETS, dechets, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
	}
*/

void affichermenu (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char jour[20];
	int  temps;
	char entree[50];
	char plat_principale[50];
	char dessert[50];
	int dechets;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("temps",renderer,"text",TEMPS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("entree",renderer,"text",ENTREE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("plat_principale",renderer,"text",PLAT_PRINCIPALE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",DESSERT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("dechets",renderer,"text",DECHETS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
		

	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	
	f=fopen("menu.txt","a+");
	if (f==NULL){
	return;}
	else
	{f=fopen("menu.txt","a+");
			while(fscanf(f,"%s %d %s %s %s %d\n",&jour,&temps,&entree,&plat_principale,&dessert,&dechets)!=EOF)
		{
	gtk_list_store_append (store,&iter);

	gtk_list_store_set (store ,&iter, JOUR, jour, TEMPS, temps, ENTREE, entree, PLAT_PRINCIPALE, plat_principale, DESSERT, dessert, DECHETS, dechets, -1);
	
		}
		fclose(f);
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}

   /////////////////////////////////////////////////////////////////////////////
void supprimer_menu(char jour[],int temps)
    {
	char ch1[50],ch2[50],ch3[50],ch4[50];
        FILE *f, *s;
        int a,b,x,test=0;
        f=fopen("menu.txt","r");
        s=fopen("sup.txt","w");
        if(f!=NULL)
        {//if
            while(fscanf(f,"%s %d %s %s %s %d \n",ch1,&a,ch2,ch3,ch4,&b)!=EOF)
            {//while
		if (strcmp(ch1,jour)!=0||a!=temps)
	{
                    fprintf(s,"%s %d %s %s %s %d \n",ch1,a,ch2,ch3,ch4,b);
	}
		

            }//while
        }//if

        fclose(f);
        fclose(s);
        remove("menu.txt");
        rename("sup.txt","menu.txt");

    }





/////////////////////////////////////////////////////////////////////////////
void meilleur_menu(char best1[], char best2[],char best3[],char best4[])
    {
    FILE *f=NULL;
    int jour;
    int temps;
    int dechets;

    int dechetsjour, i, n=24,j;
    int tab[50];
int tab2[50];
    f=fopen("dechets.txt","r");
    if (f!=NULL)
    {
        for(j=0;j<n;j++)
        {
            for (i=0; i<3; i++)
            {
                fscanf(f,"%d %d %d \n",&jour, &temps, &dechets);
                dechetsjour += dechets;
            }
            tab[j]=dechetsjour;
		tab2[j]=jour;
        }

        //tri decroissant

        int tmp=0, tmp2=0;
        for(n=24;n!=0; n--)
        {
        for(i=0;i<n; i++)
            {
            if(tab[i]<tab[i+1])
                {
                tmp=tab[i];
		tmp2=tab2[i];
                tab[i]=tab[i+1];
		tab2[i]=tab2[i+1];
                tab[i+1]=tmp;
		tab2[i+1]=tmp2;
                }
            }
       	}
sprintf(best1, "%d",tab2[23]);
sprintf(best2, "%d",tab2[22]);
sprintf(best3, "%d",tab2[21]);
sprintf(best4, "%d",tab2[20]);

fclose(f);
    }else {printf("Fichier texte introuvable.");}
	
    }


/*

char dump23[20];
sprintf(dump23, "%d",tab[23]);
strcpy(text,dump23);
strcat(text," ");

char dump22[20];
sprintf(dump22, "%d",tab[22]);
strcat(text,dump22);
strcat(text," ");

char dump21[20];
sprintf(dump21, "%d",tab[21]);
strcat(text,dump21);
strcat(text," ");

char dump20[20];
sprintf(dump20, "%d",tab[20]);
strcat(text,dump20);
*/
    

/////////////////////////////////////////////////////////////////////////////
/*
void choix_temps(int choix,int temps)
{
if (choix ==1)
	temps=7;
if (choix ==2)
	temps=12;
if (choix ==3)
	temps=18;
}
*/

////////////////////////////////////////////////////////////////////////////

void vider_menu(GtkWidget*liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char jour[20];
int  temps;
char entree[50];
char plat_principale[50];
char dessert[50];
int dechets;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", JOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("temps", renderer, "text", TEMPS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree", renderer, "text", ENTREE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("plat_principale", renderer, "text", PLAT_PRINCIPALE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert", renderer, "text", DESSERT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dechets", renderer, "text", DECHETS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store =gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
gtk_list_store_append (store, &iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

}
 
////////////////////////////////////////////////////////
void Resultat(char jour[],int temps,char texte[])
{
menu m;
m=rechercher_menu(jour, temps);
strcpy(texte,m.jour);
strcat(texte," ");
char tmp1[20];
sprintf(tmp1, "%d", m.temps);
strcat(texte,tmp1);
strcat(texte," ");
strcat(texte,m.entree);
strcat(texte," ");
strcat(texte,m.plat_principale);
strcat(texte," ");
strcat(texte,m.dessert);
strcat(texte," ");
char tmp2[20];
sprintf(tmp2, "%d", m.temps);
strcat(texte,tmp2);

}


















