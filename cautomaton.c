#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cautomaton.h"

int printToFile(int *gen,char *fname){ 
    FILE *f=fopen(fname,"a");
  
    if(f == NULL){
        printf("Error opening file\n");
        return 1;
    }

    size_t genLength = sizeof(gen)/sizeof(int); 
    for(int i=0;i<genLength;i++){
        if(gen[i]==1){
            fprintf(f,"\u25A0");
            fprintf(f,"\u25A0");
        }else{
            fprintf(f,"  "); 
        }
    }
    fprintf(f,"|\n");
    
    fclose(f);
    return 0;
}

int printGen(int *gen){
    size_t genLength=sizeof(gen)/sizeof(int);
    for(int i=0;i<genLength;i++){
        if(gen[i]==1){
            printf("\u25A0");
            printf("\u25A0");
        }else{
            printf("  "); 
        }
    }
    printf("|\n");
    return 0;
}

int compareRule(int a, int b, int c, int rule[7]){
    if(a==1 && b==1 && c==1){return rule[0];}
    if(a==1 && b==1 && c==0){return rule[1];}
    if(a==1 && b==0 && c==1){return rule[2];}
    if(a==1 && b==0 && c==0){return rule[3];}
    if(a==0 && b==1 && c==1){return rule[4];}
    if(a==0 && b==1 && c==0){return rule[5];}
    if(a==0 && b==0 && c==1){return rule[6];}
    if(a==0 && b==0 && c==0){return rule[7];}
    return -1;
}

int calculateNextGen(int *prevGen, int rule[7]){
    size_t genLength=sizeof(prevGen)/sizeof(int);

    int nextGen[genLength];
    int a,b,c;
    
    for(int i=0;i<genLength;i++){
        if(i==0){
            a=prevGen[genLength-1];
            b=prevGen[i];
            c=prevGen[i+1];
        }else if(i==genLength-1){
            a=prevGen[i-1];
            b=prevGen[i];
            c=nextGen[0];
        }else{
            a=prevGen[i-1];
            b=prevGen[i];
            c=prevGen[i+1];
        }
        nextGen[i]=compareRule(a,b,c,rule);
        
    }
    memcpy(prevGen, nextGen, genLength * sizeof(int));
    return 0;
}

int dectobin(int dec){
    if (dec == 0){
        return 0;
    }else{
        return (dec % 2 + 10 * dectobin(dec / 2));
    }
}

int decTOBinArr(int dec, int *rule){
    if (dec>255){
        return 1;
    }
        
    int bin=dectobin(dec);
    
    size_t genLength=sizeof(rule)/sizeof(int);
   
    int tmpRule[7]; 
    tmpRule[6] = bin%10;
    tmpRule[5] = (bin/10)%10;
    tmpRule[4] = (bin/100)%10;
    tmpRule[3] = (bin/1000)%10;
    tmpRule[2] = (bin/10000)%10;
    tmpRule[1] = (bin/100000)%10;
    tmpRule[0] = (bin/1000000)%10;
    
        
    memcpy(rule,tmpRule, genLength * sizeof(int));

    /*for(int i=6;i>=0;i--){
        
    }*/







    return 0;
}
