#include "headers/data.h"
#include <stdio.h>

int main()
{
    srand((unsigned)time(NULL));

    // Used for input statement
    char string[5];
    int int_string;

    int travel_speed;
    int miles_left = 2000;
    int date = 0;
    // Set amount of events per day.
    int event;

    int trading_post = 0;

    // If enabled will slow down progress
    _Bool mountain_pass = 0;



    char dates[18][20] = {
        "April 12",
        "April 26", 
        "May 10", 
        "May 24", 
        "June 7",
        "June 21",
        "July 5", 
        "July 19",
        "August 16", 
        "August 31",
        "September 13",
        "September 27",
        "October 11",
        "October 25",
        "November 8",
        "November 22",
        "December 6",
        "December 20",
    };

    struct trail_crew family = {
        .oxen           = 3,
        .kids           = 2,
        .parents        = 2,
        .money          = 700,
        .health         = 100,
        .ammo           = 200,
        .medicine       = 10,
        .clothes        = 10,
        .food           = 100,
        .alive          = 1,
    }; 
    
    intro(&family);

    while ( family.alive ){
        // Set amount of events
        event  = 2;

        // Traveling the Trail Module
        if ( mountain_pass )
            printf("Mountain pass\n");

        the_trail(&family, dates[date], &miles_left, &trading_post);
                
        // Check Food Consumption
        food_check(&family);

        // Cause Misery!
        while ( event )
        {
            events(&family, &miles_left);
            event -= 1;
        }
 
        // Advance mileage, date 
        date = date + 1;
        trading_post = trading_post + 1;

        if (mountain_pass)
            miles_left     -= random_number(10, 20) * family.oxen;
        else
            miles_left     -= random_number(15, 30) * family.oxen;
        
        // Check if the game should continue
        if ( date == 18 && miles_left > 0 )
        {
            system("clear");
            printf("You didn't make it to Oregon City before the winter is over.\n");
            printf("Your family got caught in a blizzard and died.\n");
            family.alive = 0;
        }

        if ( date <= 18 && miles_left < 1 )
        {
            system("clear");
            printf("Congratulations, you survived the trip! You and your family find\n");
            printf("a settlement and live long happy lives.\n");
            family.alive = 0;
        }
        
        if ( family.health <= 60 )
            health_check(&family);
        
        // Create a mountain pass every 4 turns
        if ( date % 4 == 0 )
            mountain_pass = 1;
        else
            mountain_pass = 0;
    }

    return 0;
}
