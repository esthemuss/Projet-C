#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util_func.h"
#define TAILLE_MAX 6

void Debug(char msg[])
{
   printf("[DEBUG] : %s\n",msg);
};

void ecrireGrille(int G[9][9])
{
   int i,j;
   printf("=========================================\n");
   for(i=0;i<9;i++)
   {
      printf("|| ");
      for(j=0;j<9;j++)
      {
         if((j+1)%3==0)
            printf("%d || ", G[i][j] );
         else
            printf("%d | ", G[i][j] );
      }
      if ((i+1)%3==0)
         printf("\n=========================================\n");
      else
         printf("\n-----------------------------------------\n");
   }
};

void lireGrille() //Faire l'en-tête
{
   FILE* grille = NULL;
   int x,y,i,j,element,trouve;
   int G[9][9];
   char ligne[TAILLE_MAX];
   char nomfichier[100]; //le 100 est à changer je pense
   
   printf("Saisir le nom du fichier texte qui contient la grille.\n");
   scanf("%s",nomfichier);
   grille =  fopen(nomfichier,"r");
   
   while (grille == NULL)
   {
      printf("La grille \"%s\" n'a pas ete trouvee, merci de verifier le nom du fichier\n",nomfichier);
      scanf("%s",&nomfichier);
      grille =  fopen(nomfichier,"r");
   }
   for (i=0;i<9;i++)
      for (j=0;j<9;j++)
         G[i][j]=0;
   
   while (fscanf(grille, "%d %d %d", &x, &y, &element) != EOF )
   {
      trouve = 0;
      while (trouve == 0)
         for (i=0;i<9;i++)
            for (j=0;j<9;j++)
               if (x==i && y==j)
               {
                  G[x][y]= element;
                  trouve = 1;
               }    
   }
      
   ecrireGrille(G);

   fclose(grille);
}

void initTab(Cand C[],Case O[],int G[])
{
   int i,j,compteur,a = 0,nc;
   
   for (i=0;i<9;i++)
   {
      for (i=0;j<9;j++)
      {
         C[i][j].nbc = 0;
         compteur = 0;
         if (G[i][j] == 0)
         {
            O[a] = {i,j};
            for (nc=1;nc<=9;nc++)
            { 
               if (estCandidat(G,i,j,nc) == 1) // Encore a definir selon ce que sera la fonction estCandidat
               {
                  C[i][j].nbc = C[i][j].nbc + 1;
                  C[i][j].tab[compteur] = nc;
                  compteur =+ 1;  
               }
            }
         }
         else
         {
            C[i][j].nbc = 0;
            C[i][j].tab = NULL;
         }    
      }
   }
}