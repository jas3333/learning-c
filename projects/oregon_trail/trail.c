#include "header/data.h"
#include <stdio.h>

void trail(struct family *family, int trading_post)
{
    char string[5];
    int choice;
    int game = 1;

    struct game_text the_trail = {
        .description            = "=-=-=-=-=-=-=-=-=-=\n"
                                  "|    The Trail    |\n"
                                  "=-=-=-=-=-=-=-=-=-=\n\n",
        .dialog                 = "You're on the trail.\n",
        .choices                = {
                                    "1) Hunt\n2) Continue on\n\n",
                                    "1) Hunt\n2) Continue on\n3) Stop at the next trading post\n\n"
                                  },
    };

    while (game) 
    {

        display_info(family, 'h');

        if (trading_post)
            printf("%s%s%s", the_trail.description, the_trail.dialog, the_trail.choices[1]);
        else
            printf("%s%s%s", the_trail.description, the_trail.dialog, the_trail.choices[0]);
 
        choice = int_input("What would you like to do?: ", string, 2); 
 
        // Go Hunting
        if (choice == 1)
        {
            // Ammo Check, needs at least 10
            if (family->ammo < 10)
                printf("You don't have enough ammo.\n");
            else
            {
                hunt(family);
                game = 0;
            }
        }
 
        // Continue On 
        if (choice == 2)
        {
           family->miles_traveled += randint(10, 30) * family->oxen;
           game = 0;
        }

        // Go to the trading post
        if (choice == 3 && trading_post == 1)
        {
            post(family);
            game = 0;
        }

     }


}
