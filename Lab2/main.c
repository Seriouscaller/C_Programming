/* file name:  main.c
   purpose:   Lab 1 - Task 2
              Approximate the value of e^x using a Taylor-serie.

   last modified: 2024.03.17
   Erik Karlsson
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG;

#define NEWLINE '\012'
#define TAB     '\011'


int main()
{
    int x;
    int n = 1;
    float latest_term;
    //float current_term;

    const float THRESHOLD = 0.0000001;

    x = readUserInputAndValidate("Enter the value of x: ", 0, 10);
    displayHeader();

    int term_number = 1;
    bool is_limit_reached = false;

    float sum = 1;
    while (!is_limit_reached){
        float current_term = calculateTerm(x, term_number++);
        sum += current_term;
        displayRowResult(term_number, current_term);
        is_limit_reached = (absoluteValue(current_term) < THRESHOLD);
        term_number++;
        latest_term = current_term;
    }

    return 0;
}

void absoluteValue(float current_term){
    if (current_term < 0){
        return (current_term * -1);
    }else return current_term;
}


void displayRowResult(int term_number, float current_term){

    printf("%c%c", TAB, TAB);
    printf("%5d %c", term_number, TAB);
    printf("%9.f %f", current_term);
    printf("%c", NEWLINE);
    return;
}


float calculateTerm(int x, int term_number){

    float nominator = power(x, term_number);
    int factorial = calculateFactorial(term_number);
    float product = ((float)nominator / factorial);
    return product;
}


int calculateFactorial(int term){

    int factorial = 1;
    while(term-- > 1) factorial *= term;
    return factorial;
}


int power(int base, int exponent){

    int product = 1;
    while(exponent-- > 1) product *= base;
    return product;
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

        #ifdef DEBUG
            printf(" -DEBUG- size: %d\n", x);
        #endif // DEBUG
    }
    while (x < lowerLimit || x > upperLimit);
    return x;
}


void clearInputBuffer(void){
    while ((getchar()) != '\n');
    return;
}
