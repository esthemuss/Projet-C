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

Cand estCandidat() //Faire l'ent�te
{
   int i,j,k, ligne, colonne;
   int candligne, candcolonne, candcase;
   candligne = 1;
   candcolonne = 1;
   candcase = 1;
   nbc = 0;
   tab = NULL;
   
      
   while(NBO!=0)
   { 
     for(i=0;i<=8;i++)
     {
        for(j=0;j<=8;j++)
        {      
            if(G[i][j]=0)
            {
               for(k=1;k<=9;k++)
               {    
                  for(ligne=0;ligne<=8;ligne++)
                  {
                     if(k!=G[ligne][j])
                        candligne = 0; 
                  };
                  
                  for(colonne=0;colonne<=8;colonne++)
                  {
                     if(k!=G[i][colonne])
                        candcolonne = 0;
                  };
                  
                  if(i>=0 && i<=2 && j>=0 && j<=2)
                  {  
                  else if(i>=0 && i<=2 && j>=3 && j<=5)
                     
                  else if(i>=0 && i<=2 && j>=6 && j<=8)
                     
                  else if(i>=3 && i<=5 && j>=0 && j<=2)
                     
                  else if(i>=3 && i<=5 && j>=3 && j<=5)
                     
                  else if(i>=3 && i<=5 && j>=6 && j<=8)
                     
                  else if(i>=6 && i<=8 && j>=0 && j<=2)
                     
                  else if(i>=6 && i<=8 && j>=3 && j<=5)
                     
                  else if(i>=6 && i<=8 && j>=6 && j<=8)
                     
                  };  
                  if(candligne=0 && candcolonne=0)
                  {
                     nbc = nbc++;
                     tab = k;
                  };
               };
            };
         };
      };
   };      
}