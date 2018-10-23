#include<stdio.h>
#include<stdlib.h>
#include"cautomaton.h"

int main(int argc, char *argv[]){
    int bin = dectobin(30);    
    printf("%d\n", bin);
    
    int rule[7]={0,0,0,0,0,0,0} ;
    
    size_t genLength= sizeof(rule)/sizeof(int);
    printf("the size is %ld\n",genLength); 

    
    decTOBinArr(30,&rule);
    for(int i=0;i<7;i++){
        printf("%d",rule[i]);
    }

    return 0;
}
