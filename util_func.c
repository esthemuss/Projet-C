#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util_func.h"
#define TAILLE_MAX 3

void Debug(char msg)
{
   printf("[DEBUG] : %s\n",msg);
};

void lireGrille() //Faire l'en-tête
{
   FILE* grille = NULL;
   char ligne[TAILLE_MAX];
   char nomfichier[1000]; //le 1000 est à changer je pense
   
   printf("Saisir le nom du fichier texte qui contient la grille.\n");
   scanf("%s",nomfichier);
   grille =  fopen(nomfichier,"r");
   
   while (grille == NULL)
   {
      printf("La grille n'a pas ete trouvee, merci de verifier le nom du fichier\n");
      scanf("%s",nomfichier);
      grille =  fopen(nomfichier,"r");
   }
   
   while (fgets(ligne, TAILLE_MAX, grille) != NULL)
   {
      printf("%s", ligne);
   }
   
   fclose(grille);

}

void ecriregrille(int grille)
{
   int i,j;
   for(i=0;i<9;i++)
   {
      for(j=0;j<9;j++)
      {
         printf("%d ",grille[i][j]);
      }
      printf("\n");
   }
}

void initTab(Cand C[], int O[])
{
   
}