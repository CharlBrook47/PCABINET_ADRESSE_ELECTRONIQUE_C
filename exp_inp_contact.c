#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    //int iteration = 0;
    char caractere;
    /*char bigin[100]="BEGIN:";
    char version[100]="VERSION:";
    char nom[100]="N:;";
    char prenom[100]="FN:";
    char numero[100]="TEL;CELL:";*/
    char *fin;
    char *trouver;
    char *ligne;
    //strcat(b,txte);CONCARTENATION
 
    fichier = fopen("contact.vcf", "r+");
    
 
    if (fichier != NULL)
    {
        /* On demande l'âge
        printf("Quel age avez-vous ? ");
        scanf("%d", &age);
 
        // On l'écrit dans le fichier
        fprintf(fichier, "Le Monsieur qui utilise le programme, il a %d ans", age);
        */
        
      do
        {
           caractere = fgetc(fichier); // On lit le caractère
           strcat(ligne,caractere);
           if(caractere != "\n")
            {
           	//trouver = strstr(ligne, prenom);
           	//fin = strstr(ligne, numero);
           	printf("%s", ligne);
           	ligne=NULL;
           	/*if(trouver!=NULL)
           	{
           		printf("%s",ligne);
           	}else if(fin!=NULL)
           	{
           		printf("%s",ligne);
           	}
           	ligne="";*/
           	
            }
             // On l'affiche
        } while (caractere != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

 
    return 0;
}
