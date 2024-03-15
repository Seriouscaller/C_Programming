#include <stdio.h>
#include <stdlib.h>

int strings(){

    char string[] = "asd" "123";
    printf("String: %s\n", string);
    printf("Length of string: %d\n", strlen(string));

    //Accessing an element of the string:
    printf("3rd element: %c\n", string[2]);

    //Modifying an element of the string:
    string[2] = 'x';
    printf("String: %s\n", string);

    printf("Size of string: %d\n", sizeof(string));
    printf("Size of first character: %d\n", sizeof(string[0]));

    char greetings[] = {'H', 'e','l','l','o', '\0'};
    printf("String: %s\n", greetings);

return 0;
}

int strlen(char s[]){
    int i;

    i = 0;
    while(s[i] != '\0'){
        ++i;
    }
    return i;
}
