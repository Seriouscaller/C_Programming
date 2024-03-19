/* file name:  main.c
   purpose:   Lab 1 - Task 2
              Approximate the value of e^x using a Taylor-serie.

   last modified: 2024.03.17
   Erik Karlsson
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


float absoluteValue(float current_term);
void displayRowResult(int term_number, float current_term);
float calculateTerm(int x, int term_number);
int calculateFactorial(int term);
int power(int base, int exponent);
void displayHeader();
int readUserInputAndValidate(char prompt [], int lowerLimit, int upperLimit);
void clearInputBuffer(void);

#define DEBUG;

#define NEWLINE '\012'
#define TAB     '\011'


int main()
{
    int x;
    int n = 1;
    float latest_term;
    float current_term;
    int term_number = 1;
    bool is_limit_reached = false;
    float sum = 1;
    const float THRESHOLD = 0.0000001;

    x = readUserInputAndValidate("Enter the value of x: ", 0, 10);
    displayHeader();

    //printf("Factorial of 3: %d\n", calculateFactorial(3));

    //float first = calculateTerm(x, term_number++);
    //float second = calculateTerm(x, term_number++);
    //printf("%f %f", first, second);


    while (!is_limit_reached){
        current_term = calculateTerm(x, term_number);

        sum += current_term;
        displayRowResult(term_number, current_term);
        is_limit_reached = (absoluteValue(current_term) < THRESHOLD);
        term_number++;
        latest_term = current_term;

    #ifdef DEBUG
        printf("Curr Term: %d Sum: %f Is_limit: %b Termnr: %d Latest: %f", current_term, sum, is_limit_reached, term_number, latest_term);
        printf("Sum: %f\n", sum);
        while(getchar()!= '\n'){}
    #endif // DEBUG

    }
    return 0;
}


float absoluteValue(float current_term){
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
    float quotient = (nominator / factorial);

    #ifdef DEBUG
        printf("Term-value: %f ", quotient);
        printf("Nom: %f ", nominator);
        printf("Fact: %d ", factorial);
        printf("Quo: %f ", quotient);
    #endif

    return quotient;
}


int calculateFactorial(int term){

    int factorial = 1;
    while(term > 1) {
        factorial *= term;
        term--;
    }
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
