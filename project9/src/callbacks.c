#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "adh.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
extern GtkWidget *window1;  
	GtkWidget *window2;  
	GtkWidget *window3;  
	GtkWidget *window4;  




void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window3;
	GtkWidget *window2;
	
	
	window2=lookup_widget(objet_graphique,"window2");
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window2);
	window3 = create_window3 ();
  	gtk_widget_show (window3);
	
	
	
	
}


void
on_button2_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
	GtkWidget *window2;
window2=lookup_widget(objet_graphique,"window2");
	window4=lookup_widget(objet_graphique,"window4");
gtk_widget_hide(window2);
	window4 = create_window4 ();
  	gtk_widget_show (window4);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window2=lookup_widget(objet_graphique,"window2");
	window1=lookup_widget(objet_graphique,"window1");
	remove("ad.txt");
	gtk_widget_hide(window2);
	window1 = create_window1 ();
  	gtk_widget_show (window1);
	
}


void
on_button7_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;


treeview1 = lookup_widget(objet_graphique,"treeview1");
afficher (treeview1);

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	char identifiant[30];
	GtkWidget *input;
	input=lookup_widget(objet_graphique,"entry6");
	window2=lookup_widget(objet_graphique,"window2");
	window1=lookup_widget(objet_graphique,"window1");
	strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input)));
	FILE *f;
	f=fopen("ad.txt","a+");
        if(f!=NULL)
        { 
	fprintf(f,"%s \n",identifiant);
	fclose(f);
	}
	else
	{
	return 0;
	}
	gtk_widget_hide(window1);
	window2 = create_window2 ();
  	gtk_widget_show (window2);


}


void
on_button9_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	adherent p ;
	char id[50];
	char nom[50];
	char prenom[50];
	char jour[50];
	char mois[50];
	char annee[50];
	char adresse[50];
	char tel[50];
	char adressemail[50];
	char Date[50];
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *comboboxentry3;
	GtkWidget *comboboxentry4;
	GtkWidget *comboboxentry5;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *input9;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *output5;
	GtkWidget *output6;
	GtkWidget *output7;
        input1=lookup_widget(objet_graphique,"label35");
	input2=lookup_widget(objet_graphique,"entry1");
	input3=lookup_widget(objet_graphique,"entry2");
	input7=lookup_widget(objet_graphique,"entry3");
	input8=lookup_widget(objet_graphique,"entry4");
	input9=lookup_widget(objet_graphique,"entry5");
	comboboxentry3= lookup_widget(objet_graphique, "comboboxentry3");
	strcpy(p.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3)));
	comboboxentry4= lookup_widget(objet_graphique, "comboboxentry4");
	strcpy(p.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry4)));
	comboboxentry5= lookup_widget(objet_graphique, "comboboxentry5");
	strcpy(p.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry5)));

strcpy(p.id,gtk_label_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(p.adressemail,gtk_entry_get_text(GTK_ENTRY(input9)));

modif_ad(p) ;
//jkbk//
strcpy(Date,p.jour);
strcat(Date,"/");
strcat(Date,p.mois);
strcat(Date,"/");
strcat(Date,p.annee);

output1=lookup_widget(objet_graphique,"label35");
gtk_label_set_text(GTK_LABEL(output1),p.id);

output2=lookup_widget(objet_graphique,"label28");
gtk_label_set_text(GTK_LABEL(output2),p.nom);

output3=lookup_widget(objet_graphique,"label29");
gtk_label_set_text(GTK_LABEL(output3),p.prenom);

output4=lookup_widget(objet_graphique,"label30");
gtk_label_set_text(GTK_LABEL(output4),Date);

output5=lookup_widget(objet_graphique,"label31");
gtk_label_set_text(GTK_LABEL(output5),p.adresse);

output6=lookup_widget(objet_graphique,"label32");
gtk_label_set_text(GTK_LABEL(output6),p.tel);

output7=lookup_widget(objet_graphique,"label33");
gtk_label_set_text(GTK_LABEL(output7),p.adressemail);

}


void
on_button12_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
char coach[50];
combobox1=lookup_widget(objet_graphique, "combobox1");
strcpy(coach,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
ajouter_res(coach);

}

// actualiser
void
on_button10_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
char coach[50];
char horraire[50];
combobox1=lookup_widget(objet_graphique, "combobox1");
FILE* f=fopen("reservation.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s \n",coach,horraire)!=EOF)
{
strcat(coach, horraire);
gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _(coach));
}
fclose(f);
}
}


