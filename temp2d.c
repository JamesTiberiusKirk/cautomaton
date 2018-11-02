#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "errors.h"

#define COLS 100
#define ROWS 100

#define clear() printf("\033[H\033[J")

int generateNextGen(int** gen);
int** initGen(int row, int col);
void printGen(int** gen);
bool checkNeighbours(int neighbors, int** gen, int row, int col);
void generateConways(int** gen, int max);
int randomiseGen(int** gen); 
void runConways();

int main(){
    runConways();
    return 0;
}

void runConways() {
   //char input;
    int inputMax;

    printf("Note: give the generation of Conway's game of life a minute to take shape");
    printf("\nEnter the number of generations you want to simulate: ");
    scanf("%d", &inputMax);

    printf("Starting...");
    int** firstGen = initGen(ROWS, COLS); // initialise the firstGen to 0's
    randomiseGen(firstGen); // randomise firstGen with 1's and 0's
    generateConways(firstGen, inputMax); // generate for n number of times defined by the MAX_GEN
    free(firstGen); // free the memory once done
}

void generateConways(int** gen, int max) {
    for (int i = 0; i < max; i++) {
        generateNextGen(gen);  // generate the next generation
        printGen(gen); // print to the screen
        usleep(200000); // suspends execution in microseconds (gives a stop motion effect)
        
    }
}

void printGen(int** gen) {
    for (int i = 1; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(gen[i][j] == 1)
                printf("\u2588"); // print a block if 1
            else
                printf(" "); // print a blank space if 0
        }
        printf("\n");
    }
}

int** initGen(int row, int col) {
    int *arr = malloc(row*sizeof(int)); // allocate memory for a 2D array
    
    for (int i = 0; i < row; i++)
        arr[i] = malloc(sizeof(int)*col); // allocate memory for each sub array

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0; // initialise to 0's
        }
    }
    return arr;
}

int randomiseGen(int** gen) {
    if (*gen == NULL)
        return NULL_PARAM;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            gen[i][j] = rand()%2; // random number mod 2 is ethier a 0 or a 1
    }
     // 2D array is returned which will be the 1st gen

    return SUCCESS;
}

int generateNextGen(int** gen) {
    clear();
    int** nextgen = initGen(ROWS, COLS); // initialise the next gen 
    int neighbours;

    if (*nextgen == NULL)
        return NULL_PARAM;

    if (*gen == NULL)
        return NULL_PARAM;
    
    // outer double for loop searches the whole 2d array 
    for (int row = 1; row < ROWS-1; row++) {
        for (int col = 1; col < COLS-1; col++) {
            neighbours = 0;
            // each element found searches for elements around the element found
            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    if (gen[r+row][c+col] == 1)
                        neighbours++; // if an alive cell is found then its a neighbour      
                }
            }

            // the centre cell cannot be a neighbour thus minus 1 from neighbours found 
            if (gen[row][col] == 1)
                neighbours--;
            
            // the return value is true then nextGen will be 1 else 0
            if(checkNeighbours(neighbours, gen, row, col) == true)
                    nextgen[row][col] = 1;
                else
                    nextgen[row][col] = 0;
            } 
        }

    // copy nextGen to gen (make the next generation the current generation)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            gen[i][j] = nextgen[i][j];
    }
    free(nextgen); // free nextGen memory after being copied to gen

    return SUCCESS;
}

bool checkNeighbours(int neighbours, int** gen, int row, int col) {
    // if the element is dead and its neighbours are 3 then the element is 1 and born
    if (gen[row][col] == 0) {
        if (neighbours == 3)
            return true;
    }
    else if (gen[row][col] == 1) {
        if (neighbours == 2 || neighbours == 3) // if its neighbours are 2 or 3 the element lives on
            return true;   
        else if (neighbours < 2) // if there are fewer than 2 neighbours then the element dies
            return false;
        else if (neighbours > 3) // if there are greater than 3 neighbours then the element dies
            return false;
    }
    return false;
}
