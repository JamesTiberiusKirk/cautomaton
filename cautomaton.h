#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"./cautomaton.h"


int printToFile(int *gen,char *fname);
int printGen(int *gen);
int compareRule(int a, int b, int c, int rule[7]);
int calculateNextGen(int *prevGen);
