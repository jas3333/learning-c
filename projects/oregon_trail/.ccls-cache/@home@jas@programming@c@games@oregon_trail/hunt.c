#include "header/data.h"
#include <stdio.h>

void hunt(struct family *family)
{

    int number = randint(40, 100);

    struct game_text the_hunt = {
        .description        = "=-=-=-=-=-=-=-=\n"
                              "|   The Hunt  |\n"
                              "=-=-=-=-=-=-=-=\n\n",

        .dialog             = "You go out and hunt for the day.",
    };

    printf("%s%s You bring back %d lbs of food.\n\n", the_hunt.description, the_hunt.dialog, number);
    family->food += number;

    // Reuse number for ammo used
    number = randint(2, 20);
    family->ammo -= number;
}
