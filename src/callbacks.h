#include <gtk/gtk.h>


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button2_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_retour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button9_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button10_rech_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button11_gen_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_close_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_login_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button9_actualiser_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_valider_rech_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button9_treeview_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

/*
void
on_button_validermodif_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_modifmenu_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);
*/
void
on_button_suppri_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton10_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_sbutton_supps_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_new_modif_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modif_retour_clicked                (GtkWidget       *user,
                                        gpointer         user_data);

void
on_radiobutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_sbutton2_modify_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sbutton1_goback_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);


//////////////////////////////////////////////////////////////////////////////
///////////////////        ARIJ       //////////////////////////////////////
void
on_buttonAA_ajouter_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_Modifier_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_supprimer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_rechercher_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_Afficher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_ajoutajout_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retourajout_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_validermod_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_modmod_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retourmod_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_supp1_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_annulers_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_nonsupp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_ouisupp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_ok_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_validerrech_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retourrech_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewAA_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonAA_actualiser_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retouraff_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_ajoutaff_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_modaff_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_suppaff_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_annuleraff_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_supp1aff_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_nonsuppaff_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_ouisuppaff_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_okaff_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_ajoutfinaff_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retourajoutaff_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_valmodaff_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_modfinaff_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retourmodaff_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_nonmod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ouimod_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAA_nonaff_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ouimaff_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

//////////////////////////////////////////////////////////////////////
////////////////////////   EYA    ///////////////////////////////////////

void
on_addReturn_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_SUBMIT_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_delete_return_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonDELETE_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_update_return_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonUPD_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_buttonADD_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonUPDATE_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonDLT_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonaffiche_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);






void
on_button1tache2_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2retour_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treevieweya_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


////////////////////////////////////////////////////////////////////////
///////////////////////////   wael   ////////////////////////////////////


void
on_button1_con_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

/*void
on_button2_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);*/

void
on_button3_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_rechercher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

/*void
on_button7_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);*/

void
on_button9_supp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_mod_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_cher_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_confirm_add                  (GtkContainer    *container,
                                        GtkWidget       *widget,
                                        gpointer         user_data);

void
on_button_confirm_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_confirm_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_back_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_alter_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_alter2_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_alter1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_testrech_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttondashwa_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoncalwa_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_ajoutwael_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_ajoutwael_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);
///////////////////////////////////////////////////////////////////////////






void
on_buttonlogin_EA_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonlogin_ET_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonlogin_EAR_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);



//////////////////////////////////////////////////////////////////////////
///////////////////////////////   sayf    /////////////////////////////////


void
on_dashboard_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_utilisateurs_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_capteurs_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_menus_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_hebergement_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_stock_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_reclamations_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_sayf_menurec_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sayf_menumod_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sayf_menusupp_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sayf_menuvoir_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonlogin_ERec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_buttonSE_ajouter_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbuttonSE_confirmer_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonSE_supp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonSE_confirmerw3_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *objet,
                                        gpointer         user_data);

void
on_buttonSE_retourw3_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonSE_rech_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void 
on_radiobuttonSE_mod_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonSE_supp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonSE_modifierw4_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonEAF_login_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEN_login_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEAF_inscri_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEN_inscri_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninsci_EA_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscri_ET_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscri_EAR_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscri_Erec_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEA_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonET_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEAR_accueil_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEE_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEAF_accueil_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEN_accueil_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhomeEA_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhomeET_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhomeEN_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhomeAF_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhomeAR_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhomeRec_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscriptionA_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscriptionT_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscriptionN_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscriptionAF_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscriptionAR_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninscriptionRec_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonSH_ajoutmenu_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSH_modmenu_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSH_suppmenu_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonEN_logoff_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonoET_logoff_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonEAF_logoff_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonERec_logoff_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonSH_ajoutretour_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAA_retouraff2_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonSH_suppretour_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonEYA_deconnexion_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonEYA_ajout_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonEYA_modif_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonEYA_supp_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonEYA_aff_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////        malek      ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_button2quitter_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button1ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_closebutton1_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_closebutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewgestionstock_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button1modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2supprimer_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3retour_clicked               (GtkButton       *button,
                                        gpointer         user_data);




void
on_button2retour2_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3repture_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1login_clicked                (GtkButton       *button,
                                        gpointer         user_data);



void
on_buttongotoajouter_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttongotomodifier_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttongotoafficher_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttongotosupprimer_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button1recherche_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton1_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton7_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton9_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_malek_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonMALEK_deconnexion_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonMALEK_ajout_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonMALEK_modif_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonMALEK_aff_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonlogin_MALEK_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficher_retour2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonWC_retourajout_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonWC_retoursupp_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonWC_modretour_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonWC_retouraff_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonARIJ_affich_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonARIJ_retouraff_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_dashlogic_accueil_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_dashlogin_cnx_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dashlogin_inscri_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_buttonMALEK_supp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
