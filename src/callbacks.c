#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "gestion.h"
#include "eya.h"
#include "wael.h"
#include "file.h"
#include "stock.h"



int a=7, b=7, c=7, d=7, e=0, z=7;
char k[8];

//////////////////////////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* jour;
gint* temps;
gchar* entree;
gchar* plat_principale;
gchar* dessert;
gint* dechets;
menu m;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path)) {

gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &jour, 1,&temps,2, &entree, 3, &plat_principale, 4, &dessert, 5, &dechets, -1);

strcpy(m.jour, jour);
m.temps=temps;
strcpy(m.entree, entree);
strcpy(m.plat_principale, plat_principale);
strcpy(m.dessert, dessert);
m.dechets=dechets;
supprimer_menu(m.jour,m.temps);
affichermenu(treeview);

}
}

//////////////////////////////////////////////////////////////////////
void
on_button3_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *newmodifwindow, *window2_aff;
window2_aff=lookup_widget(objet,"window2_aff");
gtk_widget_destroy(window2_aff);
newmodifwindow=lookup_widget(objet,"newmodifwindow");
newmodifwindow=create_newmodifwindow();
gtk_widget_show (newmodifwindow);

/*
GtkWidget *window2_aff, *window3_ajout, *treeview1, *jour, *temps, *entree, *plat_principale, *dessert, *dechets;
GtkTreeModel *model;
GtkTreeSelection *selection;
GtkTreeIter iter;
gchar *jour, *entree, *plat_principale, *dessert;
gint temps, dechets;
window2_aff=lookup_widget(objet,"window2_aff");
treeview1=lookup_widget(window2_aff,"treeview1");
selection=gtk=tree_view_get_selection(GTK_TREE_VIEW(treeview1));
if (gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(model,&iter,0,&jour,1,&temps,2,&entree,3,&plat_principal,4,&dessert,5,&dechets,-1);
gtk_widget_destroy(window2_aff);
window3_ajout=lookup_widget(objet,"window3_ajout");
window3_ajout=create_window3_ajout();
gtk_widget_show(window3_ajout);

jour=lookup_widget(window3_ajout,"comboboxentry1");
gtk_entry
}
*/

}

//////////////////////////////////////////////////////////////////////

void
on_button2_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window2_aff;
GtkWidget *window3_ajout;
window2_aff=lookup_widget(objet,"window2_aff");
gtk_widget_destroy(window2_aff);
window3_ajout=lookup_widget(objet,"window3_ajout");
window3_ajout=create_window3_ajout();

gtk_widget_show(window3_ajout);

}

////////////////////////////////////////////////////////////////////
void
on_button6_retour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5_dashboard, *window2_aff;
window2_aff=lookup_widget(objet,"window2_aff");
gtk_widget_destroy(window2_aff);
window5_dashboard=lookup_widget(objet,"window5_dashboard");
window5_dashboard=create_window5_dashboard();


gtk_widget_show (window5_dashboard);
}

//////////////////////////////////////////////////////////////////////


void
on_button7_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu m;

GtkWidget *Jour, *Temps, *Entree, *Plat_principale, *Dessert, *Dechets;
GtkWidget *fenetre_ajout, *window2_aff;


Jour=lookup_widget(objet,"comboboxentry1");
Entree=lookup_widget(objet,"entry3");
Plat_principale=lookup_widget(objet,"entry4");
Dessert=lookup_widget(objet,"entry5");
Dechets=lookup_widget(objet,"spinbutton1");



strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Jour)));
strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(Entree)));
strcpy(m.plat_principale, gtk_entry_get_text(GTK_ENTRY(Plat_principale)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(Dessert)));
m.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Dechets));

m.temps=a;

ajout_menu(m);

fenetre_ajout=lookup_widget(objet,"window3_ajout");
gtk_widget_destroy(fenetre_ajout);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();
gtk_widget_show(window2_aff);


}

//////////////////////////////////////////////////////////////////////


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		a=7;
}

//////////////////////////////////////////////////////////////////////
void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		a=12;
}

//////////////////////////////////////////////////////////////////////
void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		a=18;
}

//////////////////////////////////////////////////////////////////////
void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		b=7;
}

//////////////////////////////////////////////////////////////////////
void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		b=12;
}

//////////////////////////////////////////////////////////////////////
void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		b=18;
}


//////////////////////////////////////////////////////////////////////
void
on_button9_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window5_dashboard;
	GtkWidget *window2_aff;
	GtkWidget *treeview;
	

	window5_dashboard=lookup_widget(objet,"window5_dashboard");

	gtk_widget_destroy(window5_dashboard);
	window2_aff=lookup_widget(objet,"window2_aff");
	window2_aff = create_window2_aff();
	gtk_widget_show(window2_aff);
	treeview=lookup_widget(window2_aff,"treeview1");
	affichermenu(treeview);
}

//////////////////////////////////////////////////////////////////////
void
on_button10_rech_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5_dashboard, *window6_rech;
window5_dashboard=lookup_widget(objet,"window5_dashboard");
gtk_widget_destroy(window5_dashboard);
window6_rech=lookup_widget(objet,"window6_rech");
window6_rech=create_window6_rech();

gtk_widget_show (window6_rech);
}

//////////////////////////////////////////////////////////////////////
void
on_button11_gen_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
//char text[100]="";
char best1[10];
char best2[10];
char best3[10];
char best4[10];
GtkWidget *output1, *window5_dashboard, *output2, *output3, *output4;

meilleur_menu(best1, best2, best3, best4);
window5_dashboard=lookup_widget(objet,"window5_dashboard");
output1=lookup_widget(window5_dashboard,"label_best1");
gtk_label_set_text(GTK_LABEL(output1),best1);
gtk_widget_show(output1);

output2=lookup_widget(window5_dashboard,"label_best1");
gtk_label_set_text(GTK_LABEL(output2),best2);
gtk_widget_show(output2);

output3=lookup_widget(window5_dashboard,"label_best1");
gtk_label_set_text(GTK_LABEL(output3),best3);
gtk_widget_show(output3);

output4=lookup_widget(window5_dashboard,"label_best1");
gtk_label_set_text(GTK_LABEL(output4),best4);
gtk_widget_show(output4);
}

//////////////////////////////////////////////////////////////////////
void
on_button12_close_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5_dashboard, *window6_rech;
window6_rech=lookup_widget(objet,"window6_rech");
gtk_widget_destroy(window6_rech);
window5_dashboard=lookup_widget(objet,"window5_dashboard");
window5_dashboard=create_window5_dashboard();

gtk_widget_show(window5_dashboard);

}

//////////////////////////////////////////////////////////////////////
void
on_button1_login_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *windowdash, *windowlogin;

 
char user[20];
char pasw[20];
int trouve;
username = lookup_widget (objet, "entry1");
password = lookup_widget (objet, "entry2");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif_user(user,pasw);

if(trouve==1)
{
windowdash=create_window5_dashboard();
gtk_widget_show (windowdash);
windowlogin=lookup_widget(objet,"window1_login");
gtk_widget_destroy(windowlogin);
}
}

////////////////////////////////////////////////////////////////////
void
on_button9_actualiser_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_aff, *w1;
GtkWidget *treeview;
w1=lookup_widget(objet,"window2_aff");
fenetre_aff=create_window2_aff();
gtk_widget_show(fenetre_aff);
gtk_widget_hide(w1);
treeview=lookup_widget(fenetre_aff,"treeview1");
vider_menu(treeview);
affichermenu(treeview);
}



//////////////////////////////////////////////////////////////
void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		c=7;
}

//////////////////////////////////////////////////////////////
void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		c=12;
}

///////////////////////////////////////////////////////////
void
on_radiobutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		c=18;
}
///////////////////////////////////////////////////////////////////
void
on_button9_valider_rech_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
char texte[100]="";
GtkWidget* output, *Jour;
output=lookup_widget(objet,"label31_menurech");
int temps;
char jour[20];
Jour=lookup_widget(objet,"comboboxentry3");
strcpy(jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Jour)));
//choix_temps(choix, temps);
temps=c;
Resultat(jour, temps, texte);
gtk_label_set_text(GTK_LABEL(output),texte);	

}



void
on_button9_treeview_clicked																																																																										         (GtkWidget       *objet,
                                        gpointer         user_data)
{

/*
	GtkWidget *treeview1, *window2_aff;
	window2_aff=lookup_widget(objet,"window2_aff");


	treeview1=lookup_widget(window2_aff,"treeview1");

	afficher_menu(treeview1);
*/
}
/*
void
on_button_validermodif_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
printf("we r in");
GtkWidget *comboboxentry2;
GtkWidget *entry6;
GtkWidget *entry7;
GtkWidget *entry8;
GtkWidget *spinbutton2;
GtkWidget *window4_modif;
menu m, m1;

window4_modif=lookup_widget(objet,"window4_modif");
comboboxentry2=lookup_widget(objet,"comboboxentry2");
entry6=lookup_widget(objet,"entry6");
entry7=lookup_widget(objet,"entry7");
entry8=lookup_widget(objet,"entry8");
spinbutton2=lookup_widget (objet,"spinbutton2");


strcpy(m1.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
m1.temps=b;

int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("menu.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s %d %s %s %s %d\n",&m.jour,&m.temps,&m.entree,&m.plat_principale,&m.dessert,&m.dechets);
if((strcmp(m1.jour,m.jour)==0) && (strcmp(m1.temps,m.temps)==0))
{
strcpy(m1.entree,m.entree);
strcpy(m1.plat_principale,m.plat_principale);
strcpy(m1.dessert,m.dessert);

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
*/
/*
char Matrice[4][20]={"fumee","temperature","mouvement","debit"};
char Matricee[9][10]={"A","B","C","D","E","F","G","H","IJK"};

char type[20];
strcpy(type,c1.type);

char bloc[10];
strcpy(bloc,c1.bloc);

double etage;
etage=c1.etage;
double valmin;
valmin=c1.valmin;
double valmax;
valmax=c1.valmax;
int i=0;
int j=0;

while(i<4 && strcmp(Matrice[i],type)!=0)
{i++;}
while(j<9 && strcmp(Matricee[j],bloc)!=0)
{j++;}
*/
//
/*
char entr1[50];
strcpy(entr1,m.entree);
char plat1[50];
strcpy(plat1,m.plat_principale);
char dess1[50];
strcpy(dess1,m.dessert);
int dech1=m.dechets;


gtk_entry_set_text(GTK_ENTRY(entry6),entr1);
gtk_entry_set_text(GTK_ENTRY(entry7),plat1);
gtk_entry_set_text(GTK_ENTRY(entry8),dess1);
gtk_spin_button_set_value(spinbutton2,dech1);
/*
gtk_combo_box_set_active(GTK_COMBO_BOX (combobox1),i);
gtk_spin_button_set_value(petage,etage);
gtk_combo_box_set_active(GTK_COMBO_BOX (combobox2),j);
gtk_spin_button_set_value(pvalmin,valmin);
gtk_spin_button_set_value(pvalmax,valmax);
}
*/


