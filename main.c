// D�but des conneries sur le projet C

#include <stdio.h>
#include <stdlib.h>

char

void lireGrille(int tab,char fichiertxt[25])
{
   char nomfichier;
   
   FILE* grille = NULL;
   
   grille =  fopen(fichiertxt,"r");
   
   while (grille == NULL)
      {
         printf("La grille n'a pas �t� trouv�e, merci de v�rifier le nom du fichier")
         scanf("%s",nomfichier)
         grille =  fopen(fichiertxt,"r");
      }
  
}


)

main()
{
}