#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
    int max_hit_points;
    int defense;
    int attack;
    int gold;
    int location;
    int exp;
    int level;
};

struct monster {
    char *name;
    int hit_points;
    int attack;
    int defense;
    int gold;
    int exp_given;
};


// Function Prototypes
void display_room(struct character player, struct locations *rooms);
_Bool exit_is_valid(int choice, int location, struct locations *rooms);
char input(char text[], char string[], int string_length);
void dice(int *gold, int *location, int *hp);
void battle(struct character *player);
void training(struct character *player);
void display_battle(struct character *player, int hp, char *name);
void display_player(struct character *player);
int random_number(int min, int max);

