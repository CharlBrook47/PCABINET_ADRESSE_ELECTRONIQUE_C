//les fonctions
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "definitiondetype.h"
#include "basededonnee.h"
#include "fonction.h"
#include <time.h>

int connecter(char * loging, char * mdp)
{
MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"SELECT * FROM utilisateur WHERE loging= '%s' and password= '%s' order by id_utilisateur limit 1;",loging,mdp);
    if (mysql_query(con,querry))
    {
        finish_with_error(con);
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL)
    {
        finish_with_error(con);
    }
    MYSQL_ROW row=mysql_fetch_row(result);
    int res = atoi(row[0]);
    printf("%d",res);
    return res;

}
int insertion_dans_bd(client client)
{
    int res=0;
    time_t date = time(0);
    date = ctime(&date);
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"insert into client(nom_cli,prenom_cli,numero_cli) Values('%s','%s','%s');",
            client.nom,client.prenom,client.contact);
    if (mysql_query(con, querry))
    {
        finish_with_error(con);
        res = -1;
    }
    else
    {
        res = 1;
    }
    mysql_close(con);
}

/*void affichage_des_contacts(GtkTreeModel  *model,GtkTreeIter iter)
{
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
    if (mysql_query(con, "select * from personne;"))
    {
        finish_with_error(con);
    }
    else
    {
        MYSQL_RES *result = mysql_store_result(con);
        if (result == NULL)
        {
            finish_with_error(con);
        }
        int num_fields = mysql_num_fields(result);
        MYSQL_ROW row;
        char user_info[100];
        while ((row = mysql_fetch_row(result)))
        {
            gtk_list_store_append (model, &iter);
            gtk_list_store_set(model, &iter,0,row[1],1,row[2],2,row[3],3,row[4],4,row[5],5,row[6],6,row[7],-1);
        }
        mysql_free_result(result);
    }
    mysql_close(con);
}

int insertion_dans_bd(personne personne,char *genre )
{
    int res=0;
    time_t date = time(0);
    date = ctime(&date);
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"insert into personne(nom,prenom,contact,adresse,email,genre,date) Values('%s','%s','%s','%s','%s','%s',NOW());",
            personne.nom,personne.prenom,personne.contact,personne.adresse,personne.email,genre,date);
    if (mysql_query(con, querry))
    {
        finish_with_error(con);
        res = -1;
    }
    else
    {
        res = 1;
    }
    mysql_close(con);
}

int id_de_la_ligne(char * nom, char * prenom,char * contact, char * adresse, char * email)
{

    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"SELECT * FROM personne WHERE nom= '%s' and prenom= '%s' and contact='%s' and adresse='%s' and email='%s' order by id limit 1;",nom,prenom,contact,adresse,email);
    if (mysql_query(con,querry))
    {
        finish_with_error(con);
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL)
    {
        finish_with_error(con);
    }
    MYSQL_ROW row=mysql_fetch_row(result);
    int res = atoi(row[0]);
    return res;
}


int mise_a_jour_de_la_ligne(personne personne,int id, char *genre)
{
    int res=0;
    time_t date = time(0);
    date = ctime(&date);
    printf(date);
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[450];
    char chaine[100];
    sprintf(querry,"update personne set nom='%s',prenom='%s',contact='%s',adresse='%s',email='%s',genre='%s', date=NOW() where id = %d;",
            personne.nom,personne.prenom,personne.contact,personne.adresse,personne.email,genre,id);
    //sprintf(chaine,"update personne set  where id = %d;",id);
    //querry = strcat(querry, chaine);
    printf(querry);
    //printf(chaine);
    if (mysql_query(con, querry))
    {
        finish_with_error(con);
        res = -1;
    }
    else
    {
        res = 1;
    }
    return res;
    mysql_close(con);
}

void supprimer_un_contact(int id)
{
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
    sprintf(querry,"delete from personne where id=%d;",id);
    if (mysql_query(con, querry))
    {
        finish_with_error(con);
    }
    mysql_close(con);
}


void on_recherche_search_changed(GtkTreeModel  *model,GtkTreeIter iter, char *rechercher)
{
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[200];
    sprintf(querry,"select * from personne WHERE nom LIKE '%s%' OR prenom LIKE '%s%' OR contact LIKE '%s%' OR adresse LIKE '%s%';", rechercher,rechercher,rechercher,rechercher);
    if (mysql_query(con, querry))
    {
        finish_with_error(con);
    }
    else
    {
        MYSQL_RES *result = mysql_store_result(con);
        if (result == NULL)
        {
            finish_with_error(con);
        }
        int num_fields = mysql_num_fields(result);
        MYSQL_ROW row;
        char user_info[100];
        while ((row = mysql_fetch_row(result)))
        {
            gtk_list_store_append (model, &iter);
            gtk_list_store_set(model, &iter,0,row[1],1,row[2],2,row[3],3,row[4],4,row[5],5,row[6],6,row[7],-1);
        }
        mysql_free_result(result);
    }
    mysql_close(con);
}
void importercontact()
{
    FILE* fichier = NULL;
    personne p;
    char caractere;
    char fin[2];
    char *item_text="ami";
    char nom[300];
    char telephone[300];
    char ligne[300];
    fichier = fopen("contact.vcf", "r+");
    if (fichier != NULL)
    {
      do
        {
           caractere = fgetc(fichier); // On lit le caractère
           fin[0] = caractere;
           strcat(ligne,fin);
           if(caractere == '\n')
            {
            	if(strstr(ligne, "BEGIN:"))
            	{
            		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "VERSION:"))
            	{
            		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "N:;"))
            	{
            		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "FN:"))
            	{
            		strcpy(nom, ligne + 3);
            		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "N;"))
            	{
            		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "FN;"))
            	{
            		strcpy(nom, "sans nom");
              		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "TEL;CELL:"))
            	{
            		strcpy(telephone, ligne + 9);
            		//printf("nom: %s ",nom);
            		//printf("telephone: %s\n",telephone);
            		p.nom = nom;
			p.prenom = "a modifier";
			p.contact = telephone;
			p.adresse = "a modifier";
			p.email = "a modifier";
			//printf("%s, %s %s",p.nom,p.prenom,p.contact);
			insertion_dans_bd(p,item_text);
            		memset (ligne, 0, sizeof (ligne));
            		
            	}
            	if(strstr(ligne, "END:"))
            	{
            		
            		printf("\n");
            		memset (ligne, 0, sizeof (ligne));
            	}
            	
            }
        } while (caractere != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichier);
        
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}
*/

