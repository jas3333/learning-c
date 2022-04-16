#include "headers/data.h"
#include <stdio.h>

_Bool exit_is_valid(int choice, int location, struct locations *rooms)
{
    _Bool is_valid = 0;
    int array_size = sizeof(rooms[location].exits) / sizeof(rooms[location].exits[0]);

    for (int counter = 0; counter < array_size; counter++)
        if (rooms[location].exits[counter] == rooms[location].exits[choice - 1])
            is_valid = 1;
            
    return is_valid;
}

char input(char text[], char string[], int string_length)
{
    char character;
    int counter = 0;

    printf("%s", text);

    while((character = getchar()) != '\n')
        if (counter < string_length)
        {
            string[counter] = character;
            counter = counter + 1;
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
