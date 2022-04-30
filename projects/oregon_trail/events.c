#include "header/data.h"
#include <stdio.h>

void events(struct family *family)
{
    char string[5];
    char *gun_sounds[] = {
        "pow",
        "blam",
        "bang",
        "wham",
    };

    int number;
    int event_number;

    time_t before;
    time_t after;


    // Set max higher for more uneventful days
    event_number = randint(1, 20);

    if (event_number == 1)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               "|     Wandering Oxen    |\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               " As you push over a rolling hill, you come upon a wandering oxen. It looks\n"
               " like it has been abandoned. You wonder what happened to its owner. Well,\n"
               " looks like its your lucky day. You adopt the oxen and add it to your team.\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

        family->oxen += 1;
        input("Press enter to continue.", string, 0);
    }

    // Wile Animals
    else if (event_number == 2)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=\n"
               "|    Wild Animals   |\n"
               "=-=-=-=-=-=-=-=-=-=-=\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               "You and your family are happily singing away when a pack of animals come\n"
               "racing towards the wagon. You toss the kids into the wagon and pull out\n"
               "your trusty rifle and aim...\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        if (family->ammo >= 5)
        {
            // Get gun sound
            number = randint(1, 4) - 1;
            printf("Type: %s\n", gun_sounds[number]);

            // Time Check, type fast!
            before = time(NULL);
            input(">>>> ", string, 5);
            after = time(NULL);

            // Success
            if (strcmp(string, gun_sounds[number]) == 0 && after - before < 3)
            {
                // Food gained
                number = randint(30, 50);
                printf("Nice shooting! You got them, with a bonus of %d lbs of meat!\n", number);
                family->food += number;
                family->ammo -= randint(2, 5);

                input("Press enter to continue.", string, 0);
            }
            // Failure
            else
            {
                printf("That was some sorry shooting. You missed them all, and they run past\n"
                       "you and rummage through your food.\n");
                family->food -= randint(20, 40);
                family->ammo -= randint(2, 5);
                input("Press enter to continue.", string, 0);
            }

        }
        // Out of Ammo
        else
        {
            printf("Looks like you are out of ammo and can't defend your family. They run past\n"
                   "you and rummage through your food.\n");
            family->food -= randint(20, 40);
            input("Press enter to continue.", string, 0);
        }
    }
    // End Wild Animals

    // Dense Fog
    else if (event_number == 3)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=\n"
               "|     Dense Fog     |\n"
               "=-=-=-=-=-=-=-=-=-=-=\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               " A dense fog settles in the valley and you lose site of the trail. Several\n"
               " hours pass by and you finally find your way back. You lost valuable miles.\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        family->miles_traveled -= randint(20, 50);
        input("Press enter to continue.", string, 0);
    }

    // Uneventful Day
    else if (event_number >= 4)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=\n"
               "|     Dense Fog     |\n"
               "=-=-=-=-=-=-=-=-=-=-=\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               "It's been a relaxing uneventful day. You wish more days were like today.\n" 
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        input("Press enter to continue.", string, 0);
    }

}
