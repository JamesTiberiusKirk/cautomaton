#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int rule[8];
int *prevGen;
int genLength = 32;//default val

int printToFile(int gen[genLength],char *fname); 
int printGen(int gen[genLength]);
int compareRule(int a, int b, int c);
int calculateNextGen();
int dectobin(int dec);
int decTOBinArr(int dec);
void help();


int main(int argc, char *argv[]){
    char *p;
    int dec;
    int nrOfGens=30; //default val
    
    srand(time(NULL));
    if (argc==1){ 
        dec = (rand()%255)+1;
    } else if (argc==2) {
        if (strcmp(argv[1], "help") == 0 ){
            help();
            exit(0);
        }
        dec = strtol(argv[1], &p, 10); 
    } else if (argc==3) {
        if (strcmp(argv[1], "rand") == 0 ){
            dec = (rand()%255)+1;
        } else { 
            dec = strtol(argv[1], &p, 10); 
        }
        nrOfGens = strtol(argv[2], &p, 10);
    } else if (argc==4) {
        if (strcmp(argv[1], "rand") == 0 ){
            dec = (rand()%255)+1;
        } else {
            dec = strtol(argv[1], &p, 10); 
        }
        nrOfGens = strtol(argv[2], &p, 10);
        genLength = strtol(argv[3], &p, 10);
    } else if (argc>4) {
        printf("Too many params\n");
        help();
        exit(1);
    }

    for(int i=1; i<argc; i++){
        strtol(argv[i], &p, 10);
        printf("entered the loop %s\n",p);
        if (strcmp(argv[i], "rand") == 0 || strcmp(argv[i], "help") == 0 ){
            //i++;
            printf("arg is ok %s\n",argv[i]);
        } else if (p == argv[i] || *p != '\0'){
            printf("arg is not ok %s\n", argv[i]);
            printf("Please enter valid integers\n");
            exit(1);
        }
    }
    
    prevGen = (int *)malloc(genLength*sizeof(int));
    for(int i=0;i<genLength;i++){
        prevGen[i]=0;
    }
    prevGen[genLength/2]=1;

    printf("The rule is: %d\n",dec);         
    printf("The number of generations: %d\n",nrOfGens);
    printf("The length of each generation: %d\n",genLength);
 
    decTOBinArr(dec);   
    for(int i=0;i<nrOfGens;i++){
        printToFile(prevGen,"rule.txt");
        printGen(prevGen);
        calculateNextGen();
    }
    return 0;
}


void help(){
    printf("Usage:\n");
    printf("\t./cautomatonv2 <rule> <number of generations> <length of generations>\n");
    printf("\n<rule> needs to be a decial number between 0 and 255\n\t to chose a random number, pass in \"rand\" instead of the decial number.\n");
    printf("<number of generations> needs to be a positive decimal number\n");
    printf("<length of generation> needs to be a positive decimal for determening the \n\tlength of each individual generation\n");
    printf("\nAlternative usage:\n");
    printf("\t./cautomatonv2 <rule> <number of generations>\n");
    printf("\t./cautomatonv2 <rule>\n");
    printf("\t./cautomatonv2\n");
    printf("Not supplying the arguments like above will just set them to a default value.\n");
    printf("Not supplying a rule will automatically generate one.\n");
}

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


int dectobin(int dec){
    if (dec == 0){
        return 0;
    }else{
        return (dec % 2 + 10 * dectobin(dec / 2));
    }
}

int decTOBinArr(int dec){
    if (dec>255)
        return 1;
    
    if (rule == NULL)
        return 1;


    int bin=dectobin(dec);
    
    int tmprule[8];

    int div=1;
    for(int i=7;i>=0;i--){
        tmprule[i] = (bin/div)%10;
        div*=10;
    }
    

    memcpy(rule,tmprule,8*sizeof(int));

    return 0;
}

