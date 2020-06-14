#include "fonction.h"

/* initEmpty
 *  Donne une valeur aléatoire entre 0 et 6 a toutes les cases du plateau.
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  nbColor - nombre entier corespondant au nombre de couleurs possible
*/
void initEmpty( plateau *ptr, int lin, int col, int nbColor){
  int x,y;

  (*ptr).lin = lin;
  (*ptr).col = col;
  for (x=0; x<lin; x++){
    for (y=0; y<col; y++){
      int ran = rand() % (nbColor) + 1;
      (*ptr).cases[x][y] = ran;
    }
  }
}

/* printMonde
 *  Affiche le plateau actuel.
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
void printPlateau(plateau *ptr, int lin, int col){
  const char *c[7] = {"","\033[0;31m■","\033[0;32m■","\033[0;33m■","\033[0;34m■","\033[0;35m■","\033[0;36m■"};

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
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
bool fin(plateau *ptr, int lin, int col){
  int val = (*ptr).cases[0][0],cmpt = 0;
  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if ((*ptr).cases[i][j] != val){
        return false;
      }
    }
  }
  return true;
}

/* process
 *  toutes les cases sont remisent à une valeur positive.
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
void process(plateau *ptr, int lin, int col){
  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      (*ptr).cases[i][j] = abs((*ptr).cases[i][j]);
    }
  }
}

/* Remplir
 *  Change les cases avec l'ancienne couleur avec la nouvelle couleur de manière récursive.
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  prevColor - Ancienne couleur
 *  newColor - Couleur choisie
 *  i - position i actuelle
 *  j - position j actuelle
*/
void remplir(plateau *ptr, int prevColor, int newColor, int i, int j){
  if (i >= 0 && j >= 0 && i < (*ptr).lin && j < (*ptr).col){
    if((*ptr).cases[i][j] == prevColor){
      (*ptr).cases[i][j] = -1*newColor;
      remplir(ptr, prevColor, newColor, i, j-1);
      remplir(ptr, prevColor, newColor, i, j+1);
      remplir(ptr, prevColor, newColor, i-1, j);
      remplir(ptr, prevColor, newColor, i+1, j);
    }
  }
}

/* floodArea
 *  Pose un flag sur les cases faisant parti de la même surface
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  color - Couleur de la surface
 *  i - position i actuelle
 *  j - position j actuelle
*/
void floodArea(plateau *ptr, int color, int i, int j){
  if (i >= 0 && j >= 0 && i < (*ptr).lin && j < (*ptr).col){
    if((*ptr).cases[i][j] == color){
      (*ptr).cases[i][j] = -1*color;
      floodArea(ptr, color, i, j-1);
      floodArea(ptr, color, i, j+1);
      floodArea(ptr, color, i-1, j);
      floodArea(ptr, color, i+1, j);
    }
  }
}

/* getArea
 *  return la surface et toutes les cases sont remisent à une valeur positive.
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
*/
int getArea(plateau *ptr, int lin, int col){
  int cmpt = 0;
  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if((*ptr).cases[i][j] < 0){
        cmpt++;
        (*ptr).cases[i][j] = abs((*ptr).cases[i][j]);
      }
    }
  }
  return cmpt;
}

/* perturbate
 *  Change de manière aléatoire, l case du plateau adverse.
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice du joueur 1
 *  plateau *aPerturber - pointeur qui pointe vers le plateau/matrice du jouer 2
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  nbColor - nombre entier corespondant au nombre de couleurs possible
 *  prevArea - taille de la surface avant de faire une action
*/
void perturbate(plateau *ptr, plateau *aPerturber, int lin, int col, int nbColor, int prevArea){
  int actuArea = getArea(ptr, lin, col);
  int nbModif = prevArea - actuArea;
  printf("nbModif : %i\t actuArea : %i\t prevArea : %i\n",nbModif, actuArea, prevArea);
  for (int i = 0; i < nbModif; i++){
    int l = rand() % lin;
    int c = rand() % col;
    int color = rand() % (nbColor) + 1;
    (*aPerturber).cases[l][c] = color;
    printf("l : %i\tc : %i\tcolor : %i\n",l,c,color);
  }
}

/* floodIt
 *  Boucle principal de jeu
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  nbColor - nombre entier corespondant au nobre de couleurs possible
*/
int floodIt(plateau *ptr, int lin, int col, int nbColor){
  plateau ordi;
  int ordiChoice = 0;
  initEmpty( &ordi, lin, col, nbColor);
  int choice = 0, cmpt = 0;
  initEmpty( ptr, lin, col, nbColor);
  while(choice >= 0 && !fin(ptr, lin, col) && !fin(&ordi, lin, col) && cmpt < 22){
    printPlateau(ptr, lin, col);
    printf("Ordinateur\n");
    int color = (*ptr).cases[0][0];
    floodArea(ptr, color, 0, 0);
    int colorOrdi = ordi.cases[0][0];
    floodArea(&ordi, colorOrdi, 0, 0);
    int prevArea = getArea(ptr, lin, col);
    int prevAreaOrdi = getArea(&ordi, lin, col);
    printPlateau(&ordi,lin,col);
    printf("\n\n      \033[1mnombre de coup joué : %i", cmpt);
    printf("\n\033[0mChoix : \n1) \033[0;31m■\n\033[0m2) \033[0;32m■\n\033[0m3) \033[0;33m■\n\033[0m4) \033[0;34m■\n\033[0m5) \033[0;35m■\n\033[0m6) \033[0;36m■\n\033[0m");
    scanf("%i", &choice);
    if (choice > 0 && choice <= nbColor){
      int i = 0; int j = 0;
      int prevColor = (*ptr).cases[0][0];
      remplir(ptr, prevColor, choice, i, j);
      process(ptr, lin, col);
      perturbate(ptr, &ordi, lin, col, nbColor, prevArea);
      cmpt++;
      int prevColorOrdi = (ordi).cases[0][0];
      remplir(&ordi, prevColorOrdi, (ordiChoice%nbColor)+1,0 , 0);
      process(&ordi, lin, col);
      perturbate(&ordi, ptr, lin, col, nbColor, prevAreaOrdi);
      ordiChoice++;
    }
    system("clear");
  }
  if (choice == -1){
    return 3;
  }
  else if (cmpt == 22){
    printf("\nDéfaite !");
  }
  else{
    printf("\nVictoire !");
  }
  return 0;
}