/*
void
on_button_validermodif_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
char jour[50];
int temps;
GtkWidget *input1;
input1=lookup_widget(objet,"comboboxentry2");
strcpy(jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
temps=b;

menu m;
m=rechercher_menu(jour,temps);

GtkWidget *entry6;
//GtkWidget *window4_modif;
//window4_modif=lookup_widget(objet,"window4_modif");
entry6=lookup_widget(objet,"entry6");
gtk_entry_set_text(GTK_ENTRY(entry6),m.entree);

GtkWidget *entry7;
entry7=lookup_widget(objet,"entry7");
gtk_entry_set_text(GTK_ENTRY(entry7),m.plat_principale);

GtkWidget *entry8;
entry8=lookup_widget(objet,"entry8");
gtk_entry_set_text(GTK_ENTRY(entry8),m.dessert);

//GtkWidget *spinbutton2;



GtkWidget *entr;
entr=lookup_widget(objet,"entry6");
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(entr)));
GtkWidget *platp;
platp=lookup_widget(objet,"entry7");
strcpy(m.plat_principale,gtk_entry_get_text(GTK_ENTRY(platp)));
GtkWidget *dess;
dess=lookup_widget(objet,"entry8");
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(dess)));

GtkWidget *dech;
dech=lookup_widget(objet,"spinbutton2");
m.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dech));
modifier_menu(m);


}
*/

void
on_button8_modifmenu_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

/*
GtkWidget *comboboxentry2;
GtkWidget *entry6;
GtkWidget *entry7;
GtkWidget *entry8;
GtkWidget *spinbutton2;
GtkWidget *window4_modif;
menu m;


window4_modif=lookup_widget(objet,"window4_modif");


comboboxentry2=lookup_widget(objet,"comboboxentry2");


entry6=lookup_widget(objet,"entry6");


entry7=lookup_widget(objet,"entry7");


entry8=lookup_widget(objet,"entry8");


spinbutton2=lookup_widget (objet,"spinbutton2");


strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
m.temps=b;
strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(entry6)));
strcpy(m.plat_principale, gtk_entry_get_text(GTK_ENTRY(entry7)));
strcpy(m.dessert, gtk_entry_get_text(GTK_ENTRY(entry8)));
m.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton2));
printf("avant appel modif");
modifier_menu(m);
printf("apres appel modif");
*/
printf("inside modid");
menu m;

GtkWidget *Jour, *Temps, *Entree, *Plat_principale, *Dessert, *Dechets;
GtkWidget *window4_modif, *window2_aff;


Jour=lookup_widget(objet,"comboboxentry2");
Entree=lookup_widget(objet,"entry6");
Plat_principale=lookup_widget(objet,"entry7");
Dessert=lookup_widget(objet,"entry8");
Dechets=lookup_widget(objet,"spinbutton2");



strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Jour)));
strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(Entree)));
strcpy(m.plat_principale, gtk_entry_get_text(GTK_ENTRY(Plat_principale)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(Dessert)));
m.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Dechets));

m.temps=b;

modifier_menu(m);

window4_modif=lookup_widget(objet,"window4_modif");
gtk_widget_destroy(window4_modif);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();
gtk_widget_show(window2_aff);
}




void
on_button_suppri_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window7_supp, *window2_aff;
window2_aff=lookup_widget(objet,"window2_aff");
gtk_widget_destroy(window2_aff);

window7_supp=lookup_widget(objet,"window7_supp");
window7_supp=create_window7_supp();
gtk_widget_show(window7_supp);
}


void
on_radiobutton10_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		d=7;
}


void
on_radiobutton11_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		d=12;
}


void
on_radiobutton12_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		d=18;
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		e=1;
}


void
on_sbutton_supps_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
if (e==1)
{
char jour[50];
int temps;

GtkWidget *Jour, *Temps;
GtkWidget *window7_supp, *window2_aff;


Jour=lookup_widget(objet,"comboboxentry4");
strcpy(jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Jour)));

temps=d;
supprimer_menu(jour,temps);

window7_supp=lookup_widget(objet,"window7_supp");
gtk_widget_destroy(window7_supp);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();
gtk_widget_show(window2_aff);
}
else {
GtkWidget *window7_supp, *window2_aff;
window7_supp=lookup_widget(objet,"window7_supp");
gtk_widget_destroy(window7_supp);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();
gtk_widget_show(window2_aff);
}
}


void
on_new_modif_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

printf("inside modif");
menu m;

GtkWidget *Jour, *Temps, *Entree, *Plat_principale, *Dessert, *Dechets;
GtkWidget *window4_modif, *window2_aff;


Jour=lookup_widget(objet,"comboboxentry2");
Entree=lookup_widget(objet,"entry6");
Plat_principale=lookup_widget(objet,"entry7");
Dessert=lookup_widget(objet,"entry8");
Dechets=lookup_widget(objet,"spinbutton2");



strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Jour)));
strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(Entree)));
strcpy(m.plat_principale, gtk_entry_get_text(GTK_ENTRY(Plat_principale)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(Dessert)));
m.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Dechets));

m.temps=b;

modifier_menu(m);

window4_modif=lookup_widget(objet,"window4_modif");
gtk_widget_destroy(window4_modif);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();
gtk_widget_show(window2_aff);
}


void
on_modif_retour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2_aff, *window4_modif;
window4_modif=lookup_widget(objet,"window4_modif");
gtk_widget_destroy(window4_modif);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();

gtk_widget_show(window2_aff);
}


void
on_radiobutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		z=7;
}


void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		z=12;
}


void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		z=18;
}


void
on_sbutton2_modify_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu m;

GtkWidget *Jour, *Temps, *Entree, *Plat_principale, *Dessert, *Dechets;
GtkWidget *fenetre_ajout, *window2_aff;


Jour=lookup_widget(objet,"comboboxentry5");
Entree=lookup_widget(objet,"entry9_safa");
Plat_principale=lookup_widget(objet,"entry10_safa");
Dessert=lookup_widget(objet,"entry11_safa");
Dechets=lookup_widget(objet,"spinbutton3_safa");



strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Jour)));
strcpy(m.entree, gtk_entry_get_text(GTK_ENTRY(Entree)));
strcpy(m.plat_principale, gtk_entry_get_text(GTK_ENTRY(Plat_principale)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(Dessert)));
m.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Dechets));

m.temps=z;
printf("just before appel modif");
modifier_menu(m);
printf("after");
fenetre_ajout=lookup_widget(objet,"newmodifwindow");
gtk_widget_destroy(fenetre_ajout);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();
gtk_widget_show(window2_aff);

}


void
on_sbutton1_goback_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2_aff, *newmodifwindow;
newmodifwindow=lookup_widget(objet,"newmodifwindow");
gtk_widget_destroy(newmodifwindow);
window2_aff=lookup_widget(objet,"window2_aff");
window2_aff=create_window2_aff();

gtk_widget_show(window2_aff);
}
char supp[10];
char rech[10];
char supp1[10];
int cdefect=2;

///////////////////////////////////////////////////////////////////////////
////////////////////////    arij    ////////////////////////////////////

void
on_buttonAA_ajouter_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"EspaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"wajoutcap");
windowcree=create_wajoutcap();

gtk_widget_show(windowcree);
}


void
on_buttonAA_Modifier_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"EspaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"wmodcap");
windowcree=create_wmodcap();

gtk_widget_show(windowcree);
}


void
on_buttonAA_supprimer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;



windowcree=lookup_widget(objet,"wsuppcap1");
windowcree=create_wsuppcap1();

gtk_widget_show(windowcree);
}


void
on_buttonAA_rechercher_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"EspaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"wrechcap");
windowcree=create_wrechcap();

gtk_widget_show(windowcree);
}


void
on_buttonAA_Afficher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;
GtkWidget *treeview;

windowsupp=lookup_widget(objet,"EspaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"waffcap");
windowcree=create_waffcap();

gtk_widget_show(windowcree);
treeview=lookup_widget(windowcree,"treeviewAA");
affichcap(treeview);
}


void
on_buttonAA_ajoutajout_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *pid;
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *msg;
GtkWidget *WindowAjoutC;
capteur c;

WindowAjoutC=lookup_widget(objet,"wajoutcap");


pid=lookup_widget(objet,"entryAA_ida");


combobox1=lookup_widget(objet,"comboboxAA_typea");


petage=lookup_widget(objet,"spinbuttonAA_etagea");


combobox2=lookup_widget(objet,"comboboxAA_bloca");


pvalmin=lookup_widget (objet,"spinbuttonAA_valmina");


pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxa");


strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(pid)));

strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

c.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(petage));

strcpy(c.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

c.valmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmin));

c.valmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmax));
ajoutcap(c);
msg=lookup_widget(objet,"labelAA_ajouter");
gtk_label_set_text(GTK_LABEL(msg),"Capteur ajouté !");

}


void
on_buttonAA_retourajout_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wajoutcap");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);
}


void
on_buttonAA_validermod_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *pid;
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *WindowModC;
capteur c,c1;

WindowModC=lookup_widget(objet,"wmodcap");
pid=lookup_widget(objet,"entryAA_idm");
combobox1=lookup_widget(objet,"comboboxAA_typem");
petage=lookup_widget(objet,"spinbuttonAA_etagem");
combobox2=lookup_widget(objet,"comboboxAA_blocm");
pvalmin=lookup_widget (objet,"spinbuttonAA_valminm");
pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxm");
strcpy(c1.id,gtk_entry_get_text(GTK_ENTRY(pid)));

