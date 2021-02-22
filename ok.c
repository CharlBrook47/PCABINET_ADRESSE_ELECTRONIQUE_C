#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    int i=0;
    int a=0;
    char caractere;
    char fin[2];
    char nom[300];
    char* pre = NULL;
    char telephone[300];
    char trouver[20]="FN:";
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
              		memset (ligne, 0, sizeof (ligne));
            	}
            	if(strstr(ligne, "TEL;CELL:"))
            	{
            		strcpy(telephone, ligne + 9);
            		printf("nom: %s ",nom);
            		printf("telephone: %s\n",telephone);
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
    return 0;
}
