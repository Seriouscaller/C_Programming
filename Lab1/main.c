#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int current_horizontal_column;
    int current_vertical_line = 1;
    int factor;
    int product = 0;
    int scanf_status_code;
    int user_answer;
    bool validInput = false;

    do{
        printf("Enter the size of the table: ");
        scanf_status_code = scanf("%d", &user_answer);
        printf("Scanf statuscode: %d\n", scanf_status_code);
        clearInputBuffer();

        //Make sure input is numeric between 1-10
        if(scanf_status_code == 1 && user_answer <= 10 && user_answer >= 1){
            validInput = true;
        }
    }while(!validInput);

    factor = user_answer;

    //TODO INPUT VALIDATION

    //Insert forloop into flowchart
    displayHeader(factor);
    printf("\n");

    //Vertical-loop
    for(current_vertical_line; current_vertical_line <= factor; current_vertical_line++){
        createHorizontalLine(factor, current_vertical_line);
        printf("\n");
    }
    return 0;
}

void clearInputBuffer(void){
    while ((getchar()) != '\n');
    return;
}

void createHorizontalLine(int size, int vertical_linenumber){
    int product;
    int current_horizontal_column;

    printf("%3.d |", vertical_linenumber);

    for(current_horizontal_column = 1;current_horizontal_column <= size; current_horizontal_column++){
        product = current_horizontal_column * vertical_linenumber;
        printf("%5.d", product);
    }
    return;
}

void displayHeader(int size){
    int current_factor = 1;

    printf("  x |");
    for(current_factor; current_factor <= size;
                                   current_factor++){
        printf("%5.d", current_factor);
    }
    printf("\n");
    int bars = size * 5 + 5;
    for(int i = 0; i < bars;i++){
        printf("-");
    }
    return;
}
