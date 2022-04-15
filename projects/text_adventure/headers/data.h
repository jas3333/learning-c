#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Structs
struct locations {
    char *room_title;
    char *room_description;
    char *exit_descriptions;
    int exits[5];
};

struct character {
    char *name;
    char *weapon;
    char *armor;
    int hit_points;
    int defense;
    int attack;
    int gold;
    int location;
};


// Function Prototypes
void display_room(struct character player, struct locations *rooms);
_Bool exit_is_valid(int choice, int location, struct locations *rooms);
char input(char text[], char string[], int string_length);

