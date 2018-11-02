#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int rule[8];
int genLength = 20;
int prevGen[20][20];

int printGen(int gen[genLength][genLength]);
int printToFile(int gen[genLength][genLength], char *fname);
int countNeighbours(int i, int j);


int main(int argc, char *argv[]){
    srand(time(NULL));
    for (int i=0; i<genLength; i++){
        for (int j=0; j<genLength; j++){
            prevGen[i][j]=(rand()%2);
        }
    }
    
    printGen(prevGen);

    return 0;
}

//pringitng to a file
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
            if(gen[i][j]==1){
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

//printing in termilal
int printGen(int gen[genLength][genLength]){
    //clreaing screen
    printf("\033c" );

    for(int i=0;i<genLength;i++){
        printf("\n");
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

//for deterening current cell
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


    return 0;
}

//generating next generation
int nextGen(){
    //int nextGen[genLength][genLength];
    
    int neighborCount;
    for(int i=0;i<genLength;i++){
        for(int j=0;j<genLength;j++){
            if (i==0 || i== genLength-1 || j==0 || j== genLength-1){
               //edge case 
            }
            neighborCount = countNeighbours(i,j);
        }
    }
    return 0;
}

//For counting the neighbours of a cell
int countNeighbours(int i, int j){
    int sum=0;
    //Yes I know,there is a better way todo this, only just written it 1hour before the deadline :))
    sum += prevGen[i-1][j-1];
    sum += prevGen[i][j-1];
    sum += prevGen[i+1][j-1];
    sum += prevGen[i-1][j];
    sum += prevGen[i+1][j+1];
    sum += prevGen[i][j+1];
    sum += prevGen[i-1][j+1];
    sum += prevGen[i-1][j];
    return sum;
}