void
on_button5_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *window3;
	GtkWidget *window2;
	window2=lookup_widget(objet_graphique,"window2");
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	window2 = create_window2 ();
  	gtk_widget_show (window2);
	
}

//supprimer
void
on_button11_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox2;
char coach[50];
combobox2=lookup_widget(objet_graphique, "combobox2");
strcpy(coach,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
supprimer_res(coach);
}

//actualiser
void
on_button13_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox2;
char coach[50];
combobox2=lookup_widget(objet_graphique, "combobox2");
FILE* f=fopen("coach.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s\n",coach)!=EOF)
{
gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _(coach));
}
fclose(f);
}
}


void
on_button14_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{	adherent p ;
	char id1[50];
	char id[50];
	char nom[50];
	char prenom[50];
	char jour[50];
	char mois[50];
	char annee[50];
	char adresse[50];
	char tel[50];
	char adressemail[50];
	char Date[50];
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *output5;
	GtkWidget *output6;
	GtkWidget *output7;
	
	
    FILE *f;
    FILE *f1;
    f=fopen("baseadh.txt","r+");
    f1=fopen("ad.txt","r");
    if (f!=NULL)
    {
        while(!feof(f))
        {
	 fscanf(f1,"%s",id1);
            fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.jour,
p.mois,p.annee,p.adresse,p.tel,p.adressemail);
            if(strcmp(id1,p.id)==0)
            {
strcpy(Date,p.jour);
strcat(Date,"/");
strcat(Date,p.mois);
strcat(Date,"/");
strcat(Date,p.annee);
	output1=lookup_widget(objet_graphique,"label35");
gtk_label_set_text(GTK_LABEL(output1),p.id);

output2=lookup_widget(objet_graphique,"label28");
gtk_label_set_text(GTK_LABEL(output2),p.nom);

output3=lookup_widget(objet_graphique,"label29");
gtk_label_set_text(GTK_LABEL(output3),p.prenom);

output4=lookup_widget(objet_graphique,"label30");
gtk_label_set_text(GTK_LABEL(output4),Date);

output5=lookup_widget(objet_graphique,"label31");
gtk_label_set_text(GTK_LABEL(output5),p.adresse);

output6=lookup_widget(objet_graphique,"label32");
gtk_label_set_text(GTK_LABEL(output6),p.tel);

output7=lookup_widget(objet_graphique,"label33");
gtk_label_set_text(GTK_LABEL(output7),p.adressemail);
            }
  	 
	}
	
    fclose(f1);
    fclose(f);

    }

}


void
on_button15_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f;
	adherent p ;
	char id1[50];
	char id[50];
	char nom[50];
	char prenom[50];
	char jour[50];
	char mois[50];
	char annee[50];
	char adresse[50];
	char tel[50];
	char adressemail[50];
	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *entry3;
	GtkWidget *entry4;
	GtkWidget *entry5;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *comboboxentry1;
	GtkWidget *comboboxentry2;
	GtkWidget *comboboxentry3;
	
    FILE *f1;
    f=fopen("baseadh.txt","r+");
    f1=fopen("ad.txt","r");
    if (f!=NULL)
    {
        while(!feof(f))
        {
	 fscanf(f1,"%s",id1);
            fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.jour,
p.mois,p.annee,p.adresse,p.tel,p.adressemail);
            if(strcmp(id1,p.id)==0){
	

       
 	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");
	input3=lookup_widget(objet_graphique,"entry3");
	input4=lookup_widget(objet_graphique,"entry4");
	input5=lookup_widget(objet_graphique,"entry5");
	comboboxentry1= lookup_widget(objet_graphique, "comboboxentry1");
	comboboxentry2= lookup_widget(objet_graphique, "comboboxentry2");
	comboboxentry3= lookup_widget(objet_graphique, "comboboxentry3");
	gtk_entry_set_text (GTK_ENTRY (input1), p.nom);
	gtk_entry_set_text (GTK_ENTRY (input2), p.prenom);
	gtk_entry_set_text (GTK_ENTRY (input3), p.adresse);
	gtk_entry_set_text (GTK_ENTRY (input4), p.tel);
	gtk_entry_set_text (GTK_ENTRY (input5), p.adressemail);
	gtk_entry_set_text (GTK_ENTRY (comboboxentry1), p.jour);
	gtk_entry_set_text (GTK_ENTRY (comboboxentry2), p.mois);
	gtk_entry_set_text (GTK_ENTRY (comboboxentry3), p.annee);



 fclose(f);
fclose(f1);
}
}
}
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

