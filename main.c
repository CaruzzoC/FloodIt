#include <stdio.h>
#include "fonction.h"

plateau p;

plateau pRemplir;
plateau pTest;


int main(void) {
  //printf("HelloWorld");

  srand(time(NULL));
  system("clear");
  //=====================Zone de Test==========================
  
  pRemplir.lin=2;
  pRemplir.col=2;
  pRemplir.cases[0][0] = 1;
  pRemplir.cases[0][1] = 1;
  pRemplir.cases[1][0] = 1;
  pRemplir.cases[1][1] = 2;
  
  
  pTest.lin=2;
  pTest.col=2;
  pTest.cases[0][0] = 2;
  pTest.cases[0][1] = 2;
  pTest.cases[1][0] = 2;
  pTest.cases[1][1] = 2;
  

  //printf("%i",floodTest(&pRemplir, &pTest, 2, 2, 1, 2));

  //floodArea(&pRemplir, pRemplir.cases[0][0], 0, 0);
  //printf("%i",areaFloodTest(getArea(&pRemplir, 12, 2), 3));

  //initEmpty(&p, 12, 12, 6);
  //printf("%i",finTest(&p, 12, 12, fin(&p, 12, 12)));
  //printf("%i",initEmptyTest(&p, 12, 12, 6));
  //floodTest(plateau *ptr, int **plateau2, int lin, int col, int prevColor, int newColor);

  perturbate(&pRemplir, &pRemplir, 2, 2, 2, 1);
  printf("%i",perturbateTest(&pRemplir, &pRemplir, 2, 2, 1));
  //========================================================


  
  //initEmpty(&p, 12, 12, 6);
  //printPlateau(&p, 12, 12);
  //floodArea(&p, p.cases[0][0], 0, 0);
  //printf("%i",getArea(&p, 12, 2));

  /*
  int size = 0;
  int nbColor = 0;
  printf("Taille du plateau (2-28): ");
  scanf("%i", &size);
  if (size > 28){
    size = 28;
  }
  else if(size <= 1){
    size = 2;
  }
  printf("Couleurs différente (2-6): ");
  scanf("%i", &nbColor);
  if (nbColor > 6){
    nbColor = 6;
  }
  else if (nbColor <= 1){
    nbColor = 2;
  }
  floodIt(&p, size, size, nbColor);
  */

  return 0;
}