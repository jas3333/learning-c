#include "header/data.h"
#include <stdio.h>

void input(char text[], char *string, int string_length)
{
    char character;
    int counter = 0;

    printf("%s", text);

    while ((character = getchar()) != '\n')
    {
        if (counter < string_length)
        {
            string[counter] = character;
            counter = counter + 1;
        }
    }

    string[counter] = '\0';
    printf("\n");
}

int int_input(char text[], char *string, int string_length)
{
    char character;
    int counter = 0;
    int int_string;

    printf("%s", text);

    while ((character = getchar()) != '\n')
    {
        if (counter < string_length)
        {
            string[counter] = character;
            counter = counter + 1;
        }
    }

    string[counter] = '\0';
    printf("\n");

    int_string = strtol(string, NULL, 0);

    return int_string;
}

int randint(int min, int max)
{
    int number = (rand() % (max - min + 1)) + min;

    return number;
}