int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("data.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&c.id,&c.type,&c.etage,&c.bloc,&c.valmin,&c.valmax,&c.etat);
if(strcmp(c1.id,c.id)==0)
{
strcpy(c1.type,c.type);
c1.etage=c.etage;
strcpy(c1.bloc,c.bloc);
c1.valmin=c.valmin;
c1.valmax=c.valmax;
c1.etat=c.etat;
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

char Matrice[4][20]={"fumee","temperature","mouvement","debit"};
char Matricee[9][10]={"A","B","C","D","E","F","G","H","IJK"};

char type[20];
strcpy(type,c1.type);

char bloc[10];
strcpy(bloc,c1.bloc);

double etage;
etage=c1.etage;
double valmin;
valmin=c1.valmin;
double valmax;
valmax=c1.valmax;
int i=0;
int j=0;

while(i<4 && strcmp(Matrice[i],type)!=0)
{i++;}
while(j<9 && strcmp(Matricee[j],bloc)!=0)
{j++;}


gtk_combo_box_set_active(GTK_COMBO_BOX (combobox1),i);
gtk_spin_button_set_value(petage,etage);
gtk_combo_box_set_active(GTK_COMBO_BOX (combobox2),j);
gtk_spin_button_set_value(pvalmin,valmin);
gtk_spin_button_set_value(pvalmax,valmax);

}


void
on_buttonAA_modmod_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *pid;
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *msg;
GtkWidget *WindowModC;
capteur c;


WindowModC=lookup_widget(objet,"wmodcap");


pid=lookup_widget(objet,"entryAA_idm");


combobox1=lookup_widget(objet,"comboboxAA_typem");


petage=lookup_widget(objet,"spinbuttonAA_etagem");


combobox2=lookup_widget(objet,"comboboxAA_blocm");


pvalmin=lookup_widget (objet,"spinbuttonAA_valminm");


pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxm");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(pid)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

c.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(petage));

strcpy(c.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

c.valmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmin));

c.valmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmax));
c.etat=cdefect;
modifcap(c);
msg=lookup_widget(objet,"labelAA_modifier");
gtk_label_set_text(GTK_LABEL(msg),"Capteur modifié !");


}


void
on_buttonAA_retourmod_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wmodcap");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);
}


void
on_buttonAA_supp1_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;
GtkWidget *pid;

windowsupp=lookup_widget(objet,"wsuppcap1");
pid=lookup_widget(objet,"entryAA_ids");
strcpy(supp,gtk_entry_get_text(GTK_ENTRY(pid)));
gtk_widget_destroy(windowsupp);
windowcree=lookup_widget(objet,"wpopup");
windowcree=create_wpopup();

gtk_widget_show(windowcree);

}


void
on_buttonAA_annulers_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wsuppcap1");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);

}


void
on_buttonAA_nonsupp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wpopup");
gtk_widget_destroy(windowsupp);


}


void
on_buttonAA_ouisupp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *wpop;
GtkWidget *wok;
capteur c;


wpop=lookup_widget(objet,"wpopup");
gtk_widget_destroy(wpop);
strcpy(c.id,supp);
suppcap(c);

wok=lookup_widget(objet,"AAOK");
wok=create_AAOK();

gtk_widget_show(wok);


}


void
on_buttonAA_ok_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;
windowsupp=lookup_widget(objet,"AAOK");
gtk_widget_destroy(windowsupp);
windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);

}


void
on_buttonAA_validerrech_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *wr;
GtkWidget *pid;
capteur c,c1;

wr=lookup_widget(objet,"wrechcap");
pid=lookup_widget(objet,"entryAA_idr");
strcpy(rech,gtk_entry_get_text(GTK_ENTRY(pid)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("data.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&c.id,&c.type,&c.etage,&c.bloc,&c.valmin,&c.valmax,&c.etat);
if(strcmp(c.id,rech)==0)
{
strcpy(c1.id,rech);
strcpy(c1.type,c.type);
c1.etage=c.etage;
strcpy(c1.bloc,c.bloc);
c1.valmin=c.valmin;
c1.valmax=c.valmax;
c1.etat=c.etat;
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

wr=lookup_widget(objet,"wrechcap");
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *msg;

combobox1=lookup_widget(objet,"comboboxAA_typer");
petage=lookup_widget(objet,"spinbuttonAA_etager");
combobox2=lookup_widget(objet,"comboboxAA_blocr");
pvalmin=lookup_widget (objet,"spinbuttonAA_valminr");
pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxr");
msg=lookup_widget(objet,"labelAA_rech");

char Matrice[4][20]={"fumee","temperature","mouvement","debit"};
char Matricee[9][10]={"A","B","C","D","E","F","G","H","IJK"};


char type[20];
strcpy(type,c1.type);

char bloc[10];
strcpy(bloc,c1.bloc);

double etage;
etage=c1.etage;
double valmin;
valmin=c1.valmin;
double valmax;
valmax=c1.valmax;

int i=0;
int j=0;

while(i<4 && strcmp(Matrice[i],type)!=0)
{i++;}
while(j<9 && strcmp(Matricee[j],bloc)!=0)
{j++;}

gtk_combo_box_set_active(GTK_COMBO_BOX (combobox1),i);
gtk_spin_button_set_value(petage,etage);
gtk_combo_box_set_active(GTK_COMBO_BOX (combobox2),j);
gtk_spin_button_set_value(pvalmin,valmin);
gtk_spin_button_set_value(pvalmax,valmax);

if (c1.etat==1)
{gtk_label_set_text(GTK_LABEL(msg),"ce capteur est fonctionnant");}
if (c1.etat==0)
{gtk_label_set_text(GTK_LABEL(msg),"ce capteur est defectueux");}


}


void
on_buttonAA_retourrech_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wrechcap");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);
}


void
on_treeviewAA_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
	gchar* id;
	gchar* type;
	gint* etage;
	gchar* bloc;
	gint* valmin;
	gint* valmax;
	gint* etat;
	capteur c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if (gtk_tree_model_get_iter(model, &iter, path)) {

	gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &type, 2, &etage, 3, &bloc, 4, &valmin, 5, &valmax, 6, &etat,-1);
	strcpy(c.id,id);
	strcpy(c.type,type);
	strcpy(c.bloc,bloc);
	c.etage=etage;
	c.valmin=valmin;
	c.valmax=valmax;
	suppcap(c);
	affichcap (treeview);
	}

}


void
on_buttonAA_actualiser_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowaff,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"waffcap");
windowaff=create_waffcap();
gtk_widget_show(windowaff);

gtk_widget_hide (w1);
treeview1=lookup_widget(windowaff,"treeviewAA");
vidercap(treeview1);
affichcap(treeview1);

}


void
on_buttonAA_retouraff_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"waffcap");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);
}


void
on_buttonAA_ajoutaff_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;

windowcree=lookup_widget(objet,"wajoutcapaff");
windowcree=create_wajoutcapaff();

gtk_widget_show(windowcree);

}


void
on_buttonAA_modaff_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;

windowcree=lookup_widget(objet,"wmodcapaff");
windowcree=create_wmodcapaff();

gtk_widget_show(windowcree);

}


void
on_buttonAA_suppaff_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;

windowcree=lookup_widget(objet,"wsuppcapaff");
windowcree=create_wsuppcapaff();

gtk_widget_show(windowcree);
}


void
on_buttonAA_annuleraff_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wsuppcapaff");
gtk_widget_destroy(windowsupp);


}


void
on_buttonAA_supp1aff_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;
GtkWidget *pid;

windowsupp=lookup_widget(objet,"wsuppcapaff");
pid=lookup_widget(objet,"entryAA_idsaff");
strcpy(supp1,gtk_entry_get_text(GTK_ENTRY(pid)));
gtk_widget_destroy(windowsupp);
windowcree=lookup_widget(objet,"wpopupaff");
windowcree=create_wpopupaff();

gtk_widget_show(windowcree);
}


void
on_buttonAA_nonsuppaff_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wpopupaff");
gtk_widget_destroy(windowsupp);

}


void
on_buttonAA_ouisuppaff_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *wpop;
GtkWidget *wok;
capteur c;


wpop=lookup_widget(objet,"wpopupaff");
gtk_widget_destroy(wpop);
strcpy(c.id,supp1);
suppcap(c);

wok=lookup_widget(objet,"AAOKAFF");
wok=create_AAOKAFF();

gtk_widget_show(wok);
}


void
on_buttonAA_okaff_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;
windowsupp=lookup_widget(objet,"AAOKAFF");
gtk_widget_destroy(windowsupp);

}


void
on_buttonAA_ajoutfinaff_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pid;
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *msg;
GtkWidget *WindowAjoutC;
capteur c;

WindowAjoutC=lookup_widget(objet,"wajoutcapaff");


pid=lookup_widget(objet,"entryAA_idaaff");


combobox1=lookup_widget(objet,"comboboxAA_typeaaff");


petage=lookup_widget(objet,"spinbuttonAA_etageaaff");


combobox2=lookup_widget(objet,"comboboxAA_blocaaff");


pvalmin=lookup_widget (objet,"spinbuttonAA_valminaaff");


pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxaaff");


strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(pid)));

strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

c.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(petage));

strcpy(c.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

c.valmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmin));

c.valmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmax));
ajoutcap(c);
msg=lookup_widget(objet,"labelAA_ajouteraff");
gtk_label_set_text(GTK_LABEL(msg),"Capteur ajouté !");
}


void
on_buttonAA_retourajoutaff_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wajoutcapaff");
gtk_widget_destroy(windowsupp);


}


void
on_buttonAA_valmodaff_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *pid;
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *WindowModC;
capteur c,c1;

WindowModC=lookup_widget(objet,"wmodcapaff");
pid=lookup_widget(objet,"entryAA_idmaff");
combobox1=lookup_widget(objet,"comboboxAA_typemaff");
petage=lookup_widget(objet,"spinbuttonAA_etagemaff");
combobox2=lookup_widget(objet,"comboboxAA_blocmaff");
pvalmin=lookup_widget (objet,"spinbuttonAA_valminmaff");
pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxmaff");
strcpy(c1.id,gtk_entry_get_text(GTK_ENTRY(pid)));

