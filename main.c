/*
Konan Jean-CharlEm OLE MASTER 1 SIGL

code de compilation:

make
./main

*/


//le code main
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
//#include <mysql/mysql.h>
#include "fonction.h"
#include "definitiondetype.h"
#include <time.h>


client p;

// les variables globales
GtkWidget	*authen;
GtkWidget	*login;
GtkWidget	*mdpp;
GtkWidget	*totalcontact;
GtkWidget	*amicontact;
GtkWidget	*jobcontact;
GtkWidget	*famillecontact;
GtkWidget 	*w_comboboxtext_options;
GtkWidget 	*w_comboboxtext_options_modif;
GtkWidget	*fenetre;
GtkWidget	*dialog;
GtkWidget	*dialog2;
GtkWidget	*screen;
GtkWidget	*authen;
GtkWidget	*id_ligne;
GtkWidget	*btn_ajouter;
GtkWidget	*btn_modifier;
GtkWidget	*btn_statistique;
GtkWidget	*btn_rechercher;
GtkWidget	*btn_suprimer;
//CHAMP DU FORMULAIRE
GtkWidget	*nom;
GtkWidget	*prenom;
GtkWidget	*contact;
GtkWidget	*adresse;
GtkWidget	*email;
GtkBuilder	*projet_glade; 
GtkWidget	*fixedajout; 
GtkWidget	*entrynom1;
GtkWidget	*entryprenom1;
GtkWidget	*entrycontact1;
GtkWidget	*entryadresse1;
GtkWidget	*entryemail1;

GtkWidget	*rechercher;

// AFFICHAGE TREE
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeView *table;
GtkTreeSelection *selectionner;


void on_authentifier_clicked(GtkButton *b)
{
	int id;
	char *loging, *mdp;
	login = GTK_WIDGET(gtk_builder_get_object(projet_glade, "loging"));
        mdpp = GTK_WIDGET(gtk_builder_get_object(projet_glade, "mdp"));
        
	loging = gtk_entry_get_text(GTK_ENTRY(login));
    	mdp = gtk_entry_get_text(GTK_ENTRY(mdpp));
	id = connecter(loging,mdp);
	printf("%d",id);
	if(id)
	{
	 	gtk_widget_hide(authen);
		gtk_widget_show(fenetre);
	}else{gtk_widget_show(authen);}
	
}

void on_btnajouter_clicked(GtkButton *b)
{
	char *item_text;
	nom = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entrynom"));
	prenom = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entryprenom"));
	contact = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entrycontacts"));
	w_comboboxtext_options = GTK_WIDGET(gtk_builder_get_object(projet_glade, "liste"));
	item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(w_comboboxtext_options));
	if (item_text == NULL) {
		// return if no text found in combo box
		return;
	}
	//printf(item_text);
	
	p.nom = gtk_entry_get_text(GTK_ENTRY(nom));
	p.prenom = gtk_entry_get_text(GTK_ENTRY(prenom));
	p.contact = gtk_entry_get_text(GTK_ENTRY(contact));
	insertion_dans_bd(p);
	//ajout_reussi();
	gtk_entry_set_text(GTK_ENTRY(nom), "");
	gtk_entry_set_text(GTK_ENTRY(prenom), "");
	gtk_entry_set_text(GTK_ENTRY(contact), "");
	
	//gtk_widget_show(dialog);
	
}


