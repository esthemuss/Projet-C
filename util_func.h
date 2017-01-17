typedef struct coocase Case;
struct coocase {
  int x;
  int y;
};

typedef struct candidats Cand;
struct candidats {
  int nbc;
  int * tab;
};

void ecrireGrille(int G[9][9]);
void lireGrille(int G[9][9]);
void initTab(Cand C[9][9],Case O[81],int G[9][9],int *NBO);
int estCandidat(int G[9][9],int i, int j, int nc);
int admetUnique(int i, int j,Cand C[9][9]);
void fermerGrille(int G[9][9]);
