/* file name:  main.c
   purpose:   Lab 1 - Task 2
              Approximate the value of e^x using a Taylor-serie.

   last modified: 2024.03.27
   Erik Karlsson
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double absoluteValue(double);
void displayRowResult(int, double);
void displayHeader();
int readUserInputAndValidate(char[], int, int);
void clearInputBuffer(void);
void displayResult(int, double, float);

//#define DEBUG;

#define NEWLINE '\012'
#define TAB     '\011'


int main()
{
    int x;
    double current_term;
    const float THRESHOLD = 0.0000001;


    x = readUserInputAndValidate("Enter the value of x: ", -10, 10);
    displayHeader();


    unsigned long long int factorial = 1;
    bool is_limit_reached = false;
    double sum = 1;
    int term_number = 1;
    int nominator = x;
    while (!is_limit_reached){

        current_term = (double) nominator / factorial;
        is_limit_reached = (absoluteValue(current_term) < THRESHOLD);
        sum += current_term;
        displayRowResult(term_number, sum);

        #ifdef DEBUG
            /*Pauses the program until ENTER is pressed.*/
            printf("Termnumber: %d factorial: %8llu curr_term: %.10f sum: %.10f x: %d", term_number, factorial, current_term, sum, x);
            pause();
        #endif // DEBUG

        factorial *= ++term_number;
        nominator *= x;

    }
    displayResult(term_number, sum, THRESHOLD);
    pause();
    return 0;
}


void pause(void){
    while(getchar()!= '\n'){}
}


double absoluteValue(double current_term){
    if (current_term < 0){
        return (current_term * -1);
    }else return current_term;
}


void displayResult(int term, double sum, float THRESHOLD){
    printf("\n");
    printf("Within threshold of %.7f at term %d.\n", THRESHOLD, term-1);
    printf("Sum is equal to: %f ", sum);
}


void displayRowResult(int term_number, double sum){
    printf("%c%c", TAB, TAB);
    printf("%5d %c", term_number, TAB);
    printf("%10.8f", sum);
    printf("%c", NEWLINE);
    return;
}


void displayHeader(){
    printf("%c%c", TAB, TAB);
    printf("terms %c value", TAB);
    printf("%c", NEWLINE);
    return;
}


int readUserInputAndValidate(char prompt [], int lowerLimit, int upperLimit){
    int x;
    do
    {
        printf("%s (%d-%d):", prompt, lowerLimit, upperLimit);
        scanf("%d", &x);
        clearInputBuffer();
    }
    while (x < lowerLimit || x > upperLimit);
    return x;
}


void clearInputBuffer(void){
    while ((getchar()) != '\n');
    return;
}