int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("data.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %d \t %s \t %d \t %d \t %d \n",&c.id,&c.type,&c.etage,&c.bloc,&c.valmin,&c.valmax,&c.etat);
if(strcmp(c1.id,c.id)==0)
{
strcpy(c1.type,c.type);
c1.etage=c.etage;
strcpy(c1.bloc,c.bloc);
c1.valmin=c.valmin;
c1.valmax=c.valmax;
c1.etat=c.etat;
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

char Matrice[4][20]={"fumee","temperature","mouvement","debit"};
char Matricee[9][10]={"A","B","C","D","E","F","G","H","IJK"};

char type[20];
strcpy(type,c1.type);

char bloc[10];
strcpy(bloc,c1.bloc);

double etage;
etage=c1.etage;
double valmin;
valmin=c1.valmin;
double valmax;
valmax=c1.valmax;
int i=0;
int j=0;

while(i<4 && strcmp(Matrice[i],type)!=0)
{i++;}
while(j<9 && strcmp(Matricee[j],bloc)!=0)
{j++;}


gtk_combo_box_set_active(GTK_COMBO_BOX (combobox1),i);
gtk_spin_button_set_value(petage,etage);
gtk_combo_box_set_active(GTK_COMBO_BOX (combobox2),j);
gtk_spin_button_set_value(pvalmin,valmin);
gtk_spin_button_set_value(pvalmax,valmax);

}


void
on_buttonAA_modfinaff_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *pid;
GtkWidget *combobox1;
GtkWidget *petage;
GtkWidget *combobox2;
GtkWidget *pvalmin;
GtkWidget *pvalmax;
GtkWidget *msg;
GtkWidget *WindowModC;
capteur c;


WindowModC=lookup_widget(objet,"wmodcapaff");


pid=lookup_widget(objet,"entryAA_idmaff");


combobox1=lookup_widget(objet,"comboboxAA_typemaff");


petage=lookup_widget(objet,"spinbuttonAA_etagemaff");


combobox2=lookup_widget(objet,"comboboxAA_blocmaff");


pvalmin=lookup_widget (objet,"spinbuttonAA_valminmaff");


pvalmax=lookup_widget (objet,"spinbuttonAA_valmaxmaff");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(pid)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

c.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(petage));

strcpy(c.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

c.valmin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmin));

c.valmax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pvalmax));
c.etat=cdefect;
modifcap(c);
msg=lookup_widget(objet,"labelAA_modifieraff");
gtk_label_set_text(GTK_LABEL(msg),"Capteur modifié !");


}


void
on_buttonAA_retourmodaff_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"wmodcapaff");
gtk_widget_destroy(windowsupp);
}


void
on_radiobutton_nonmod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{cdefect=1;}
}


void
on_radiobutton_ouimod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{cdefect=0;}
}


void
on_radiobuttonAA_nonaff_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{cdefect=1;}
}


void
on_radiobutton_ouimaff_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{cdefect=0;}
}

///////////////////////////////////////////////////////////////////////
/////////////////////////////   eya    /////////////////////////////////

void
on_addReturn_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet_graphique, "Addetudiant");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet_graphique, "window_menu_eya");
affiche = create_window_menu_eya();
gtk_widget_show(affiche);

}


void
on_SUBMIT_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input;
eya e;

input = lookup_widget(objet_graphique, "entryCIN") ;
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(objet_graphique, "entryFIRSTNAME") ;
strcpy(e.firstname,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(objet_graphique, "entryLASTNAME") ;
strcpy(e.lastname,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(objet_graphique, "entryADRESS") ;
strcpy(e.adress,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(objet_graphique, "entryPHONE") ;
strcpy(e.phone,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(objet_graphique, "entryEMAIL") ;
strcpy(e.email,gtk_entry_get_text(GTK_ENTRY(input)));

input = lookup_widget(objet_graphique, "entryPASSWORD") ;
strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(input)));


add_etudiant (e);
}
void
on_delete_return_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget* affiche;
GtkWidget* DELETE;
DELETE = lookup_widget(objet_graphique, "DELETE");
gtk_widget_destroy(DELETE);
affiche = lookup_widget(objet_graphique, "window_menu_eya");
affiche = create_window_menu_eya();
gtk_widget_show(affiche);

}


void
on_buttonDELETE_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget* input;
  char cin[50];
  input = lookup_widget(objet_graphique, "entryCIN") ;
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
  if (check_etudiant(cin)==1){
    del_etudiant(cin);

  }
}

void
on_update_return_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* UPDATEetudiant;
UPDATEetudiant = lookup_widget(objet_graphique, "UPDATEetudiant");
gtk_widget_destroy(UPDATEetudiant);
affiche = lookup_widget(objet_graphique, "window_menu_eya");
affiche = create_window_menu_eya();
gtk_widget_show(affiche);
}



void
on_buttonUPD_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

  GtkWidget* input;
  eya e1;

  input = lookup_widget(objet_graphique, "entryCIN") ;
  strcpy(e1.cin,gtk_entry_get_text(GTK_ENTRY(input)));

  input = lookup_widget(objet_graphique, "entryFIRSTNAME") ;
  strcpy(e1.firstname,gtk_entry_get_text(GTK_ENTRY(input)));

  input = lookup_widget(objet_graphique, "entryLASTNAME") ;
  strcpy(e1.lastname,gtk_entry_get_text(GTK_ENTRY(input)));

  input = lookup_widget(objet_graphique, "entryADRESS") ;
  strcpy(e1.adress,gtk_entry_get_text(GTK_ENTRY(input)));

  input = lookup_widget(objet_graphique, "entryPHONE") ;
  strcpy(e1.phone,gtk_entry_get_text(GTK_ENTRY(input)));

  input = lookup_widget(objet_graphique, "entryEMAIL") ;
  strcpy(e1.email,gtk_entry_get_text(GTK_ENTRY(input)));

  input = lookup_widget(objet_graphique, "entryPASSWORD") ;
  strcpy(e1.password,gtk_entry_get_text(GTK_ENTRY(input)));

  upd_etudiant(e1);
}




void
on_buttonADD_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
affiche = lookup_widget(objet_graphique, "affiche");
gtk_widget_destroy(affiche);
addetudiant = lookup_widget(objet_graphique, "Addetudiant");
addetudiant = create_Addetudiant();
gtk_widget_show(addetudiant);

}


void
on_buttonUPDATE_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* UPDATEetudiant;
affiche = lookup_widget(objet_graphique, "affiche");
gtk_widget_destroy(affiche);
UPDATEetudiant = lookup_widget(objet_graphique, "UPDATEetudiant");
UPDATEetudiant = create_UPDATEetudiant();
gtk_widget_show(UPDATEetudiant);

}


void
on_buttonDLT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* DELETE;
affiche = lookup_widget(objet_graphique, "affiche");
gtk_widget_destroy(affiche);
DELETE = lookup_widget(objet_graphique, "DELETE");
DELETE = create_DELETE();
gtk_widget_show(DELETE);

}


void
on_buttonaffiche_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *affiche;
	GtkWidget *treevieweya;
	affiche = lookup_widget(objet_graphique,"affiche");

	treevieweya = lookup_widget(affiche,"treevieweya");

	aff_etudiant(treevieweya,"db_etudiant.txt");





}
 	

void
on_button1tache2_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* tache2;
GtkWidget* treeview2;
tache2 = lookup_widget(objet_graphique, "tache2");
affiche = lookup_widget(objet_graphique, "affiche");
gtk_widget_destroy(affiche);

tache2 = create_tache2();
gtk_widget_show(tache2);
alarme();
treeview2 = lookup_widget(tache2,"treeview2");
affiche_alarm(treeview2);
remove("alarme.txt");
}


void
on_button2retour_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* tache2;
tache2 = lookup_widget(objet_graphique, "tache2");
affiche = lookup_widget(objet_graphique, "affiche");
gtk_widget_destroy(tache2);

affiche = create_affiche();
gtk_widget_show(affiche);

}


void
on_treevieweya_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

//////////////////////////////////////////////////////////////////
//////////////////////////////   wael //////////////////////


void
on_button1_con_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*input2,*info2;
GtkWidget *fenetre_auth;
GtkWidget *fenetre_option;
char nomm[20];
char mdpp[20];
fenetre_auth=lookup_widget(objet,"window1_auth");
input1=lookup_widget(objet,"entry1_nomut");
input2=lookup_widget(objet,"entry2_mdp");
strcpy(nomm,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mdpp,gtk_entry_get_text(GTK_ENTRY(input2)));
if(strcmp(nomm,"agent")==0 && strcmp(mdpp,"0000")==0)
{
fenetre_option=lookup_widget(objet,"window2_opti");
fenetre_option=create_window2_opti();

gtk_widget_show(fenetre_option);}
else {info2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"identifiants erronés");
switch (gtk_dialog_run(GTK_DIALOG(info2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info2);
break;}}
}

/*
void
on_button2_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{




}
*/

void
on_button3_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_supp;
fenetre_option=lookup_widget(objet,"window2_opti");
gtk_widget_destroy(fenetre_option);

fenetre_supp=lookup_widget(objet,"window4_supp");
fenetre_supp=create_window4_supp();

gtk_widget_show(fenetre_supp);
}


void
on_button4_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_modif;
fenetre_option=lookup_widget(objet,"window2_opti");
gtk_widget_destroy(fenetre_option);

fenetre_modif=lookup_widget(objet,"window5_modif");
fenetre_modif=create_window5_modif();

gtk_widget_show(fenetre_modif);
}


void
on_button5_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;

fenetre_ajout=lookup_widget(objet,"window2_opti");
gtk_widget_destroy(fenetre_ajout);

fenetre_afficher=lookup_widget(objet,"tv");
fenetre_afficher=create_tv();

gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"treeview3");

affichereleve(treeview);

}


void
on_button6_rechercher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_rech;
fenetre_option=lookup_widget(objet,"window2_opti");
gtk_widget_destroy(fenetre_option);

fenetre_rech=lookup_widget(objet,"modif2");
fenetre_rech=create_modif2();

gtk_widget_show(fenetre_rech);
}

/*
void
on_button7_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{


}
*/

void
on_button8_mod_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
etudiant e;

