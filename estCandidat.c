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

Cand estCandidat() //Faire l'entête
{
   int i,j,k, ligne, colonne;
   int candligne, candcolonne, candcase;
   candligne = 1;
   candcolonne = 1;
   candcase = 1;
   C[i][j].nbc = 0;
   C[i][j].tab = NULL
   
      
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
                  
                  
                  switch(i)
                  {  
                     case(i>=0 && i<=2):
                        switch(j)
                        {
                           case((j>=0 && j<=2)):
                              for(i=0,j=0;i<=2,j<=2;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                           case(j>=3 && j<=5):
                              for(i=0,j=3;i<=2,j<=5;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                           case(j>=6 && j<=8):
                              for(i=0,j=6;i<=2,j<=8;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                        };
                        break;
                        
                     case(i>=3 && i<=5):
                        switch(j)
                        {
                           case((j>=0 && j<=2)):
                              for(i=3,j=0;i<=5,j<=2;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                           case(j>=3 && j<=5):
                              for(i=3,j=3;i<=5,j<=5;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                           case(j>=6 && j<=8):
                              for(i=3,j=6;i<=5,j<=8;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                        };
                        break;
                     
                     case(i>=6 && i<=8):
                        switch(j)
                        {
                           case((j>=0 && j<=2)):
                              for(i=6,j=0;i<=8,j<=2;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                              
                           case(j>=3 && j<=5):
                              for(i=6,j=3;i<=8,j<=5;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;

                              
                           case(j>=6 && j<=8):
                              for(i=6,j=6;i<=8,j<=8;i++,j++)
                              {
                                 if(k!=G[i][j])
                                    candcase = 0;
                              };
                              break;
                               
                        };
                        break;
                     
                  }; 
                   
                  if(candligne=0 && candcolonne=0 && candcase=0)
                  {
                     C[i][j].nbc = C[i][j].nbc++;
                     C[i][j].tab = C[i][j].tab*10 + k;
                     NBO = NBO-1;
                  };
               };
            };
         };
      };
   };
   
   return C;      
}