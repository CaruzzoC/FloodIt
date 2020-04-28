#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct {
  int lin, col;
  int cases[28][28];
  int nbCoup;
} plateau;




void initEmpty( plateau *ptrm, int lin, int col);
void printPlateau(plateau *ptrm, int lin, int col);


#endif