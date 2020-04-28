#include <stdio.h>
#include "fonction.h"

plateau p;


int main(void) {
  //printf("HelloWorld");

  srand(time(NULL));

  initEmpty(&p, 12, 12);
  printPlateau(&p, 12, 12);



  return 0;
}