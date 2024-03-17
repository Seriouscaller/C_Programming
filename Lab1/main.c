/* file name:  main.c
   purpose:   Lab 1 - Task 1
              Get input from user and display a multiplication-table up to the size of the input.

   last modified: 2024.03.16
   Erik Karlsson
*/

#include <stdio.h>
#include <stdlib.h>


/*Function prototypes*/
void clearInputBuffer(void);
void createHorizontalLine(int size, int vertical_linenumber);
void displayHeader(int size);
void readUserInputAndValidate(char prompt [], int lowerLimit, int upperLimit);

/*Macros*/
#define DASH    '\055'
#define NEWLINE '\012'
#define VBAR    '\174'
//#define DEBUG


int main()
{
    int table_size;

    const int MAX = 10;
    table_size = readUserInputAndValidate ( "Enter the size of the table: ", 1, MAX);
    displayHeader(table_size);
    printf("%c" ,NEWLINE);

    /*Vertical-loop*/
    for(int vertical_line = 1; vertical_line <= table_size; vertical_line++){
        createHorizontalLine(table_size, vertical_line);
        printf("%c" ,NEWLINE);
    }
    return 0;
}


int readUserInputAndValidate(char prompt [], int lowerLimit, int upperLimit){

    int size;
    do
    {
        printf("%s (%d-%d):", prompt, lowerLimit, upperLimit);
        scanf("%d", &size);
        clearInputBuffer();

        #ifdef DEBUG
            printf(" -DEBUG- size: %d\n", size);
        #endif // DEBUG
    }
    while (size < lowerLimit || size > upperLimit);
    return size;
}


/*Keeps reading the input-buffer and discards the values, until a newline-character appears*/
void clearInputBuffer(void){
    while ((getchar()) != '\n');
    return;
}


void createHorizontalLine(int size, int vertical_linenumber){
    int product;
    int horizontal_column;

    /*The leftmost fixed column, "  2|"*/
    printf("%3.d %c", vertical_linenumber, VBAR);

    for(horizontal_column = 1;horizontal_column <= size; horizontal_column++){
        /*Re-evaluate the product for each column*/
        product = horizontal_column * vertical_linenumber;
        printf("%5.d", product);
    }
    return;
}


void displayHeader(int size){
    const int COLUMN_WIDTH = 5;

    printf("  x %c", VBAR);
    int current_number = 1;
    for(current_number; current_number <= size; current_number++){
        printf("%5.d", current_number);
    }

    printf("%c", NEWLINE);
    /*Vertical separator"-----------"*/
    int bars = size * COLUMN_WIDTH + 5;
    for(int i = 0; i < bars;i++){
        printf("%c", DASH);
    }
    return;
}
