#include <stdio.h>
#include <stdlib.h>

int main()
{
    //size();
    strings();
    enumerations();
    printf("%d", square(5));
    printf("%d", inline_square(5));

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
