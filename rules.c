#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int rule30[] = {0,0,0,1,1,1,1,0};
int prevGen[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int genLength = 32;


int printToFile(int gen[genLength],char *fname){ 
    FILE *f=fopen(fname,"a");
  
    if(f == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    
    for(int i=0;i<genLength;i++){
        //printf(" %d ",gen[i]);
        if(gen[i]==1){
            fprintf(f,"\u25A0");
            fprintf(f,"\u25A0");
        }else{
            //printf("\u25A1");
            fprintf(f,"  "); 
        }
    }
    fprintf(f,"|\n");
    
    fclose(f);
    return 0;
}

int printGen(int gen[genLength]){
    for(int i=0;i<genLength;i++){
        //printf(" %d ",gen[i]);
        if(gen[i]==1){
            printf("\u25A0");
            printf("\u25A0");
        }else{
            //printf("\u25A1");
            printf("  "); 
        }
    }
    printf("|\n");
    return 0;
}

int compareRule(int a, int b, int c){
    if(a==1 && b==1 && c==1){return rule30[0];}
    if(a==1 && b==1 && c==0){return rule30[1];}
    if(a==1 && b==0 && c==1){return rule30[2];}
    if(a==1 && b==0 && c==0){return rule30[3];}
    if(a==0 && b==1 && c==1){return rule30[4];}
    if(a==0 && b==1 && c==0){return rule30[5];}
    if(a==0 && b==0 && c==1){return rule30[6];}
    if(a==0 && b==0 && c==0){return rule30[7];}
    return -1;
}

int calculateNextGen(){
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
        nextGen[i]=compareRule(a,b,c);
        
    }
    //prevGen=nextGen;
    memcpy(prevGen, nextGen, genLength * sizeof(int));
    return 0;
}

int main(){
    for(int i=0;i<250;i++){
        printToFile(prevGen,"rule30.txt");
        printGen(prevGen);
        calculateNextGen();
    }
    return 0;
}
