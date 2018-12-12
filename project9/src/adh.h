#include <gtk/gtk.h>
#include <stdio.h>
struct adherent {
	char id[50];
	char nom[50];
	char prenom[50];
	char jour[50];
	char mois[50];
	char annee[50];
	char adresse[10];
	char tel[50];
	char adressemail[50];
	
} ;
typedef struct adherent adherent;
struct co {
	char nomm[50];
	char ress[50];

} ;
typedef struct co co;


void afficher (GtkWidget *treeview1);

int modif_ad(adherent p) ;
void affich_ad(char id[]) ;
int ajouter_res(char coach[50]);
void supprimer_res(char coach[50]);


