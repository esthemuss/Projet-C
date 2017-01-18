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

   int i,j,compteur,nc = 1,a = 0,b;
   for (i=0;i<9;i++)
   {
      for (j=0;j<9;j++)
      {
         C[i][j].nbc = 0;
         C[i][j].tab = malloc(9 * sizeof(int));
         compteur = 0;
         printf("Fais le test de G[%d][%d] == %d \n",i,j,G[i][j]);
         if (G[i][j] == 0)
         {
            O[a].x = i;
            O[a].y = j;
            a++;
            *NBO = a;
            for (nc=1;nc<=9;nc++)
            {
              printf("nc = %d \n",nc);
               if (estCandidat(G,i,j,nc) == 0)
               {

                  C[i][j].nbc = C[i][j].nbc + 1;
                  C[i][j].tab[compteur] = nc;
                  printf("Contenu de tab : %d \n",C[i][j].tab[compteur]);
                  compteur++;
                  printf("Le compteur est a : %d \n",compteur);
                  for (b=0;b<C[i][j].nbc;b++)
                   printf("Le contenu de la table C[%d][%d].tab[%d] = %d \n",i,j,b,C[i][j].tab[b]);
               };

            };

         }
         else
         {
            C[i][j].nbc = 0;
            C[i][j].tab = NULL;
            printf("plop NULL \n");
         };
      };
   };
   printf("Sort de l'inittab \n");
};

int estCandidat(int G[9][9],int i, int j, int nc)
{
   printf("Rentre dans est candidat\n");
   int estcand = 0,a,b;
   // Test pour ligne
   for(a=0;a<9;a++)
     if(nc == G[a][j])
        estcand = 1;

        // pour colonne
    for(b=0; b<9; b++)
      if(nc==G[i][b])
        estcand = 1;



// Pour section de 9 cases
  int x1, x2, y1, y2;

  if(i >=0 && i<3)
  {
    x1=0;
    x2=2;
  }
  else if(i>2 && i<6)
  {
    x1=3;
    x2=5;
  }
  else if(i>5 && i<=8)
  {
    x1=6;
    x2=8;
  }


  if(j >=0 && j<3)
  {
    y1=0;
    y2=2;
  }
  else if(j>2 && j<6)
  {
    y1=3;
    y2=5;
  }
  else if(j>5 && j<=8)
  {
    y1=6;
    y1=8;
  }

//tester la section

  for(a=x1; a<=x2;a++)
    for(b=y1; b<=y2;b++)
       if(nc == G[i][j])
        estcand = 1;
   return estcand;

   printf("se barre de  estcandidat\n");

};

int admetUnique(int i, int j,Cand C[9][9])
{
   printf("Rentre dans admetunique\n");
   if (C[i][j].nbc == 1)
      return C[i][j].tab[0];
   else
      return 0;
};

void rechDich(int T[],int nb, int val, int *bl, int *pos)
{
   int bi=0,bs=nb,m;

   while (*bl == 0 && bi <= bs)
   {
      m = (bi+bs)/2;
      if (T[m] = val)
      {
         *pos = m;
         *bl = 1;
      }
      else if (T[m] > val)
         bs = m - 1;
      else
         bi = m +1;
   };
};

void suppVal(int T[],int *nb,int nbas,int pos)
{
   int i;
   for (i=pos;i<*nb;i++)
      T[i] = T[i+1];
   *nb = *nb -1;
};

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
      rechDich(C[i][y].tab,C[i][y].nbc,candidat,&b,&posb);
      printf("Plop01 bis!");
      rechDich(C[x][i].tab,C[x][i].nbc,candidat,&a,&posa);
      printf("Plop01 bis bis!");
      if (a == 1)
      {
        printf("Plop02 !");
         suppVal(C[x][i].tab,&C[x][i].nbc,candidat,posa);
      };
      if (b == 1)
      {
         printf("Plop03 !");
         suppVal(C[i][y].tab,&C[x][i].nbc,candidat,posa);
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
            suppVal(C[x2][y2].tab,&C[x2][y2].nbc,candidat,posa);
            a = 0;
          };
       };
    };

printf("Sortir de fermercase \n" );
};

void ecrireCand(Cand C[9][9])
{
   printf("Rentre dans ecrireCand\n");
   int x,y,i;
   for (x=0;x<9;x++)
      for (y=0;y<9;y++)
      if (C[x][y].nbc!=0 && C[x][y].tab!=NULL)
         for(i=0;i<C[x][y].nbc;i++)
            printf("[%d] [%d] : %d \n",x,y,C[x][y].tab[i]);
}
void fermerGrille(int G[9][9])
{
   printf("Rentre dans fermergrille \n");
   Cand C[9][9];
   Case O[81];
   int NBO, candidat, nbcandidat,i,j;


   initTab(C,O,G,&NBO);
   printf("Fin d'un initab \n");
   for(i=0;i<NBO;i++)
    printf("O[%d] = { x = %d | y = %d } \n",i,O[i].x,O[i].y);
   while(NBO != 0 )
   {
      printf("rentre dans un while \n");
      nbcandidat = 0;
      for(i=0;i<=NBO;i++)
      {
         candidat = admetUnique(O[NBO].x,O[NBO].y,C);

         if (candidat != 0)
            fermerCase(O[NBO].x,O[NBO].y,candidat,G,C,O);
      };

   };

   ecrireCand(C);
   ecrireGrille(G);
};
