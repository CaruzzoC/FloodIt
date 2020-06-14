#include "fonction.h"

/* initEmptyTest
 *  Fonction de test de la fonction initEmpty
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  nbColor - nombre entier corespondant au nobre de couleurs possible
*/
bool initEmptyTest(plateau *ptr, int lin, int col, int nbColor){
  initEmpty( ptr, lin, col, nbColor);
  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if ((*ptr).cases[i][j] < 1 || (*ptr).cases[i][j] > nbColor){
        return false;
      }
    }
  }
  return true;
}

/* finTest
 *  Fonction de test de la fonction fin
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  fin - resultat de la fonction fin()
*/
bool finTest(plateau *ptr, int lin, int col, bool fin){
  int color = (*ptr).cases[0][0];
  for(int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      if (color != (*ptr).cases[i][j] && fin){
        return false;
      }
      else if (color != (*ptr).cases[i][j] && !fin){
        return true;
      } 
    }
  }
  if (fin){
    return true;
  }
  else{
    return false;
  }
}

/* floodTest
 *  Fonction de test de la fonction remplir et process
 *  
 * Parametres :
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  plateau *ptr2 - pointeur qui pointe vers le plateau/la matrice de test
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  prevColor - Ancienne couleur
 *  newColor - Couleur choisie
*/
bool floodTest(plateau *ptr, plateau *ptr2, int lin, int col, int prevColor, int newColor){
  remplir(ptr, prevColor, newColor, 0, 0);
  process(ptr, lin, col);
  for(int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      if((*ptr).cases[i][j] != (*ptr2).cases[i][j]){
        return false;
      }
    }
  }
  return true;
}

/* finTest
 *  Fonction de test de la fonction floodArea et getArea
 *  
 * Parametres :
 *  ans - valeur retourné par la fonction getArea
 *  res - resultat attendu par la fonction getArea
*/
bool areaFloodTest(int ans, int res){
  if(ans == res){
    return true;
  }
  else{
    return false;
  }
}

/* PerturbateTest
 *  Fonction de test de la fonction perturbate
 *  
 *  plateau *ptr - pointeur qui pointe vers le plateau/la matrice
 *  plateau *ptr2 - pointeur qui pointe vers le plateau/la matrice
 *  lin - nombre de lignes composant le plateau
 *  col - nombre de lignes composant le plateau
 *  caseModifie - delta surface
*/
bool perturbateTest(plateau *ptr, plateau *ptr2, int lin, int col, int caseModifie){
  int cmpt;
  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if ((*ptr).cases[i][j] != (*ptr2).cases[i][j]){
        cmpt++;
      }
    }
  }
  if(cmpt == caseModifie){
    return true;
  }
  else{
    return false;
  }
}