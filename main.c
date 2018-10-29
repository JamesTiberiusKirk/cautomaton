#include<stdio.h>
#include<stdlib.h>
#include"cautomaton.h"

int main(int argc, char *argv[]){
    int bin = dectobin(30);    
    printf("%d\n", bin);

    int *rule;
    int *gen;

    initRuleNGen(&rule,&gen,32);
    //gen[16]=1;
    //rule = (int*)malloc(sizeof(int)*8);

    size_t genLength= sizeof(rule)/sizeof(int);
    printf("the size is %ld\n",genLength); 

    
    decTOBinArr(30,rule);
    for(int i=0;i<8;i++){
        printf(" %d ",rule[i]);
    }
    printf("\n");
    return 0;
}
