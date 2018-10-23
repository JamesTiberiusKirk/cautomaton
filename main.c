#include<stdio.h>
#include<stdlib.h>
#include"cautomaton.h"

int main(int argc, char *argv[]){
    int bin = dectobin(30);    
    printf("%d\n", bin);
    
    int *rule[7];
    decTOBinArr(30,*rule);
    for(int i=0;i<7;i++){
        printf("%ls",rule[i]);
    }

    return 0;
}