GtkWidget *input1, *input2, *input3, *input4;
GtkWidget *fenetre_modif;

fenetre_modif==lookup_widget(objet,"window5_modif");

input1=lookup_widget(objet,"entry7_nom");
input2=lookup_widget(objet,"entry8_prenom");
input3=lookup_widget(objet,"entry9_wael");
input4=lookup_widget(objet,"spinbutton2_cin");

strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
e.niveau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
modifiereleve(e);
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	/*GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gint* cin;
	gint* niveau;
	etudiant e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if (gtk_tree_model_get_iter(model, &iter, path)) {

	gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &nom, 1, &prenom, 2, &cin, 3, &niveau, -1);
	strcpy(e.cin,cin);
	strcpy(e.nom,nom);
	strcpy(e.prenom,prenom);
	e.niveau=niveau;
	supprimereleve(cin);
	affichereleve(treeview);
	}






*/}


void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_ajout;
fenetre_option=lookup_widget(objet,"tv");
gtk_widget_destroy(fenetre_option);

fenetre_ajout=lookup_widget(objet,"window5_modif");
fenetre_ajout=create_window5_modif();

gtk_widget_show(fenetre_ajout);

}


void
on_supp_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_ajout;
fenetre_option=lookup_widget(objet,"tv");
gtk_widget_destroy(fenetre_option);

fenetre_ajout=lookup_widget(objet,"window4_supp");
fenetre_ajout=create_window4_supp();

gtk_widget_show(fenetre_ajout);
}


void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_ajout;
fenetre_option=lookup_widget(objet,"tv");
gtk_widget_destroy(fenetre_option);

fenetre_ajout=lookup_widget(objet,"window3_ajoutwael");
fenetre_ajout=create_window3_ajoutwael();

gtk_widget_show(fenetre_ajout);
}


void
on_button1_cher_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
char cin[8];
GtkWidget *input1;
GtkWidget *fenetre_rech;

fenetre_rech=lookup_widget(objet,"window1_rech");
input1=lookup_widget(objet,"entry6_cin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
rechercher(cin);
}

int choix1;
void
on_checkbutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix1=1;}
}


void
on_checkbutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix1=0;}
}


void
on_button_confirm_add                  (GtkContainer    *container,
                                        GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_button_confirm_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*info,*info1;
GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;

fenetre_confirm=lookup_widget(objet,"alerte");
fenetre_supp=lookup_widget(objet,"window4_supp");
if (choix1==1)
{
supprimereleve(k);
gtk_widget_destroy(fenetre_confirm);
info=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"eya supprimé!");
switch (gtk_dialog_run(GTK_DIALOG(info)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info);
break;
}
}
else
{
fenetre_supp=create_window4_supp();
info1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"eya non supprimé!");
switch (gtk_dialog_run(GTK_DIALOG(info1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info1);
break;
}

gtk_widget_show(fenetre_supp);
gtk_widget_destroy(fenetre_confirm);
}
}


void
on_back_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_mod2;
fenetre_mod2=lookup_widget(objet,"modif2");
fenetre_option=lookup_widget(objet,"window2_opti");

fenetre_option=create_window2_opti();

gtk_widget_show(fenetre_option);
}

void
on_alter1_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cin2,*info,*info2;

char cin1[20];
int test=0;
cin2 = lookup_widget (objet,"entry12");

strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin2)));
printf("\n%s",cin1);
/*GtkWidget *windowmodifier;*/
etudiant e2;

FILE *f,*g;
f=fopen("residents.txt","r");
g=fopen("tmp2.txt","w");
if ((f!=NULL) )
{
while (fscanf(f,"%s %s %s %d \n",e2.nom,e2.prenom,e2.cin,e2.niveau)!=EOF)
{
if (strcmp(cin1,e2.cin)==0)
{
test=1;
fprintf(g,"%s %s %s %d \n",e2.nom,e2.prenom,e2.cin,e2.niveau);
info=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"eya trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info);
break;
}
}



}
}
fclose(f);
fclose(g);



if (test==0)
{
info2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'etudiant avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(info2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info2);
break;

}
}
////// iniiiiiiiiiit

etudiant e3;
GtkWidget *nom,*prenom,*cin,*spin_niveau;
FILE *q=NULL;
q=fopen("tmp2.txt","r");
fscanf(q,"%s %s %s %d \n",e3.nom,e3.prenom,e3.cin,e3.niveau);
nom = lookup_widget (objet,"entry10");
gtk_entry_set_text(nom,e3.nom);
prenom = lookup_widget (objet,"entry11");
gtk_entry_set_text(prenom,e3.prenom);
cin = lookup_widget (objet,"entry12");
gtk_entry_set_text(cin,e3.cin);


spin_niveau=lookup_widget(objet,"spin_niv");
gtk_spin_button_set_value(spin_niveau,e3.niveau);
}





void
on_testrech_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cin2,*info,*info2;

char cin1[20];
int test=0;
cin2 = lookup_widget (objet,"entry12");

strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin2)));
printf("\n%s",cin1);
/*GtkWidget *windowmodifier;*/
etudiant e2;

FILE *f,*g;
f=fopen("residents.txt","r");
g=fopen("tmp2.txt","w");
if ((f!=NULL) )
{
while (fscanf(f,"%s %s %s %d \n",e2.nom,e2.prenom,e2.cin,&e2.niveau)!=EOF)
{
if (strcmp(cin1,e2.cin)==0)
{
test=1;
fprintf(g,"%s %s %s %d \n",e2.nom,e2.prenom,e2.cin,e2.niveau);
info=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"eya trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info);
break;
}
}



}
}
fclose(f);
fclose(g);



if (test==0)
{
info2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'etudiant avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(info2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info2);
break;

}
}
////// iniiiiiiiiiit

etudiant e3;
GtkWidget *nom,*prenom,*cin,*spin_niveau;
FILE *q=NULL;
q=fopen("tmp2.txt","r");
fscanf(q,"%s %s %s %d \n",e3.nom,e3.prenom,e3.cin,&e3.niveau);
nom = lookup_widget (objet,"entry10");
gtk_entry_set_text(nom,e3.nom);
prenom = lookup_widget (objet,"entry11");
gtk_entry_set_text(prenom,e3.prenom);
cin = lookup_widget (objet,"entry12");
gtk_entry_set_text(cin,e3.cin);


spin_niveau=lookup_widget(objet,"spin_niv");
gtk_spin_button_set_value(spin_niveau,e3.niveau);
}



void
on_buttondashwa_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_dash;
fenetre_option=lookup_widget(objet,"window2_opti");

fenetre_dash=lookup_widget(objet,"dashboardwa");
fenetre_dash=create_dashboardwa();

gtk_widget_show(fenetre_dash);
}


void
on_buttoncalwa_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
output = lookup_widget(objet,"labelcalcul");
etudiant e;
char a[5],b[5],h[5],l[5],m[5];
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
sprintf(a,"%d",p);
sprintf(b,"%d",d);
sprintf(h,"%d",t);
sprintf(l,"%d",q);
sprintf(m,"%d",c);
strcat(a," éléves de premiére année,");
strcat(b," éléves de deuxiéme année,");
strcat(h," éléves de troisiéme année,");
strcat(l," éléves de quatriéme année,");
strcat(m," éléves de cinqiéme année,");
strcat(a,b);
strcat(a,h);
strcat(a,l);
strcat(a,m);
gtk_label_set_text(GTK_LABEL(output),a);



}


void
on_button2_ajoutwael_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_option;
GtkWidget *fenetre_ajout;
fenetre_option=lookup_widget(objet,"window2_opti");
gtk_widget_destroy(fenetre_option);

fenetre_ajout=lookup_widget(objet,"window3_ajoutwael");
fenetre_ajout=create_window3_ajoutwael();

gtk_widget_show(fenetre_ajout);
}


void
on_button7_ajoutwael_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
printf("u clicked");
etudiant e;

GtkWidget *input1, *input2, *input3, *input4;


input1=lookup_widget(objet,"entry3_nom");
input2=lookup_widget(objet,"entry4_Prenom");
input3=lookup_widget(objet,"entry5_cin");
input4=lookup_widget(objet,"spinbutton1_niv");

strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
e.niveau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
printf("before appel");
ajoutereleve(e);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet, "window3_ajoutwael");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet, "window2_opti");
affiche = create_window2_opti();
gtk_widget_show(affiche);

}



void
on_button9_supp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
char cin[8];
GtkWidget *fenetre_supp;
GtkWidget *input1;
GtkWidget *fenetre_confirm;

fenetre_confirm=lookup_widget(objet,"alerte");
fenetre_supp=lookup_widget(objet,"window4_supp");
input1=lookup_widget(objet,"entry6_cin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
fenetre_confirm=create_alerte();
gtk_widget_show(fenetre_confirm);
gtk_widget_destroy(fenetre_supp);
strcpy(k,cin);
}


//////////////////////////////////////////////////////////////////////





void
on_buttonlogin_EA_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrylogin_EAname");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrylogin_EApw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{

fenetre_confirm=lookup_widget(objet,"window_menu_eya");
fenetre_supp=lookup_widget(objet,"loginespaceA");

fenetre_confirm=create_window_menu_eya();
gtk_widget_show(fenetre_confirm);

gtk_widget_destroy(fenetre_supp);
}
else 
{
fenetre_supp=lookup_widget(objet,"loginespaceA");
msg = lookup_widget (fenetre_supp, "labelEA_alertpw");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"loginespaceT");
msg1 = lookup_widget (fenetre_supp, "labelEA_alertname");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}


}


void
on_buttonlogin_ET_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrylogin_ETname");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrylogin_ETpw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{

fenetre_confirm=lookup_widget(objet,"EspaceT");
fenetre_supp=lookup_widget(objet,"loginespaceT");

fenetre_confirm=create_EspaceT();
gtk_widget_show(fenetre_confirm);

gtk_widget_destroy(fenetre_supp);
}
else 
{
fenetre_supp=lookup_widget(objet,"loginespaceT");
msg = lookup_widget (fenetre_supp, "labelET_alertpw");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"loginespaceT");
msg1 = lookup_widget (fenetre_supp, "labelET_alertname");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}

}


