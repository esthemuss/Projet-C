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

   printf("se barre de  estcandidat\n");

   if(candligne == 0 && candcolonne == 0)
      return 0;

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

void rechDich(int T[],int nb, int val, int *b, int *pos)
{
   int bi=0,bs=nb,m;

   while (*b == 0 && bi <= bs)
   {
      m = (bi+bs)/2;
      if (T[m] = val)
      {
         *pos = m;
         *b = 1;
      }
      else if (T[m] > val)
         bs = m - 1;
      else
         bi = m +1;
   }
}

void suppVal(int T[],int *nb,int nbas,int pos)
{
   int i;
   for (i=pos;i<*nb;i++)
      T[i] = T[i+1];
   *nb = *nb -1;
}

void fermerCase(int x,int y,int candidat,int G[9][9],Cand C[9][9],Case O[81])
{
   printf("Rentre dans fermer case \n" );
   G[x][y] = candidat;
   int a,b; // Booleens pour si le chiffre existe apr�s recherche dicho
   int posa,posb; // Recuperation des positions ou enlever les candidat dans C
   int i,j;
   int x2,y2; // Variables utiles pour la recherche au sein d'une "grande case" de neuf
   x2 = x%3;
   y2 = y%3;
   for (i=0;i<9;i++)
   {
      a = 0;
      b = 0;
      printf("Plop01 !");
      rechDich(C[x][i].tab,C[x][i].nbc,candidat,&a,&posa);
      printf("Plop01 bis!");
      rechDich(C[x][i].tab,C[i][y].nbc,candidat,&b,&posb);
      printf("Plop01 bis bis!");
      if (a == 1)
      {
        printf("Plop02 !");
         suppVal(C[x][i].tab,&C[x][i].nbc,candidat,posa);
      };
      if (b == 1)
      {
         printf("Plop03 !");
         suppVal(C[x][i].tab,&C[x][i].nbc,candidat,posa);
         printf("Plop03bis !");
      };
    };
    i = x - x2;
    j = y - y2;
    printf("Plop04 !");
    for(x2=0;x2<=2;x2++)
    {
       for(y2=0;y2<=2;y2++)
       {
          rechDich(C[x2][y2].tab,C[x2][y2].nbc,candidat,&a,&posa);
          if (a == 0)
          {
            suppVal(C[x][i].tab,&C[x][i].nbc,candidat,posa);
            a = 0;
          };
       };
    };

printf("Sortir de fermercase \n" );
};

void ecrireCand(Cand C[9][9])
{
   printf("Rentre dans ecireCand\n");
   int x,y,i;
   for (x=0,y=0;x<81;x++,y++)
      if (C[x][y].nbc!=0 && C[x][y].tab!=NULL)
         for(i=0;i<C[x][y].nbc;i++)
            printf("[%d] [%d] : %d \n",x,y,C[x][y].tab[i]);
}

void fermerGrille(int G[9][9])
{
   printf("Rentre dans fermergrille \n");
   Cand C[9][9];
   Case *O = calloc(81,sizeof(int));
   int NBO, candidat, nbcandidat,i,j;


   initTab(C,O,G,&NBO);
   printf("Fin d'un initab \n");
   while(NBO!=0)
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
