#include "header/data.h"
#include <stdio.h>

char input(char print_text[], char string[], int size)
{
    char character;
    int counter = 0;

    printf("%s", print_text);

    while((character = getchar()) != '\n')
    {
        if (counter < size)
        {
            string[counter] = character;
            counter++;
        }
    }
    string[counter] = '\0';
    printf("\n");

    return *string;
}

int random_number(int min, int max)
{
    int number = (rand() % max) + min;
    return number;
}