void
on_buttonlogin_EAR_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;

fenetre_confirm=lookup_widget(objet,"EspaceT");
fenetre_supp=lookup_widget(objet,"loginespaceT");

fenetre_confirm=create_EspaceT();
gtk_widget_show(fenetre_confirm);

gtk_widget_destroy(fenetre_supp);
}

////////////////////////////////////////////////////////////////////////////
///////////////////////////     sayf     //////////////////////////////////

char supp[10];
char rech[10];
char supp1[10];





void
on_dashboard_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"window_dashboard_login");
windowcree=create_window_dashboard_login();

gtk_widget_show(windowcree);
}


void
on_utilisateurs_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"loginespaceA");
windowcree=create_loginespaceA();

gtk_widget_show(windowcree);
}


void
on_capteurs_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"loginespaceT");
windowcree=create_loginespaceT();

gtk_widget_show(windowcree);
}


void
on_menus_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"loginespaceN");
windowcree=create_loginespaceN();

gtk_widget_show(windowcree);
}


void
on_hebergement_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"loginespaceAf");
windowcree=create_loginespaceAf();

gtk_widget_show(windowcree);

}


void
on_stock_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"loginespaceAR");
windowcree=create_loginespaceAR();

gtk_widget_show(windowcree);
}


void
on_reclamations_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"SMARTESPRIT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"loginespaceRec");
windowcree=create_loginespaceRec();

gtk_widget_show(windowcree);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void
on_sayf_menurec_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *msg;
GtkWidget *type;
	

	
  window2 = create_window2 ();
  gtk_widget_show (window2);
 type = lookup_widget (window2, "combobox1");
	gtk_combo_box_set_active(GTK_COMBO_BOX(type),1);
  
 msg = lookup_widget (window2, "label25sayf");
  gtk_label_set_text(GTK_LABEL(msg),"");
}


void
on_sayf_menumod_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *treeview;

  window3 = create_window3 ();
  gtk_widget_show (window3);
  treeview = lookup_widget (window3, "treeviewSE");
  afficher_treev(treeview);

}


void
on_sayf_menusupp_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *treeview;

  window3 = create_window3 ();
  gtk_widget_show (window3);
  treeview = lookup_widget (window3, "treeviewSE");
  afficher_treev(treeview);
}


void
on_sayf_menuvoir_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *treeview;

  window3 = create_window3 ();
  gtk_widget_show (window3);
  treeview = lookup_widget (window3, "treeviewSE");
  afficher_treev(treeview);

}


void
on_buttonlogin_ERec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *windowcree;
GtkWidget *windowsupp;

GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrylogin_ERecname");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrylogin_ERecpw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{

GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceRec");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"main");
windowcree=create_main();

gtk_widget_show(windowcree);

}
else 
{
fenetre_supp=lookup_widget(objet,"loginespaceRec");
msg = lookup_widget (fenetre_supp, "labelERec_alertpw");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"loginespaceRec");
msg1 = lookup_widget (fenetre_supp, "labelERec_alertname");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}

}



void
on_buttonSE_ajouter_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	rec r;
	int i_jour;
	int i_mois;
	int i_annee;
	char c_jour[20];
	char c_mois[20];
	char c_annee[20];
	GtkWidget *window2;
	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *classe;
	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *cin;
	GtkWidget *reclam;
	GtkWidget *type;
	GtkWidget *confirm;
	GtkWidget *msg;
	window2 = lookup_widget (objet,"window2");
	confirm = lookup_widget (window2, "checkbuttonSE_confirmer");
	msg = lookup_widget (window2, "label25sayf");
	type = lookup_widget (objet, "combobox1sayf");
	strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	
	nom = lookup_widget (objet, "entrySE_nom");
strcpy(r.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
prenom = lookup_widget (objet, "entrySE_prenom");
strcpy(r.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
classe = lookup_widget (objet, "entrysE_classe");
strcpy(r.classe, gtk_entry_get_text(GTK_ENTRY(classe)));
cin = lookup_widget (objet, "entrySE_cin");
strcpy(r.cin_ou_passeport, gtk_entry_get_text(GTK_ENTRY(cin)));
reclam = lookup_widget (objet, "entrySE_zonerec");
strcpy(r.details_reclamation, gtk_entry_get_text(GTK_ENTRY(reclam)));
jour = lookup_widget (objet, "spinbuttonSE_jour");
i_jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
mois = lookup_widget (objet, "spinbuttonSE_mois");
i_mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
annee = lookup_widget (objet, "spinbuttonSE_annee");
i_annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
sprintf(c_jour, "%d", i_jour);
sprintf(c_mois, "%d", i_mois);
sprintf(c_annee, "%d", i_annee);

	strcpy(r.date_rec ,"");
	strcat(r.date_rec ,c_jour);
	strcat(r.date_rec ,"/");
	strcat(r.date_rec ,c_mois);
	strcat(r.date_rec ,"/");
	strcat(r.date_rec ,c_annee);

r.id=chercher_id()+1;
	
	
		
	if((gtk_toggle_button_get_active(confirm)==1)&&(strcmp(r.nom,"")!=0)&&(strcmp(r.prenom,"")!=0)&&(strcmp(r.classe,"")!=0)&&(strcmp(r.cin_ou_passeport,"")!=0)&&(strcmp(r.details_reclamation,"")!=0)&&(strcmp(r.type,"")!=0))
	{
	ajouter(r,"");
	  
  gtk_widget_destroy (window2);}

	else {
	gtk_label_set_text(GTK_LABEL(msg),"svp-remplisser et cocher tous les cases");
	 }

}


void
on_checkbuttonSE_confirmer_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{



}


void
on_buttonSE_supp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *id;
	GtkWidget *window5;
	int i_id;
	id = lookup_widget (objet_graphique, "spinbuttonSE_suppid");
i_id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));
	supprimer(i_id,"");
	window5 = lookup_widget (objet_graphique,"window5");
  	gtk_widget_hide (window5);
}


void
on_buttonSE_confirmerw3_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *radiob1;
GtkWidget *window5;
GtkWidget *window4;

radiob1 = lookup_widget (objet_graphique, "radiobuttonSE_supp");
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiob1)) )
	{
	  window5 = create_window5 ();
  	gtk_widget_show (window5);	
		
	}
else {
		  window4 = create_window4 ();
  	gtk_widget_show (window4);		
	
	}



}


void
on_buttonSE_retourw3_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
  window3 = lookup_widget (objet_graphique,"window3");
  gtk_widget_hide (window3);

}


void
on_buttonSE_rech_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id;
	GtkWidget *treeview;
	GtkWidget *window3;
	char id_rech[20];
	window3 = lookup_widget (objet_graphique, "treeviewSE");
  	treeview = lookup_widget (window3, "treeviewSE");
	
	id = lookup_widget (objet_graphique, "entrySE_rechw3");
	strcpy(id_rech, gtk_entry_get_text(GTK_ENTRY(id)));
	if(!(strcmp (id_rech,"")))
	afficher_treev(treeview);
	else
	recherche_treev(treeview, id_rech);

}


void
on_radiobuttonSE_mod_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonSE_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonSE_modifierw4_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	rec r;
	int i_jour;
	int i_mois;
	int i_annee;
	char c_jour[20];
	char c_mois[20];
	char c_annee[20];
	GtkWidget *window4;
	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *classe;
	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *cin;
	GtkWidget *reclam;
	GtkWidget *id;
	GtkWidget *type;
	type = lookup_widget (objet_graphique, "comboboxSE_dep");
	strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	nom = lookup_widget (objet_graphique, "entrySE_nomm");
strcpy(r.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
prenom = lookup_widget (objet_graphique, "entrySE_prenomm");
strcpy(r.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
classe = lookup_widget (objet_graphique, "entrySE_classem");
strcpy(r.classe, gtk_entry_get_text(GTK_ENTRY(classe)));
cin = lookup_widget (objet_graphique, "entrySE_cinm");
strcpy(r.cin_ou_passeport, gtk_entry_get_text(GTK_ENTRY(cin)));
reclam = lookup_widget (objet_graphique, "entrySE_zonerecm");
strcpy(r.details_reclamation, gtk_entry_get_text(GTK_ENTRY(reclam)));
jour = lookup_widget (objet_graphique, "spinbuttonSE_jourm");
i_jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
mois = lookup_widget (objet_graphique, "spinbuttonSE_moism");
i_mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
annee = lookup_widget (objet_graphique, "spinbuttonSE_anneem");
i_annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
sprintf(c_jour, "%d", i_jour);
sprintf(c_mois, "%d", i_mois);
sprintf(c_annee, "%d", i_annee);
	strcpy(r.date_rec ,"");
	strcat(r.date_rec ,c_jour);
	strcat(r.date_rec ,"/");
	strcat(r.date_rec ,c_mois);
	strcat(r.date_rec ,"/");
	strcat(r.date_rec ,c_annee);
id = lookup_widget (objet_graphique, "spinbuttonSE_idm");
r.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id));
modifier(r.id, r , "");
	  window4 = lookup_widget (objet_graphique,"window4");
  gtk_widget_hide (window4);
}



////////////////////////////////////////////////////////////////////////












void
on_buttonEAF_login_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrylogin_EAFname");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrylogin_EAFpw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{
windowsupp=lookup_widget(objet,"loginespaceAf");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"window2_opti");
windowcree=create_window2_opti();

gtk_widget_show(windowcree);

}
else 
{
fenetre_supp=lookup_widget(objet,"loginespaceAf");
msg = lookup_widget (fenetre_supp, "labelEAF_alertpw");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"loginespaceAf");
msg1 = lookup_widget (fenetre_supp, "labelEAF_alertname");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}


}


void
on_buttonEN_login_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *windowcree;
GtkWidget *windowsupp;

GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrylogin_ENname");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrylogin_ENpw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{
windowsupp=lookup_widget(objet,"loginespaceN");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"window5_dashboard");
windowcree=create_window5_dashboard();

gtk_widget_show(windowcree);

}
else 
{
fenetre_supp=lookup_widget(objet,"loginespaceN");
msg = lookup_widget (fenetre_supp, "labelEN_alertpw");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"loginespaceN");
msg1 = lookup_widget (fenetre_supp, "labelEN_alertname");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}

}


