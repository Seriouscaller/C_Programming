#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int lengthOfString(char string[]);
char readUserInputAndValidate(char, int, int);
bool validateBinaryString(char string[], int);


int main()
{
    char input[17];
    unsigned long int bitpattern;
    int scanfStatus;
char *end;
    bool valid_input = false;





    while(!valid_input){
        printf("Input bitpattern: ");
        scanfStatus = scanf("%16s", &input);    //Only allowing 16 characters.
        char length = lengthOfString(input);
        valid_input = validateBinaryString(input, length);
    }

    long int binaryNumber = strtoul(input, &end, 2);
    printf("Converted: %lu", binaryNumber);

    unsigned int stat = 0000000010110101;
    unsigned int checkFuel = 0b0000000000010000;
    unsigned int checkSnowAndOverheat = 0000000000100100;
    unsigned int checkBrakes = 0000000000000011;


    if(stat != 0){
        if(stat & checkFuel > 0){
            puts("Fuel level is too low.");
        }
        if(stat & checkSnowAndOverheat > 0 ){
            puts("It's snowing outside, and the engine is too hot.");
        }
        if(stat & checkBrakes > 0){
            puts("Either the brakefluid is too low, or the brakepads are bad.");
        }
    }else{
        puts("Everything in the car is working normally.");
    }

    return 0;
}


bool validateBinaryString(char string[], int length){
char *end;
    if (length < 17){
        return false;
    }

    long int conversion = strtoul(string, &end, 2);
    if (conversion < 0){
        return true;
    }else{
        return false;
    }

}


unsigned int lengthOfString(char string[]){
    unsigned int counter;
    for(counter = 0; string[counter]; ++counter);
    return counter;
}
