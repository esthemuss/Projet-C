#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util_func.h"
#define TAILLE_MAX 3

void ecrireGrille(int G[9][9])
{
   printf("Rentre dans ecrireGrille\n");
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
   printf("Fin de ecrireGrille\n");
};

void lireGrille(int G[9][9]) //Faire l'en-tête
{
   FILE* grille = NULL;
   int x,y,i,j,element,trouve;
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

   //fclose(grille);
   printf("Ici ca va ^^");

}

void initTab(Cand C[9][9],Case O[81],int G[9][9],int *NBO)
{
   printf("Rentre dans l'inittab \n");

   int i,j,compteur,nc,a = 0;
   for (i=0;i<9;i++)
   {
      for (j=0;j<9;j++)
      {
         C[i][j].nbc = 0;
            C[i][j].tab = malloc(9 * sizeof(int));
         compteur = 0;
         if (G[i][j] == 0)
         {
            printf("Fais le test de G[i][j] == 0 \n");
            O[a].x = i;
            O[a].y = j;
            a =+ 1;
            *NBO = a;
            for (nc=1;nc<=9;nc++)
            { printf("Est candidat test avant for %d \n",estCandidat(G,i,j,nc));
               if (estCandidat(G,i,j,nc) == 0)
               {
                  printf("plop 0\n");
                  C[i][j].nbc =+ 1;
                  printf("plop 01\n");
                  C[i][j].tab[compteur] = nc;
                  printf("plop 02\n");
                  compteur =+ 1;
               }
            }
         }
         else
         {
            C[i][j].nbc = 0;
            C[i][j].tab = NULL;
            printf("plop NULL");
         }
      }
   }
   printf("Sort de l'inittab \n");
}

int estCandidat(int G[9][9],int i, int j, int nc)
{
   printf("Rentre dans est candidat\n");
   int ligne, colonne;
   int candligne, candcolonne;
   int x, y;
   x = i%3;
   y = j%3;
   candligne = 1;
   candcolonne = 1;

   for(ligne=0;ligne<=8;ligne++)
   {
      if(nc != G[ligne][j])
         candligne = 0;
   };

   for(colonne=0;colonne<=8;colonne++)
   {
      if(nc!=G[i][colonne])
         candcolonne = 0;
   };
   
   printf("plop 1 !");

   i = i-x;
   j = j-y;

   for(i=0;i<=2;i++)
   {
      for(j=0;j<=2;j++)
      {
         if(nc==G[i][j])
            return 1;
      };
   };
   printf("plop 2 !");
   
   printf("se barre de  estcandidat\n");

   if(candligne == 0 && candcolonne == 0)
      return ;
      
   printf("se barre de  estcandidat\n");

};

int admetUnique(int i, int j,Cand C[9][9])
{
   printf("Rentre dans admetunique\n");
   if (C[i][j].nbc==1)
      return C[i][j].tab[0];
   else
      return 0;
};

void fermerCase(int x,int y,int candidat,int G[9][9],Cand C[9][9],Case O[81])
{
   printf("Rentre dans fermercase\n");
   int a;
   G[x][y]=candidat;
   initTab(C,O,G,&a);
}

void ecrireCand(Cand C[9][9])
{
   printf("Rentre dans ecireCand\n");
   int x,y,i;
   for (x=0,y=0;x<81;x++,y++)
      if (C[x][y].nbc!=0 && C[x][y].tab!=NULL)
         for(i=0;i<C[x][y].nbc;i++)
            printf("[%d] [%d] : %d",x,y,C[x][y].tab[i]);
}

void fermerGrille(int G[9][9])
{
   printf("Rentre dans fermergrille \n");
   Cand C[9][9];
   Case O[81] = {0};
   int NBO, candidat, nbcandidat,i,j;


   initTab(C,O,G,&NBO);
   printf("Fin d'un initab \n");
   while(NBO!=0 && nbcandidat==NBO)
   {
      printf("rentre dans un while \n");
      nbcandidat = 0;
      for(i=0;i<=NBO;i++)
      {
         candidat = admetUnique(O[NBO].x,O[NBO].y,C);
      
         if (candidat!=0)
            fermerCase(O[NBO].x,O[NBO].y,candidat,G,C,O);
         nbcandidat = nbcandidat+1;
      };
   
   };

   ecrireCand(C);
   ecrireGrille(G);
};