void
on_buttonEAF_inscri_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceAf");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscriEAF");
windowcree=create_inscriEAF();

gtk_widget_show(windowcree);
}


void
on_buttonEN_inscri_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceN");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscriEN");
windowcree=create_inscriEN();

gtk_widget_show(windowcree);

}


void
on_buttoninsci_EA_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceA");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscri");
windowcree=create_inscri();

gtk_widget_show(windowcree);

}


void
on_buttoninscri_ET_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscriET");
windowcree=create_inscriET();

gtk_widget_show(windowcree);
}


void
on_buttoninscri_EAR_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceAR");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscriEAR");
windowcree=create_inscriEAR();

gtk_widget_show(windowcree);

}


void
on_buttoninscri_Erec_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceRec");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscriERec");
windowcree=create_inscriERec();

gtk_widget_show(windowcree);
}


void
on_buttonEA_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceA");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonET_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonEAR_accueil_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceAR");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonEE_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceRec");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonEAF_accueil_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceAf");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonEN_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"loginespaceN");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonhomeEA_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscri");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonhomeET_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriET");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonhomeEN_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriEN");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonhomeAF_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriEAF");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonhomeAR_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriEAR");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);

}


void
on_buttonhomeRec_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriERec");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttoninscriptionA_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pusername;
GtkWidget *ppw;
GtkWidget *pidesprit;
appuser u;



pusername=lookup_widget(objet,"entryinscri_EAname");
strcpy(u.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entryinscri_EApw");
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));

pidesprit=lookup_widget(objet,"entryinscri_EAid");
strcpy(u.idesprit,gtk_entry_get_text(GTK_ENTRY(pidesprit)));
ajoutuser(u);
////////////////////////////////////////////////////////////////
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscri");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);

}


void
on_buttoninscriptionT_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pusername;
GtkWidget *ppw;
GtkWidget *pidesprit;
appuser u;


pusername=lookup_widget(objet,"entryinscri_ETname");
strcpy(u.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entryinscri_ETpw");
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));

pidesprit=lookup_widget(objet,"entryinscri_ETid");
strcpy(u.idesprit,gtk_entry_get_text(GTK_ENTRY(pidesprit)));
ajoutuser(u);
//////////////////////////////////////////////////////////
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriET");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);

}


void
on_buttoninscriptionN_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pusername;
GtkWidget *ppw;
GtkWidget *pidesprit;
GtkWidget *Windowins;
appuser u;

Windowins=lookup_widget(objet,"inscriEN");


pusername=lookup_widget(objet,"entryinscri_ENname");
strcpy(u.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entryinscri_ENpw");
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));

pidesprit=lookup_widget(objet,"entryinscri_ENid");
strcpy(u.idesprit,gtk_entry_get_text(GTK_ENTRY(pidesprit)));
ajoutuser(u);
////////////////////////////////////////////////////////
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriEN");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);

}


void
on_buttoninscriptionAF_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pusername;
GtkWidget *ppw;
GtkWidget *pidesprit;
GtkWidget *Windowins;
appuser u;

Windowins=lookup_widget(objet,"inscriEAF");


pusername=lookup_widget(objet,"entryinscri_EAFname");
strcpy(u.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entryinscri_EAFpw");
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));

pidesprit=lookup_widget(objet,"entryinscri_EAFid");
strcpy(u.idesprit,gtk_entry_get_text(GTK_ENTRY(pidesprit)));
ajoutuser(u);
/////////////////////////////////////////////////////////////////
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriEAF");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);

}


void
on_buttoninscriptionAR_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pusername;
GtkWidget *ppw;
GtkWidget *pidesprit;
GtkWidget *Windowins;
appuser u;

Windowins=lookup_widget(objet,"inscriEAR");


pusername=lookup_widget(objet,"entryinscri_EARname");
strcpy(u.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entryinscri_EARpw");
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));

pidesprit=lookup_widget(objet,"entryinscri_EARid");
strcpy(u.idesprit,gtk_entry_get_text(GTK_ENTRY(pidesprit)));
ajoutuser(u);
////////////////////////////////////////////////////////
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriEAR");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);

}


void
on_buttoninscriptionRec_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pusername;
GtkWidget *ppw;
GtkWidget *pidesprit;
appuser u;


pusername=lookup_widget(objet,"entryinscri_ERecname");
strcpy(u.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entryinscri_ERecpw");
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));

pidesprit=lookup_widget(objet,"entryinscri_ERecid");
strcpy(u.idesprit,gtk_entry_get_text(GTK_ENTRY(pidesprit)));
ajoutuser(u);

///////////////////////////////////////////////////////////

GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"inscriERec");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);


}


void
on_buttonSH_ajoutmenu_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window5_dashboard");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"window3_ajout");
windowcree=create_window3_ajout();

gtk_widget_show(windowcree);
}


void
on_buttonSH_modmenu_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window5_dashboard");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"window4_modif");
windowcree=create_window4_modif();

gtk_widget_show(windowcree);
}


void
on_buttonSH_suppmenu_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window5_dashboard");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"window7_supp");
windowcree=create_window7_supp();

gtk_widget_show(windowcree);
}


void
on_buttonEN_logoff_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window5_dashboard");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonoET_logoff_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"EspaceT");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonEAF_logoff_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window2_opti");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonERec_logoff_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"main");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonSH_ajoutretour_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"window3_ajout");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"window5_dashboard");
windowcree=create_window5_dashboard();

gtk_widget_show(windowcree);

}


void
on_buttonAA_retouraff2_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"waffcap");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);
}


void
on_buttonSH_suppretour_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"window7_supp");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"window5_dashboard");
windowcree=create_window5_dashboard();

gtk_widget_show(windowcree);
}


void
on_buttonEYA_deconnexion_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_menu_eya");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonEYA_ajout_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_menu_eya");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"Addetudiant");
windowcree=create_Addetudiant();

gtk_widget_show(windowcree);
}


void
on_buttonEYA_modif_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_menu_eya");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"UPDATEetudiant");
windowcree=create_UPDATEetudiant();

gtk_widget_show(windowcree);
}


void
on_buttonEYA_supp_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_menu_eya");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"DELETE");
windowcree=create_DELETE();

gtk_widget_show(windowcree);
}


void
on_buttonEYA_aff_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_menu_eya");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"affiche");
windowcree=create_affiche();

gtk_widget_show(windowcree);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////            malek      /////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char am[20]="laitier";
char bm[20]="";
stock x;







void
on_button2quitter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *afficher_stock;

window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
afficher_stock=lookup_widget(GTK_WIDGET(button),("window1_malek"));

gtk_widget_destroy(afficher_stock);
window4=create_window_menu_malek();
gtk_widget_show(window4);
}


void
on_button1ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
stock x;
GtkWidget *nom_produit=lookup_widget(GTK_WIDGET(button),"nom_produit");
GtkWidget *lieu=lookup_widget(GTK_WIDGET(button),"lieu");
GtkWidget *fournisseur=lookup_widget(GTK_WIDGET(button),"fournisseur");
GtkWidget *quantite=lookup_widget(GTK_WIDGET(button),"quantite");
GtkWidget *reference=lookup_widget(GTK_WIDGET(button),"reference");
GtkWidget *jrf=lookup_widget(GTK_WIDGET(button),"jrf");
GtkWidget *msf=lookup_widget(GTK_WIDGET(button),"msf");
GtkWidget *anf=lookup_widget(GTK_WIDGET(button),"anf");
GtkWidget *jre=lookup_widget(GTK_WIDGET(button),"jre");
GtkWidget *mse=lookup_widget(GTK_WIDGET(button),"mse");
GtkWidget *ane=lookup_widget(GTK_WIDGET(button),"ane");


if((strcmp((gtk_entry_get_text(GTK_ENTRY(nom_produit))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(lieu))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(fournisseur))),"")==0)||(strcmp((gtk_entry_get_text(GTK_ENTRY(reference))),"")==0))
{ 
g_print("non");
GtkWidget *dialog2;
dialog2=create_dialog2() ;
gtk_widget_show(dialog2) ;

}

else{

strcpy(x.nom_produit,gtk_entry_get_text(GTK_ENTRY(nom_produit)));
strcpy(x.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
strcpy(x.fournisseur,gtk_entry_get_text(GTK_ENTRY(fournisseur)));
strcpy(x.reference,gtk_entry_get_text(GTK_ENTRY(reference)));

x.quantite=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
x.date_fabrication.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jrf));
x.date_fabrication.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(msf));
x.date_fabrication.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anf));
x.date_expiration.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jre));
x.date_expiration.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mse));
x.date_expiration.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ane));

strcpy(x.type,am);
strcpy(x.unite,bm);

GtkWidget *dialog1;
dialog1=create_dialog1() ;
gtk_widget_show(dialog1) ;

Ajouter_stock(x);}
strcpy(am,"laitier");
strcpy(b,"");
}


void
on_closebutton1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog1=lookup_widget(GTK_WIDGET(button),("dialog1"));

gtk_widget_destroy(dialog1);
}


void
on_closebutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2=lookup_widget(GTK_WIDGET(button),("dialog2"));

gtk_widget_destroy(dialog2);
}


void
on_button3afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
stock x;
GtkWidget *window1_malek;
GtkWidget *afficher_stock;
GtkWidget *treeviewstock;
  window1_malek=lookup_widget(objet,"window1_malek");
  gtk_widget_destroy(window1_malek);
  afficher_stock=lookup_widget(objet,"afficher_stock");
  afficher_stock=create_afficher_stock();
  gtk_widget_show(afficher_stock);
treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
Afficher_stock(treeviewstock,"stock.txt");
}


void
on_treeviewgestionstock_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gchar *str_data1;
gchar *str_data2;
gchar *str_data3;

gchar *str_data5;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
  {

 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &str_data1, -1);
 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &str_data2, -1);
 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &str_data3, -1);
 gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 6, &str_data5, -1);
  }

strcpy(x.nom_produit,str_data1);
strcpy(x.lieu,str_data2);
strcpy(x.fournisseur,str_data3);
strcpy(x.reference,str_data5);

}


