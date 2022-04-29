#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct trail_crew {
    int oxen;
    int kids;
    int parents;
    int money;
    int health;
    int ammo;
    int medicine;
    int clothes;
    int food;
    _Bool alive;
};

int random_number(int min, int max);
void the_trail(struct trail_crew *family, char date[], int *miles_left, int *trading_post);
void food_check(struct trail_crew *family);
void intro(struct trail_crew *family);
void input(char text[], char *string, int string_length);
void display_stats(struct trail_crew *family);
void hunt(struct trail_crew *family);
void events(struct trail_crew *family, int *miles);
void robbed(struct trail_crew *family);
void trail_stats(struct trail_crew *family);
void health_check(struct trail_crew *family);
void trading(struct trail_crew *family);
