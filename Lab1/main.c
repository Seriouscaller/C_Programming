#include <stdio.h>
#include <stdlib.h>

int main()
{
    int current_horizontal_column = 1;
    int current_vertical_line = 1;
    int factor;
    int product = 0;
    int scanf_status_code;
    int user_answer;


    printf("Enter the size of the table: ");
    scanf_status_code = scanf("%d", &user_answer);
    printf("Scanf statuscode: %d\n", scanf_status_code);
    factor = user_answer;


    //TODO INPUT VALIDATION


    //Insert forloop into flowchart
    //Formatting Header
    printf(" X |");
    for(current_horizontal_column; current_horizontal_column <= factor;
                                                    current_horizontal_column++){
        printf("%5.d", current_horizontal_column);
    }
    printf("\n");
    int bars = ()
    for(int i = 0; i < ){}
    printf("%s", bar * 5);


    //
    return 0;
}

