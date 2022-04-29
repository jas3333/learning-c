#include <stdio.h>
#include <string.h>

char input(char text[], char *string, int string_size);

int main()
{
    struct main_character{
        char *character_name;
        int hit_points;
        int defense;
        int attack;
    };

    struct location {
        char *description;
        char *title;
        char *exit_descriptions;
        int exits[10];
    };


    struct location places[2] = {
        {"You are standing at the town square. Everywhere you look\n" 
         "you see under construction signs.", 
         "Town Square",
         "1) Armor Shop\n2) Weapon Shop\n3) Forest\n4) Inn",
         {1, 2, 3, 4}},
    };


    char user_input[5];
    printf("%s\n-----------\n", places[0].title);
    printf("%s Despite this, you see the following exits.\n-------------\n%s\n\n", 
            places[0].description, places[0].exit_descriptions);
    input("Where would you like to go? >>> ", user_input, 5);


    
    return 0;
}

char input(char text[], char *string, int string_size)
{
    printf("%s", text);
    fgets(string, string_size, stdin);
    int size = strlen(string);
    string[size - 1] = '\0';

    return *string;
}


