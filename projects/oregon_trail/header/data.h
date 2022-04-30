#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct family {
    int oxen;
    int money;
    int health;
    int size;
    int is_alive;
    int ammo;
    int food;
    int medicine;
    int clothes;
    int miles_traveled;

};

struct game_text {
    char *description;
    char *dialog;
    char *choices[3];
    char *negative[5];
    char *positive[5];
};

struct weather {
    char *description;
    int travel_speed;
};


// Prototypes
void input(char text[], char *string, int string_length);
int int_input(char text[], char *string, int string_length);
int randint(int min, int max);
void food(struct family *family);
void display_info(struct family *family, char orientation);
void display_travel_info(struct family *family, char date[], char weather[]);
void hunt(struct family *family);
void trail(struct family *family, int trading_post);
void intro(struct family *family);
void events(struct family *family);



