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
  //int coupsEff[21];
} plateau;



void initEmpty( plateau *ptrm, int lin, int col, int nbColor);
void printPlateau(plateau *ptrm, int lin, int col);
void remplir(plateau *ptr, int prevColor, int newColor, int i, int j);
void process(plateau *ptr, int lin, int col);
int floodIt(plateau *ptr, int lin, int col, int nbColor);
bool fin(plateau *ptr, int lin, int col);
void floodArea(plateau *ptr, int color, int i, int j);
int getArea(plateau *ptr, int lin, int col);
void perturbate(plateau *ptr, plateau *aPerturber, int lin, int col, int nbColor, int prevArea);


bool initEmptyTest(plateau *ptr, int lin, int col, int nbColor);
bool finTest(plateau *ptr, int lin, int col, bool fin);
bool floodTest(plateau *ptr, plateau *ptr2, int lin, int col, int prevColor, int newColor);
bool areaFloodTest(int ans, int res);

#endif