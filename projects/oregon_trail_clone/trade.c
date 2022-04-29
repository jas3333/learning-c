#include "headers/data.h"
#include <stdio.h>

void trading(struct trail_crew *family)
{
    char string[5];
    int int_string;
    _Bool shopping = 1;


    while(shopping)
    {
        printf("You are at the trading post.\n\n");
        display_stats(family);
        printf("\n\n1) Buy Oxen\n2) Buy Food\n3) Buy Medicine\n4) Buy Clothes\n5) Buy Ammo\n6) Sell\n7) Leave\n");
        input("What would you like to do?: ", string, 2);
        int_string = strtol(string, NULL, 0);

        if (int_string == 1)
        {
            printf("You make your way over to the oxen pen. A farmer greets you and offers to sell you\n");
            printf("oxen at $100 a head.\n\n");
            input("How many would you like to buy?: ", string, 2);
            int_string = strtol(string, NULL, 0);

            if (int_string * 100 > family->money)
                printf("You don't have that much!\n");

            else if (int_string > 0 && int_string * 100 <= family->money)
            {
                printf("You bought %d oxen. The farmer thanks you and sees you on your way.\n", int_string);
                family->oxen += int_string;
                family->money -= int_string * 100;
                
            }
        }

        else if (int_string == 7)
            shopping = 0;
    }
}
