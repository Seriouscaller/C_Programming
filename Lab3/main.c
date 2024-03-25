#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int lengthOfString(char string[]);
char readUserInputAndValidate(char, int, int);
bool validateBinaryString(char string[], int);

#define DEBUG

int main()
{
    char input[17];
    int scanfStatus;
    char *end;

    printf("Input bitpattern (16-bit): ");
    scanfStatus = scanf("%16s", input);    //Only allowing 16 characters.

    /*Conversion of string to unsigned long int*/
    unsigned long int stat = strtoul(input, &end, 2);

    /*Binary constants*/
    unsigned int checkFuel =            0b0000000000010000;
    unsigned int checkSnowAndOverheat = 0b0000000000100100;
    unsigned int checkBrakes =          0b0000000000000011;


    /* Checking conditions. If any case is true, the resulting value will not be equal to 0 */
    if(stat != 0){

        if((stat & checkFuel) > 0){

            puts("Fuel level is too low.");
            #ifdef DEBUG
                printf("stat & checkFuel = %d\n", (stat & checkFuel));
            #endif // DEBUG
        }

        if((stat & checkSnowAndOverheat) > 0 ){

            puts("It's snowing outside, and the engine is too hot.");
            #ifdef DEBUG
                printf("stat & checkSnowAndOverheat = %d\n", (stat & checkSnowAndOverheat));
            #endif // DEBUG
        }
//excusive or
        if((stat & checkBrakes) > 0){

            puts("Either the brakefluid is too low, or the brakepads are bad.");
            #ifdef DEBUG
                printf("stat & checkBrakes = %d\n", (stat & checkBrakes));
            #endif // DEBUG
        }
    }else{
        puts("Everything in the car is working normally.");
    }

    return 0;
}
