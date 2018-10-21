#include<stdio.h>
#include<stdlib.h>


int decToBin(int dec){
    if (dec == 0){
        return 0;
    }else{
        return (dec % 2 + 10 * convert(dec / 2));
    }
}

int binToString(int dec, char *binString){
    int binInt = decToBin(dec);
    char *tmpBin[256];
    itoa(binInt,tmpBin,10);
    *binString=tmpBin;

}

int main(int argc, char *argv[]){
    //char ruleDec = *argv[1];
    char *p;
    int ruleInt = strtol(argv[1],&p,10);
    
    char *bin;
    binToString(ruleInt,0,&bin);
            
    printf("%s\n",*bin);
    
    return 0;
}
