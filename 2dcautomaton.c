#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int rule[8];
int prevGen[32][32];

int printGen(int gen[32][32]);

int main(int argc, char *argv[]){
    for (int i=0; i<32; i++){
        for (int j=0; j<32; j++){
            prevGen[i][j]=0;
        }
    }
    prevGen[0][0]=1;
    prevGen[31][31]=1;
    prevGen[0][31]=1;
    prevGen[31][0]=1;

    prevGen[16][16]=1;
    
    printGen(prevGen);

    return 0;
}

int printGen(int gen[32][32]){
    printf("\033c" );

    for(int i=0;i<32;i++){
        printf("\n"); 
        for (int j=0; j<32;j++){
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
