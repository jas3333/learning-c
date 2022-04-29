#include "headers/data.h"
#include <stdio.h>

void input(char text[], char *string, int string_length)
{
    char character;
    int counter = 0;

    printf("%s", text);

    while ((character = getchar()) != '\n'){
        if (counter < string_length){
            string[counter] = character;
            counter++;
        }
    }

    string[counter] = '\0';
    printf("\n");

}

int random_number(int min, int max)
{
    max += 1;
    int number = rand() % max;

    if ( number < min )
        number += min;

    return number;
}
