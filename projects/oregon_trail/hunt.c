#include "header/data.h"
#include <stdio.h>

void hunt(struct family *family)
{

    char string[5];
    char *gun_sounds[] = {
        "blam",
        "bang",
        "wham",
        "pow",
    };

    int number = randint(1, 4) - 1;


    struct game_text the_hunt = {
        .description        = "=-=-=-=-=-=-=-=\n"
                              "|   The Hunt  |\n"
                              "=-=-=-=-=-=-=-=\n\n",

        .dialog             = "You go out and hunt for the day.",
        .positive           = "Nice, you got one! Full bellies tonight.",
        .negative           = "Looks like you missed, better luck next time.",


    };

    printf("%s%s\n", the_hunt.description, the_hunt.dialog);
    printf("Type: %s\n", gun_sounds[number]);

    // Time Users Typing
    time_t before = time(NULL);
    input(">>>> ", string, 5);
    time_t after = time(NULL);

    if (strcmp(string, gun_sounds[number]) == 0 && after - before < 3)
    {
        number = randint(40, 100);
        puts(the_hunt.positive[0]);
        printf("You brought back %d lbs of meat.\n", number);

        family->food += number;
        family->ammo -= randint(2, 10);
    }
    else 
    {
        puts(the_hunt.negative[0]);
        family->ammo -= randint(2, 10);
    }

    input("Press any key to continue.", string, 0);
    
}