/*void on_btnconfirmerbox_clicked(GtkButton *b)
{
	supprimer_un_contact(id_ligne);
	
	gtk_widget_hide(dialog);
	gtk_widget_show(fenetre);
	
}


void on_supprimercontact_clicked(GtkButton *b)
{
	char *nom, *prenom, *contact, *adresse, *email;
        table = GTK_TREE_VIEW(gtk_builder_get_object(projet_glade, "table_de_vu"));
        selectionner = gtk_tree_view_get_selection(table);
        gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selectionner), &model,  &iter);
        gtk_tree_model_get(model, &iter, 0, &nom, 1, &prenom, 2, &contact, 3, &adresse,4, &email,-1);
	id_ligne=id_de_la_ligne(nom,prenom,contact, adresse, email);
	gtk_widget_show(dialog);
}


void on_btnmodifiervalider_clicked(GtkButton *b)
{
	char *text_h;
	p.nom = gtk_entry_get_text(GTK_ENTRY(entrynom1));
    	p.prenom = gtk_entry_get_text(GTK_ENTRY(entryprenom1));
    	p.contact = gtk_entry_get_text(GTK_ENTRY(entrycontact1));
        p.adresse = gtk_entry_get_text(GTK_ENTRY(entryadresse1));
	p.email = gtk_entry_get_text(GTK_ENTRY(entryemail1));
	w_comboboxtext_options_modif = GTK_WIDGET(gtk_builder_get_object(projet_glade, "liste1"));
	text_h = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(w_comboboxtext_options_modif));
	if (text_h == NULL) {
		// return if no text found in combo box
		return;
	}
	mise_a_jour_de_la_ligne(p,id_ligne,text_h);
	//printf("%d",id_ligne);
        gtk_list_store_clear(GTK_LIST_STORE(model));
	affichage_des_contacts(model,iter);
	gtk_widget_hide(screen);
	gtk_widget_show(fenetre);
	
}

void on_btnmodifier_clicked(GtkButton *b)
{

	char *nom, *prenom, *contact, *adresse, *email;

	entrynom1 = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entrynom1"));
	entryprenom1 = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entryprenom1"));
	entrycontact1 = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entrycontacts1"));
	entryadresse1 = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entryadresse1"));
	entryemail1 = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entryemail1"));
        table = GTK_TREE_VIEW(gtk_builder_get_object(projet_glade, "table_de_vu"));
	
    
        selectionner = gtk_tree_view_get_selection(table);
        gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selectionner), &model,  &iter);

        gtk_tree_model_get(model, &iter, 0, &nom, 1, &prenom, 2, &contact, 3, &adresse,4, &email,-1);
	gtk_entry_set_text(GTK_ENTRY(entrynom1), nom);
	gtk_entry_set_text(GTK_ENTRY(entryprenom1), prenom);
	gtk_entry_set_text(GTK_ENTRY(entrycontact1), contact);
	gtk_entry_set_text(GTK_ENTRY(entryadresse1), adresse);
	gtk_entry_set_text(GTK_ENTRY(entryemail1), email);
	

	
	
	id_ligne=id_de_la_ligne(nom,prenom,contact, adresse, email);
	gtk_widget_show(screen);
}


void on_actualiser_clicked(GtkButton *b)
{
	gtk_list_store_clear(GTK_LIST_STORE(model));
	affichage_des_contacts(model,iter);
}

void ajout_reussi()
{
	gtk_list_store_clear(GTK_LIST_STORE(model));
	affichage_des_contacts(model,iter);
	gtk_widget_show(dialog2);
}

void on_btnokboxe2_clicked(GtkButton *b)
{
	gtk_widget_hide(dialog2);
	gtk_widget_show(fenetre);
}


void on_btnajouter_clicked(GtkButton *b)
{
	char *item_text;
	nom = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entrynom"));
	prenom = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entryprenom"));
	contact = GTK_WIDGET(gtk_builder_get_object(projet_glade, "entrycontacts"));
	w_comboboxtext_options = GTK_WIDGET(gtk_builder_get_object(projet_glade, "liste"));
	item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(w_comboboxtext_options));
	if (item_text == NULL) {
		// return if no text found in combo box
		return;
	}
	//printf(item_text);
	
	p.nom = gtk_entry_get_text(GTK_ENTRY(nom));
	p.prenom = gtk_entry_get_text(GTK_ENTRY(prenom));
	p.contact = gtk_entry_get_text(GTK_ENTRY(contact));
	p.adresse = gtk_entry_get_text(GTK_ENTRY(adresse));
	p.email = gtk_entry_get_text(GTK_ENTRY(email));
	insertion_dans_bd(p,item_text);
	ajout_reussi();
	gtk_entry_set_text(GTK_ENTRY(nom), "");
	gtk_entry_set_text(GTK_ENTRY(prenom), "");
	gtk_entry_set_text(GTK_ENTRY(contact), "");
	gtk_entry_set_text(GTK_ENTRY(adresse), "");
	gtk_entry_set_text(GTK_ENTRY(email), "");	
	
	//gtk_widget_show(dialog);
	
}



void on_recherche_changed(GtkSearchEntry *text)
{
	
	gtk_list_store_clear(GTK_LIST_STORE(model));
	on_recherche_search_changed(model,iter, gtk_entry_get_text(GTK_ENTRY(rechercher)));
}

void on_btnannuldialog_clicked(GtkButton *b)
{
	gtk_widget_hide(dialog);
	gtk_widget_show(fenetre);
}
void on_btnmodifierannuler_clicked(GtkButton *b)
{
	gtk_widget_hide(screen);
	gtk_widget_show(fenetre);
}
void on_importer_clicked(GtkButton *b)
{
	importercontact();
}
*/

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

	projet_glade = gtk_builder_new_from_file("fenetre.glade");

	fenetre = GTK_WIDGET(gtk_builder_get_object(projet_glade, "fenetre"));
        /*dialog = GTK_WIDGET(gtk_builder_get_object(projet_glade, "dialog"));
	dialog2= GTK_WIDGET(gtk_builder_get_object(projet_glade, "dialog2"));
	screen= GTK_WIDGET(gtk_builder_get_object(projet_glade, "screen"));*/
	authen= GTK_WIDGET(gtk_builder_get_object(projet_glade, "authent"));


	
	//affichage des contacts dans le table
	/*model = gtk_list_store_new (7,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	table = GTK_TREE_VIEW(gtk_builder_get_object(projet_glade, "table_de_vu"));
	gtk_tree_view_set_model (GTK_TREE_VIEW(table), GTK_TREE_MODEL(model));
	affichage_des_contacts(model,iter);
	rechercher = GTK_WIDGET(gtk_builder_get_object(projet_glade, "recherche"));

	g_signal_connect(fenetre, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(dialog, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(dialog2, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(screen, "destroy", G_CALLBACK(gtk_main_quit), NULL);*/
	g_signal_connect(authen, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
        gtk_builder_connect_signals(projet_glade, NULL);

	//--btn_ajouter = GTK_WIDGET(gtk_builder_get_object(projet_glade, "btnajout"));
	//--lbl_head = GTK_WIDGET(gtk_builder_get_object(projet_glade, "lbl_head"));
	
	gtk_widget_show(authen);
	gtk_main();
	return EXIT_SUCCESS;
}

