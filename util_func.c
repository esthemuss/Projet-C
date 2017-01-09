#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 6

void Debug(char msg[])
{
   printf("[DEBUG] : %s\n",msg);
};

void main() //Faire l'en-tête
{
   FILE* grille = NULL;
   int x,y,element;
   int i,j;
   int G[9][9];
   char ligne[TAILLE_MAX];
   char nomfichier[100]; //le 100 est à changer je pense
   
   printf("Saisir le nom du fichier texte qui contient la grille.\n");
   scanf("%s",nomfichier);
   grille =  fopen(nomfichier,"r");
   
   while (grille == NULL)
   {
      printf("La grille n'a pas ete trouvee, merci de verifier le nom du fichier\n");
      scanf("%s",nomfichier);
      grille =  fopen(nomfichier,"r");
   }
   Debug("Début");
   for (i=0;i<9;i++)
   {
      for (j=0;j<9;j++)
      {
         fscanf(grille, "%d %d %d", x, y, element);
         if (x==i && y==j)
            G[x][y]=element;
         else
            G[x][y]=0;
      }  
   }
   Debug("Fin");
   
   /*
   while (fscanf(grille, "%d %d %d", x, y, element) != EOF)
      G[x][y]=element;
      
     
    (fgets(ligne, TAILLE_MAX, grille) != NULL)
   {
      printf("%s", ligne);
   }
   */
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