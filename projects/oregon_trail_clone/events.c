#include "headers/data.h"
#include <stdio.h>

void events(struct trail_crew *family, int *miles)
{
    char string[5]; int number; int int_string;
    int event_number = random_number(1, 20);
    int event = 1;

    // Event One, Wild Animals
    while (event)
    {
        if ( event_number == 1)
        {
            printf("\n\nWild animals attack! What will you do?\n\n");
            input("1) Shoot them\n2) Shout and try to scare them\n3) Pee your pants\n\nYou choose to: ", string, 2);
            int_string = strtol(string, NULL, 0);

            if ( int_string == 1 && family->ammo > 10 )
            {
                // Amount of rounds fired
                number = random_number(5, 10);
                printf("You point your gun at them and start shooting. After firing %d rounds\n", number);
                family->ammo -= number;

                // Food gained from killing animals
                number = random_number(30, 60);
                printf("You manage to fend them off. You got %d lbs of food!\n", number);
                family->food += number;
                event = 0;
            }

            else if ( int_string == 2 )
            {
                number = random_number(1, 2);
                if ( number == 1 )
                {
                    printf("You shout and throw your arms up and manage to scare off the\n");
                    printf("furry invaders.\n");
                    event = 0;
                }

                else 
                {
                    printf("Your shouting goes ignored. They manage to rip through your supplies.\n");
                    number = random_number(20, 70);

                    if ( family->food < number )
                        family->food = 0;
                    event = 0;
                }
            }
        }
        // End of Event One

        // Event Two, Riders
        if ( event_number == 2 )
        {
            printf("\n\nRiders approach! What will you do?\n");
            input("\n1) Greet them\n2) Shoot them\n3) Run away\n\nMake your choice:  ", string, 2);
            int_string = strtol(string, NULL, 0);

            // Check if friendly or not. 20% = Hostile, 80% = Friendly
            number = random_number(1, 100);
            if (int_string == 1 && number >= 21)
            {
                printf("\nYou greet the friendly travelers.\n");
                event = 0;
            }

            else if ( int_string == 1 && number <= 20 )
            {
                printf("\nYou wave at the riders in hopes that they are friendly. Turns out...They aren't.\n");
                printf("They rob you of some of your supplies.\n");
                robbed(family);
                event = 0;
            }

            else if ( int_string == 2 && family->ammo > 10 )
            {
                if ( number >= 21 )
                {
                    // Check how much ammo was used
                    number = random_number(2, 10);
                    printf("\nYou fire at the friendly riders and they flee, but not before one of them falls\n");
                    printf("off their horse. You used up %d rounds of ammo.\n", number);
                    family->ammo -= number;
                    event = 0;
                }
                else if ( number <= 20 )
                {
                    // Check kill amount
                    number = random_number(2, 3);
                    printf("\nYou fire at the hostile riders. You knock %d riders off their horse. The rest flee\n", number);

                    // Money found
                    number = random_number(10, 50);
                    printf("and get away. After checking their corpses you find $%d.\n", number);
                    family->money += number;
                    family->ammo -= random_number(2, 10);
                    event = 0;
                }
            }
        }
        // End Event Two

        // Event Three, Ox in Trouble!
        if ( event_number == 3 )
        {
            // Check if the ox dies or not.
            number = random_number(1, 100);
            if ( number <= 20 )
            {
                printf("\nOne of your oxen stumbles on a rock and breaks its leg. Sadly you had to put it down.\n");
                // Food gained
                number = random_number(30, 100);
                printf("On the bright side you gained %d lbs of food.\n", number);
                family->food += number;
                family->oxen -= 1;
                event = 0;
            }

            else
            {
                printf("\nOne of your oxen stumbles on a rock. Thankfully it catches itself and is unharmed.\n");
                event = 0;
            }
        }
        // End Event Three

        // Event Four, Found an Ox!
        if ( event_number == 4 )
        {
            printf("\nYou find an oxen wandering around. Looks like its owner has been lost. You adopt it and\n");
            printf("add it to your team.\n");
            family->oxen += 1;
            event = 0;
        }
        // End Event Four

        if (event_number == 5)
        {
            printf("\nYou get lost in a dense fog and lose some time.\n");
            miles += random_number(20, 40);
            event = 0;
            
        }

        if ( event_number >= 6)
        {
            printf("\n\nIt's been an uneventful day.\n");
            event = 0;
        }

    }
}
