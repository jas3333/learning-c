#include "headers/data.h"
#include <stdio.h>

void robbed(struct trail_crew *family)
{
    int number;

    // Medicine Lost
    number = random_number(1, 3);
    if ( number > family->medicine )
        family->medicine = 0;
    else
        family->medicine -= number;

    // Food Lost
    number = random_number(20, 40);
    if ( number > family->food )
        family->food = 0;
    else
        family->food -= number;

    // Ammo Lost
    number = random_number(10, 20);
    if ( number > family->ammo )
        family->ammo = 0;
    else
        family->ammo -= number;

    // Clothes Lost
    number = random_number(1, 3);
    if ( number > family->clothes )
        family->clothes = 0;
    else
        family->clothes -= number;
}

void health_check(struct trail_crew *family)
{
    int number;
    char disease[5][20] = {
        "Dysentery",
        "Cholera", 
        "Typhoid fever",
        "Diphtheria",
        "Measles",
    };

    if ( number <= 30 )
    {
        number = random_number(0, 4);
        if ( family->medicine > 0 )
        {
            printf("Your child got %s. You give them some medicine and hope for a recovery.\n", disease[number]);
            family->medicine -= 1;
        }

        else 
        {
            printf("Your child got %s. Unfortunatley you don't have any medicine. If left unchecked\n", disease[number]); 
            printf("they could die.\n");
        }
    }

    else 
    {
        printf("\nYour families health is getting poor. You should eat better.\n");
    }
}

void the_trail(struct trail_crew *family, char date[], int *miles_left, int *trading_post)
{
    int event = 1;
    char string[5];
    int int_string;

    while ( event )
    {
        printf("\nIt is %s and you are on the trail. You have a total of %d miles to go.\n", date, *miles_left);
        trail_stats(family);
        
        if (*trading_post == 3)
        {
            input("\n1) Hunt\n2) Continue on\n3) Stop at trading post\nWhat would you like to do?: ", string, 2);
            int_string = strtol(string, NULL, 0);
        }

        else 
        {
            input("\n1) Hunt\n2) Continue on\n\nWhat would you like to do?: ", string, 2);
            int_string = strtol(string, NULL, 0);
        }
       
        if ( int_string == 1 )
        {
            hunt(family);
            event = 0;
        }

        else if ( int_string == 2 ) 
        {
            printf("You decide to continue on and get in as many miles as possible.\n\n");
            *miles_left -= random_number(15, 40) * family->oxen;
            event = 0;
        }

        else if ( int_string == 3 && *trading_post == 3)
        {
            printf("You make your way to the nearest trading post.\n");
            trading(family);
            *trading_post = 0;
            event = 0;
        }
    }
}

void food_check(struct trail_crew *family)
{
    char string[5];
    int int_string;
    _Bool eatting = 1;

    while (eatting)
    {
        printf("Night rolls in, how well will you eat tonight?\n\n");
        input("1) Poorly\n2) Moderately\n3) Well\n\nYour choice: ", string, 2);
        int_string = strtol(string, NULL, 0);
     
        if ( int_string == 1 )
        {
            printf("You decide to conserve the food as best as you can.\n");
            family->health -= 30;
            family->food -= random_number(10, 20);
            eatting = 0;
        }

        else if ( int_string == 2 )
        {
            printf("You decide it's best to eat moderately. Don't want to\n");
            printf("go through all your food too fast.\n");
            family->health -= 10;
            family->food -= random_number(20, 40);
            eatting = 0;
        }

        else if ( int_string == 3 )
        {
            printf("You decide to eat like a king tonight!\n");
            family->health += 10;
            family->food -= random_number(40, 60);
            eatting = 0;
        }
            
    }
}


