#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int rule[8];
int prevGen[32][32];
int genLength = 20;


int printGen(int gen[genLength][genLength]);

int main(int argc, char *argv[]){
    srand(time(NULL));
    for (int i=0; i<genLength; i++){
        for (int j=0; j<genLength; j++){
            prevGen[i][j]=rand()%1;
        }
    }
    
    printGen(prevGen);

    return 0;
}

int printToFile(int gen[genLength][genLength],char *fname){ 
    FILE *f=fopen(fname,"a");
  
    if(f == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    
    for(int i=0;i<genLength;i++){
        printf("Generation %d\n",i);
        for(int j=0;j<genLength;j++){
            //printf(" %d ",gen[i]);
            if(gen[i]==1){
                fprintf(f,"\u25A0");
                fprintf(f,"\u25A0");
            }else{
                //printf("\u25A1");
                fprintf(f,"  "); 
            }
        }
    }
    fprintf(f,"|\n");
    
    fclose(f);
    return 0;
}

int printGen(int gen[genLength][genLength]){
    printf("\033c" );

    for(int i=0;i<32;i++){
        printf("Generation %d\n",i); 
        for (int j=0; j<genLength;j++){
            //printf(" %d ",gen[i][j]);
            if(gen[i][j]==1){
                printf("\u25A0");
                printf("\u25A0");
            }else{
                //printf("\u25A1");
                printf("  "); 
            }
        }
    }
    printf("|\n");
    return 0;
}

int compareRule(){
    /*
     * possible combos
    0000
    0001
    0010
    0011
    0100
    0101
    0110
    0111
    1000
    1001
    1010
    1011
    1100
    1101
    1110
    1111
    */

    



}

int nextGen(){
    int nextGen[genLength][genLength];
    //int tr,t,tl,mr,ml,lr,l,ll;
    
    for(int i=0;i<genLength;i++){
        for(int j=0;j<genLength;j++){
            if (i==0){

            }
        }
    }
    return 0;
}



