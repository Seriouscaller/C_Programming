#include <stdio.h>
#include <stdlib.h>

int main()
{
    char testPattern[] =          "0000000010110101";

    char checkNormal[] =          "0000000000000000";
    char checkFuel[] =            "0000000000010000";
    char checkSnowAndOverheat[] = "0000000000100100";
    char checkBrakes[] =          "0000000000000011";

    int results[] = checkFuel & testPattern;
    printf("%c", (checkFuel & testPattern));

    puts(checkNormal);

    return 0;
}
