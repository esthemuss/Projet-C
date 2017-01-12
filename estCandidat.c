#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util_func.h"
#define TAILLE_MAX 3

void Debug(char msg)
{
   printf("[DEBUG] : %s\n",msg);
};

void lireGrille() //Faire l'en-tÃªte
{
   FILE* grille = NULL;
   char ligne[TAILLE_MAX];
   char nomfichier[1000]; //le 1000 est Ã  changer je pense
   
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

Cand estCandidat(int G[],int i, int j, int nc)
{
   int ligne, colonne;
   int candligne, candcolonne;
   int x, y;
   x = i%3
   y = j%3
   candligne = 1;
   candcolonne = 1;
   
   for(ligne=0;ligne<=8;ligne++)
   {
     if(nc!=G[ligne][j])
        candligne = 0; 
   };
                  
   for(colonne=0;colonne<=8;colonne++)
   {
       if(nc!=G[i][colonne])
            candcolonne = 0;
   };
   
   i = i-x
   j = j-y
   
   for(i=0;i<=2;i++)
   {
      for(j=0;j<=2;j++)
      {
        if(nc==G[i][j])
           return 1;
      };
   };
   
   if(candligne=0 && candcolonne=0)
      return 0;
      
};

int admetUnique(int i, int j)
{
   if C[i][j].nbc==1
         return C[i][j].tab[0];
   else
      return 0;
};

void fermerGrille(int G[9][9])
{
   Cand C[9][9];
   Case O[81];
   int NBO, candidat, nbcandidat;
   
   
   initTab(C[9][9],O[81],int G[9][9],&NBO);
   
   while(NBO!=0 || nbcandidat==NBO)
   {
      nbcandidat = 0
         for(i=0;i<=NBO;i++)
         {
            candidat = admetUnique(O[NBO].x,O[NBO].y);
         
            if candidat!=0
               fermerCase(O[NBO].x,O[NBO].y,candidat,G[9][9],C[9][9],O[81]);
               nbcandidat = nbcandidat+1
         };
   
   };
   
   ecrireCand(C[9][9])
   ecrireGrille(G[9][9]);
};