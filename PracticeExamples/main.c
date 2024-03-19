#include <stdio.h>
#include <stdlib.h>

int main()
{
    //size();

    int a = 3;
    int b = 4;
    float c;

    c = (float)a/b;
    printf("%f", c);


    //strings();
    //enumerations();
    //printf("%d", square(5));
    //printf("%d", inline_square(5));

    return 0;
}

int square(int x)
{
    return x * x;
}



inline int inline_square(int x)
{
    return x * x;
}
