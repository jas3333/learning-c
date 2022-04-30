#include "header/data.h"
#include <stdio.h>

void events(struct family *family)
{
    char string[5];
    int number;
    int active_event = 1;
    int choice;

    struct game_text events[10] = {
        {
            .description        = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|    Heavy Fog    |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",

            .dialog             = "You get lost in a thick dense fog and lost time trying to find\n"
                                  "your way back to the trail.\n\n",
                
        },
        {
            .description        = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|    Lost Oxen    |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",

            .dialog             = "While traveling you find an oxen that looks like it lost its owner.\n"
                                  "You adopt it and add it to your oxen team.\n\n",
        },
        {
            .description        = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|    Oxen Down    |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",

            .dialog             = "While traveling your oxen stumbles. You stop and do a check up on it.\n",

            .positive           = "After throughly checking over the oxen. Looks like it's healthy as an ox...\n\n",
            .negative           = "After throughly checking over the oxen, looks like it has a maimed leg.\n"
                                  "You will have to put it down. On the bright side, you will gain some food.\n\n",
        },
        {
            .description        = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|   Blessed Day   |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",

            .dialog             = "As you and your family are walking the trail. You think of how blessed you\n"
                                  "are to have such a wonderful family and making a journey of a lifetime.\n\n",
        },
        {
            .description        = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|  Wild Animals   |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",

            .dialog             = "A pack of wild animals make their way toward your wagon.\n",

            .choices            = "1) Shoot Them\n2) Shout at Them\n3) Run Around and Panic\n\n",

            .positive           = {
                                  "You point your gun at them and start firing! You manage to fend them off.\n",
                                  "You let out a loud shout and scare the animals off.\n",
                                  },

            .negative           = {
                                  "You point your gun at them and...click...click...click...You ran out of\n"
                                  "ammo. They run past you and rummage through your food supply.\n",
                                  "Your shouts go ignored and they rummage your food supply.\n",
                                  "You run around in a panic and they rummage your food supply.\n",
                                  },
        },
        {
            .description        = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|    Uneventful   |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",

            .dialog             = "The day have been uneventful.\n\n",

        },
    };

    // Random number to pick events
    // Set it higher to get more uneventful days.
    number = randint(1, 20);

    // Heavy Fog
    if (number == 1)
    {
        printf("%s%s", events[0].description, events[0].dialog);

        if (family->miles_traveled < 40)
            family->miles_traveled = 0;
        else
            family->miles_traveled -= randint(10, 40);
    }

    // Wandering Oxen
    else if (number == 2)
    {
        printf("%s%s", events[1].description, events[1].dialog);
        family->oxen += 1;
    }

    // Oxen Down
    else if (number == 3)
    {
        printf("%s%s", events[2].description, events[2].dialog);

        // Set higher to lower chance of losing oxen
        number = randint(1, 10);

        if (number >= 2)
            puts(events[2].positive[0]);

        else
        {
            puts(events[2].negative[0]);
            family->oxen -= 1;
        }
    }

    // Blessed Day
    else if (number == 4)
    {
        printf("%s%s", events[3].description, events[3].dialog);
        family->health += 10;
    }

    // Wild Animals
    else if (number == 5)
    {
        while(active_event)
        {

            printf("%s%s%s", events[4].description, events[4].dialog, events[4].choices[0]);
            choice = int_input("What will you do?: ", string, 2);

            // Shoot the animals + Enough Ammo
            if (choice == 1 && family->ammo >= 10)
            {
                puts(events[4].positive[0]);

                // Amount of meat gained 
                number = randint(30, 70);
                printf("You gained %d lbs of meat.", number);

                // Ammo used
                number = randint(2, 10);
                printf(" You used up %d rounds of ammo.\n\n", number);
                family->ammo -= number;
                active_event = 0;
            }

            // Shoot the animals + Not enough ammo
            else if (choice == 1 && family->ammo < 10)
            {
                puts(events[4].negative[0]);
                family->food -= randint(20, 50);
                active_event = 0;
            }

            // Shout at the animals
            else if (choice == 2)
            {
                number = randint(1, 5);

                // Sets shout success rate
                if (number >= 2)
                {
                    puts(events[4].positive[1]);
                    active_event = 0;
                }
                else
                {
                    puts(events[4].negative[1]);
                    family->food -= randint(20, 50);
                    active_event = 0;
                }
            }
            
            // Panic!
            else if (choice == 3)
            {
                puts(events[4].negative[2]);
                family->food -= randint(20, 50);
                active_event = 0;
            }
        }
    }
    // End Wild Animals

    // Uneventful
    else if (number >= 6)
    {
        printf("%s%s", events[5].description, events[5].dialog);
    }
}
