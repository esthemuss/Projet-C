// D�but des conneries sur le projet C

#include <stdio.h>
#include <stdlib.h>
#include "util_func.c"


void lireGrille(int tab,char fichiertxt[25])
{
   char nomfichier;

   FILE* grille = NULL;

   grille =  fopen(fichiertxt,"r");

   while (grille == NULL)
      {
         printf("La grille n'a pas ete trouvee, merci de verifier le nom du fichier")
         scanf("%s",nomfichier)
         grille =  fopen(fichiertxt,"r");
      }

      // Ici début du test pour vérifier la lecture du fichier
    do
      {
         caractereActuel = fgetc(fichier);
         printf("%c", caractereActuel);
      } while (caractereActuel != EOF);
      // Fin du test
}