void
on_button1modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget *label=lookup_widget(GTK_WIDGET(button),"label16");
//gtk_label_set_text(GTK_LABEL(label),v.test);
dell_stock(x.nom_produit);
/*****Na3mlo Actualiser lil liste **************/

GtkWidget *afficher_stock=lookup_widget(GTK_WIDGET(button),"afficher_stock");

GtkWidget *window1;
window1=lookup_widget(GTK_WIDGET(button),("window1_malek"));

gtk_widget_destroy(afficher_stock);
window1=create_window1_malek();
gtk_widget_show(window1);

GtkWidget *nom_produit=lookup_widget(window1,"nom_produit");
GtkWidget *lieu=lookup_widget(window1,"lieu");
GtkWidget *fournisseur=lookup_widget(window1,"fournisseur");

GtkWidget *reference=lookup_widget(window1,"reference");
gtk_entry_set_text(GTK_LABEL(nom_produit),x.nom_produit);
gtk_entry_set_text(GTK_LABEL(lieu),x.lieu);
gtk_entry_set_text(GTK_LABEL(fournisseur),x.fournisseur);
gtk_entry_set_text(GTK_LABEL(reference),x.reference);


}


void
on_button2supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget *label=lookup_widget(GTK_WIDGET(button),"label16");
//gtk_label_set_text(GTK_LABEL(label),v.test);
dell_stock(x.nom_produit);
/*****Na3mlo Actualiser lil liste **************/

GtkWidget *afficher_stock=lookup_widget(GTK_WIDGET(button),"afficher_stock");
GtkWidget *treeviewstock;

treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
Afficher_stock(treeviewstock,"stock.txt");
gtk_widget_show(treeviewstock);

}


void
on_button3retour_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *afficher_stock;
window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
gtk_widget_destroy(afficher_stock);
window4=create_window_menu_malek();
gtk_widget_show(window4);
}





void
on_button2retour2_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_stock, *window2,*treeviewstock;
window2=lookup_widget(GTK_WIDGET(button),("window2_malek"));
afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
gtk_widget_destroy(window2);
afficher_stock=create_afficher_stock();
gtk_widget_show(afficher_stock);
treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
Afficher_stock(treeviewstock,"stock.txt");
}


void
on_button3repture_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
stock x;
reptre_de_stock();
GtkWidget *window2;
GtkWidget *afficher_stock;
GtkWidget *treeviewstock;
  afficher_stock=lookup_widget(objet,"afficher_stock");
  gtk_widget_destroy(afficher_stock);
  window2=lookup_widget(objet,"window2_malek");
  window2=create_window2_malek();
  gtk_widget_show(window2);
treeviewstock=lookup_widget(window2,"treeview1");
Afficher_stock(treeviewstock,"repture_stock.txt");
remove("repture_stock.txt");
}


void
on_button1login_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttongotoajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{/*
	GtkWidget *window1, *window4;
	window1=lookup_widget(GTK_WIDGET(button),("window1_malek"));
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	gtk_widget_destroy(window4);
	window1=create_window1_malek();
	gtk_widget_show(window1);
*/}


void
on_buttongotomodifier_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{/*
	GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
*/}


void
on_buttongotoafficher_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{/*
	GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
*/}


void
on_buttongotosupprimer_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
}





void
on_button1recherche_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	char recherche1[19];
	GtkWidget *afficher_stock, *recherche,*treeviewstock;
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	recherche=lookup_widget(GTK_WIDGET(button),("entry1recherche"));
	strcpy(recherche1,gtk_entry_get_text(GTK_ENTRY(recherche)));
	recherche_stock(recherche1);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"recherche_stock.txt");
	remove("recherche_stock.txt");
}


void
on_radiobutton1_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"laitier");
	}
}


void
on_radiobutton2_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"Céreal");
	}
}


void
on_radiobutton3_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"sucré");
	}
}


void
on_radiobutton4_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"Boissons");
	}
}


void
on_radiobutton5_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"Legumes");
	}
}


void
on_radiobutton6_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"Fruits");
	}
}


void
on_radiobutton7_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"grass");
	}
}


void
on_radiobutton8_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"Viandes");
	}
}


void
on_radiobutton9_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		strcpy(am,"Poissons");
	}
}


void
on_checkbutton2_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	strcpy(bm,"Piéce");
}


void
on_checkbutton1_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	strcpy(bm,"Kg");
}



void
on_buttonMALEK_deconnexion_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_menu_malek");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_buttonMALEK_ajout_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window1, *window4;
	window1=lookup_widget(GTK_WIDGET(button),("window1_malek"));
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	gtk_widget_destroy(window4);
	window1=create_window1_malek();
	gtk_widget_show(window1);
}


void
on_buttonMALEK_modif_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
}


void
on_buttonMALEK_aff_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_stock, *window4,*treeviewstock;
	window4=lookup_widget(GTK_WIDGET(button),("window_menu_malek"));
	afficher_stock=lookup_widget(GTK_WIDGET(button),("afficher_stock"));
	gtk_widget_destroy(window4);
	afficher_stock=create_afficher_stock();
	gtk_widget_show(afficher_stock);
	treeviewstock=lookup_widget(afficher_stock,"treeviewgestionstock");
	Afficher_stock(treeviewstock,"stock.txt");
}


void
on_buttonlogin_MALEK_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrylogin_EARname");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrylogin_EARpw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{

fenetre_confirm=lookup_widget(objet,"window_menu_malek");
fenetre_supp=lookup_widget(objet,"loginespaceAR");

fenetre_confirm=create_window_menu_malek();
gtk_widget_show(fenetre_confirm);

gtk_widget_destroy(fenetre_supp);
}
else 
{
fenetre_supp=lookup_widget(objet,"loginespaceAR");
msg = lookup_widget (fenetre_supp, "labelEAR_alertpw");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"loginespaceAR");
msg1 = lookup_widget (fenetre_supp, "labelEAR_alertname");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}
}


void
on_afficher_retour2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet_graphique, "affiche");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet_graphique, "window_menu_eya");
affiche = create_window_menu_eya();
gtk_widget_show(affiche);
}


void
on_buttonWC_retourajout_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet_graphique, "window3_ajoutwael");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet_graphique, "window2_opti");
affiche = create_window2_opti();
gtk_widget_show(affiche);
}


void
on_buttonWC_retoursupp_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet_graphique, "window4_supp");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet_graphique, "window2_opti");
affiche = create_window2_opti();
gtk_widget_show(affiche);
}


void
on_buttonWC_modretour_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet_graphique, "window5_modif");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet_graphique, "window2_opti");
affiche = create_window2_opti();
gtk_widget_show(affiche);
}


void
on_buttonWC_retouraff_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* affiche;
GtkWidget* addetudiant;
addetudiant = lookup_widget(objet_graphique, "tv");
gtk_widget_destroy(addetudiant);
affiche = lookup_widget(objet_graphique, "window2_opti");
affiche = create_window2_opti();
gtk_widget_show(affiche);
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gint* cin;
	gint* niveau;
	etudiant e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if (gtk_tree_model_get_iter(model, &iter, path)) {

	gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &nom, 1, &prenom, 2, &cin, 3, &niveau, -1);
	strcpy(e.cin,cin);
	strcpy(e.nom,nom);
	strcpy(e.prenom,prenom);
	e.niveau=niveau;
	supprimereleve(cin);
	affichereleve(treeview);
	}

}


void
on_buttonARIJ_affich_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window4, *afficher_stock;
window4=lookup_widget(GTK_WIDGET(button),("waffcap"));
afficher_stock=lookup_widget(GTK_WIDGET(button),("EspaceT"));
gtk_widget_destroy(afficher_stock);
window4=create_waffcap();
gtk_widget_show(window4);
}


void
on_buttonARIJ_retouraff_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"waffcap");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"EspaceT");
windowcree=create_EspaceT();

gtk_widget_show(windowcree);
}


void
on_dashlogic_accueil_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(button,"window_dashboard_login");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(button,"SMARTESPRIT");
windowcree=create_SMARTESPRIT();

gtk_widget_show(windowcree);
}


void
on_dashlogin_cnx_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

GtkWidget *fenetre_supp;
GtkWidget *fenetre_confirm;
GtkWidget *msg;
GtkWidget *msg1;
GtkWidget *pusername;
GtkWidget *ppw;
appuser u,u1;

pusername=lookup_widget(objet,"entrydashlogin");
strcpy(u1.uname,gtk_entry_get_text(GTK_ENTRY(pusername)));

ppw=lookup_widget(objet,"entrydashpw");
strcpy(u1.pw,gtk_entry_get_text(GTK_ENTRY(ppw)));


int error=0;
FILE *f=NULL;
int trouve=0;
f=fopen("users.txt","a+");
if (f!=NULL)
{
do
{
fscanf(f,"%s \t %s \t %s \n",&u.uname,&u.pw,&u.idesprit);
if(strcmp(u1.uname,u.uname)==0)
{
trouve=1;
if (strcmp(u1.pw,u.pw)==0)
{
windowsupp=lookup_widget(objet,"window_dashboard_login");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"ZE_DASHBOARD");
windowcree=create_ZE_DASHBOARD();

gtk_widget_show(windowcree);

}
else 
{
fenetre_supp=lookup_widget(objet,"window_dashboard_login");
msg = lookup_widget (fenetre_supp, "label346");
  gtk_label_set_text(GTK_LABEL(msg)," Mot de passe incorrect ! ");}
}

}
while(!feof(f)&&trouve==0);

if (trouve==0)
{
error=2;
fenetre_supp=lookup_widget(objet,"window_dashboard_login");
msg1 = lookup_widget (fenetre_supp, "label344");
  gtk_label_set_text(GTK_LABEL(msg1),"Ce nom d'utilisateur n'existe pas ");
}
fclose(f);
}
else
{error=1;}

}


void
on_dashlogin_inscri_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"window_dashboard_login");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"inscriET");
windowcree=create_inscriET();

gtk_widget_show(windowcree);
}




void
on_buttonMALEK_supp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowcree;
GtkWidget *windowsupp;

windowsupp=lookup_widget(objet,"window_menu_malek");
gtk_widget_destroy(windowsupp);

windowcree=lookup_widget(objet,"afficher_stock");
windowcree=create_afficher_stock();

gtk_widget_show(windowcree);
}

