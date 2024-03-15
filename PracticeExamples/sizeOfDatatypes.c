#include <stdio.h>
#include <stdlib.h>

int size()
{
    int intType;
    short int shortType;
    long int longType;

    char charType;
    float floatType;
    double doubleType;

    printf("Size of int: %zu\n", sizeof(intType));
    printf("Size of short int: %zu\n", sizeof(shortType));
    printf("Size of long int: %zu\n\n", sizeof(longType));

    printf("Size of char: %zu\n", sizeof(charType));
    printf("Size of float: %zu\n", sizeof(floatType));
    printf("Size of double: %zu\n", sizeof(doubleType));



    return 0;
}
