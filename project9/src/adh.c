#include <stdio.h> 
#include <string.h>
#include "adh.h" 
#include <gtk/gtk.h>
#include <stdlib.h>
// modification des adherent
int modif_ad(adherent A) 
{
    adherent p;
    char id1[50];
    FILE *f;
    FILE *f1;
    FILE *f2;
    f1=NULL;
    f=fopen("baseadh.txt","r+");
    f2=fopen("ad.txt","r");
    f1=fopen("baseadh.txt.tmp","a+");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.jour,
p.mois,p.annee,p.adresse,p.tel,p.adressemail);
	
            fscanf(f2,"%s",id1);
            if(strcmp(p.id,id1)!=0)
            {
			fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.jour,
p.mois,p.annee,p.adresse,p.tel,p.adressemail);
            }
  	    else
            {
	     		fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",id1,A.nom,A.prenom,A.jour,
A.mois,A.annee,A.adresse,A.tel,A.adressemail);
	    }	
	}
	
    fclose(f1);
    fclose(f);
	fclose(f2);
    rename("baseadh.txt.tmp","baseadh.txt");

	return 0;

    }
}
//affichage des adherent 
void afficher (GtkWidget *treeview1)
{
enum
{
 COACH,
 DISPONIBILITE,
 COL
 
};

GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;
char coach[100];
char disponibilite[100];


FILE *f;
store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("COACH",renderer,"text",COACH,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("DISPONIBILITE",renderer,"text",DISPONIBILITE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);




	}	
	store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("coach.txt","r");
if (f == NULL ) {return;}
else
{
while (fscanf(f,"%s %s\n ",coach,disponibilite)!=EOF) {

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COACH,coach,DISPONIBILITE,disponibilite,-1);
}
fclose(f);
}
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store));
	g_object_unref(store);

}
// ajouter reservation 
int ajouter_res(char coach[50])
{
FILE *f;
f=fopen("res.txt","a+");
        if(f!=NULL)
        { 
	fprintf(f,"%s \n",coach);
	fclose(f);
	}
	else
	{
	return 0;
	}
}
// supprimer reservation
void supprimer_res(char coach[50])
{
char c[50];
FILE *f;
FILE *f2;
f=fopen("coach.txt","r");

if(f==NULL)
	{
		printf("erreur d'ouverture du fichier ");
		return;
	}
while (fscanf(f,"%s ",c)!=EOF)
        {
         if (strcmp(coach,c))
        {
	f2=fopen("res1.txt", "a");
		if (f2==NULL)
		{
		printf("erreur d'ouverture du fichier en mode a");
		return;
		}

	fprintf(f2,"%s \n",c);

	 fclose(f2);
	}
	}

	fclose(f);
remove("coach.txt");
rename("res1.txt","coach.txt");

}

