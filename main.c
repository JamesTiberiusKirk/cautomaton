#include<stdio.h>
#include<stdlib.h>
#include"./cautomaton.h"



int main(int argc, char *argv[]){
    //char ruleDec = *argv[1];
    char *p;
    int ruleInt = strtol(argv[1],&p,10);
    
    char *bin;
    binToString(ruleInt,0,&bin);
            
    printf("%s\n",*bin);
    
    return 0;
}
