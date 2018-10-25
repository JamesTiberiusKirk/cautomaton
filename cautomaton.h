#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int initRuleNGen(int **rule, int **gen, int genLength);
int printToFile(int *gen,char *fname);
int printGen(int *gen);
int compareRule(int a, int b, int c, int rule[7]);
int calculateNextGen(int *prevGen, int rule[7]);
int dectobin(int dec);
int decTOBinArr(int dec, int *rule);
