#include <stdio.h>
#include <stdlib.h>

char readUserInputAndValidate(char, int, int);

int main()
{
    char input[17];

    int scanfStatus = scanf("%16s", &input);    //Only allowing 16 characters.
    char length = lengthOfString(input);

    printf("Length of user-input: %d\n", length);

    printf("Scanf-status: %d\n", scanfStatus);
    printf("Userinput: %s\n", input);
    puts(input);


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

int validateBinaryString(char string[]){

}

int lengthOfString(char string[]){
    unsigned int counter;
    for(counter = 0; string[counter]; ++counter);
    return counter;
}
