/*
    Author: Michael Bateman
    Email: mikeb8ma@student.ubc.ca
    Student Number: 14805246
    Lab Section: L2M
    Today's Date: March 14, 2021
 
    Purpose: simple loop with sum
    Input:
        none
    Output:
        i - the amount of times the loop is run
        sum - the sum of i's
*/

#include <stdio.h>

//Define
#define NUM_ROWS 2
#define NUMCOLS 5
#define TRUE 1
#define FALSE 0

//Function protype
int search(int value, int array[NUM_ROWS][NUMCOLS]);

int main(void) {
    
    //Test array
    int array[NUM_ROWS][NUMCOLS] = {
        {2,4,6,8,10},
        {12,14,16,18,20}
    };
    printf("%d\n", search(3, array));
    return 0;
}

//Function search
int search(int value, int array[NUM_ROWS][NUMCOLS]) {
    int index_row = 0;
    int index_col = 0;
    int found = FALSE;
    
    // Loop to check 2D array
    while (index_row < NUM_ROWS) {
        while (index_col < NUMCOLS) {
            if (array[index_row][index_col] == value) {
                found = TRUE;
                break;
            }
            index_col++;
        }
        if (array[index_row][index_col] == value) {
            break;
        }
        index_row++;
    }
    
    //Will either return 1 or 0
    return found;
}
