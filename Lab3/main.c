#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int lengthOfString(char string[]);
char readUserInputAndValidate(char, int, int);
bool validateBinaryString(char string[], int);

//#define DEBUG

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
    unsigned int checkOverheat =        0b0000000000000100;
    unsigned int checkSnow =            0b0000000000100000;

    unsigned int checkBrakePads =       0b0000000000000001;
    unsigned int checkBrakeFluid =      0b0000000000000010;


    /* Checking conditions. If any case is true, the resulting value will not be equal to 0 */
    if(stat != 0){

        if((stat & checkFuel) > 0){

            puts("Fuel level is too low.");
            #ifdef DEBUG
                printf("stat & checkFuel = %d\n", (stat & checkFuel));
            #endif // DEBUG
        }

        if(((stat & checkSnow) > 0) && ((stat & checkOverheat) > 0)){
            //Snowing AND overheating
            puts("It's snowing outside, and the engine is too hot.");
            #ifdef DEBUG
                printf("stat & checkSnow = %d\n", (stat & checkSnow));
                printf("stat & checkOverheat = %d\n", (stat & checkOverheat));
            #endif // DEBUG
        }


        unsigned int brakePadsMask = (stat & checkBrakePads);
        unsigned int brakeFluidMask = (stat & checkBrakeFluid);

        //isolating bit we are interested in
        unsigned int brakePadsBit = brakePadsMask;

        //moving the bit to the least significant bit
        unsigned int brakeFluidBit = brakeFluidMask >> 1;
        //Now we can apply our XOR-operation

        if(brakePadsBit ^ brakeFluidBit > 0){

            //If either one of brakebits are set
            puts("Either the brakefluid is too low, or the brakepads are bad.");
            #ifdef DEBUG
                printf("stat & checkBrakes = %d\n", (brakePadsBit ^ brakeFluidBit));
            #endif // DEBUG
        }else{
            //If both brakebits are set, it's working normally
            puts("Everything in the car is working normally.");
        }
    }else{
        puts("Everything in the car is working normally.");
    }

    return 0;
}
