#include "fonction.h"

/* initEmpty
 *  Donne une valeur aléatoire entre 0 et 6 a toutes les cases du plateau.
 *  
 * Parametres :
 *  plateau *ptrm - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
void initEmpty( plateau *ptr, int lin, int col){
  int x,y;

  (*ptr).lin = lin;
  (*ptr).col = col;
  for (x=0; x<lin; x++){
    for (y=0; y<col; y++){
      int ran = rand() % 6;
      (*ptr).cases[x][y] = ran;
    }
  }
}

/* printMonde
 *  Affiche le plateau actuel.
 *  
 * Parametres :
 *  plateau *ptrm - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
void printPlateau(plateau *ptr, int lin, int col){
  const char *c[6] = {"\033[0;31m■","\033[0;32m■","\033[0;33m■","\033[0;34m■","\033[0;35m■","\033[0;36m■"};

  (*ptr).lin = lin;
  (*ptr).col = col;
  int x,y; 
  for (x=0; x<lin; x++){
    for (y=0; y<col; y++){
      printf(" %s ", c[(*ptr).cases[x][y]]);
    }
    printf("\n");
  }
  printf("\033[0m");
}


/* fin
 *  Vérifie si toutes les cases sont les mêmes
 *  
 * Parametres :
 *  plateau *ptrm - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
bool fin(plateau *ptr, int lin, int col){
  int val = (*ptr).cases[0][0],cmpt = 0;
  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if ((*ptr).cases[i][j] != val){
        cmpt++;
      }
    }
  }
  if (cmpt > 0){
    return false;
  }
  else{
    return true;
  }
}