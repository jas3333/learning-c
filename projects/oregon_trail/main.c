#include "header/data.h"
#include <stdio.h>

int main()
{
    srand((unsigned)time(NULL));

    int trading_post = 0;
    int date_index = 0;
    int weather_index = 0;
    int event_amount;
    int mountains = 0;
    int mountain_penalty = 0;

    struct family family = {
        .oxen           = 3,
        .money          = 700,
        .health         = 100,
        .size           = 4,
        .is_alive       = 1,
        .ammo           = 100,
        .food           = 200,
        .medicine       = 4,
        .clothes        = 4,
        .miles_traveled = 0,
    };

    char *dates[] = {
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

    char *spring_weather[] = {
        "Sunny",
        "Cloudy",
        "Raining",
        "Downpour",
    };

    char *summer_weather[] = {
        "Sunny",
        "Cloudy", 
        "Raining",
        "Heat Wave",
    };

    char *fall_weather[] = {
        "Sunny",
        "Cloudy",
        "Light Snow",
        "Blizzard",
    };

    // Intro 
    intro(&family);

    while (family.is_alive)
    {
        // The Trail Display Info
        if (date_index < 4 )
            display_travel_info(&family, dates[date_index], spring_weather[weather_index]);
        if (date_index > 3 && date_index < 11)
            display_travel_info(&family, dates[date_index], summer_weather[weather_index]);
        if (date_index >= 11)
            display_travel_info(&family, dates[date_index], fall_weather[weather_index]);
        if (mountains)
            printf("=-=-=-=-=-=-=-=-=-=-=-=\n"
                   "|  Rugged Mountains!  |\n"
                   "=-=-=-=-=-=-=-=-=-=-=-=\n");

        
        // On the Trail
        trail(&family, trading_post);

        // Set how many events you want
        event_amount = 1;
        while (event_amount)
        {
            events(&family);
            event_amount -= 1;
        }

        // How will you ration your food?
        food(&family);

        // Advance the Date
        date_index += 1;

        // Add some rugged mountains
        if (date_index % 5 == 0)
        {
            mountains = 1;
            mountain_penalty = randint(10, 40);
        }
        else
        {
            mountains = 0;
            mountain_penalty = 0;
        }

        // Set the weather
        weather_index = randint(1, 4) - 1;
        
        // Miles traveled based on oxen amount
        if (weather_index == 3)
            family.miles_traveled +=  randint(10, 20) * family.oxen - mountain_penalty;
        else
            family.miles_traveled +=  randint(25, 35) * family.oxen - mountain_penalty;

        // YOU DIED
        if (date_index == 18 && family.miles_traveled < 2000)
        {
            printf("You and your family gave it all, but unfortunately you didn't make it.\n"
                   "You got caught in a blizzard and your whole family froze to death.");
            family.is_alive = 0;
        }

        // Winning
        if (date_index <= 18 && family.miles_traveled >= 2000)
        {
            printf("You and your family pull into Oregon City after a long grueling trek.\n"
                   "You find a plot of land and live happily ever after.\n");
            family.is_alive = 0;
        }
           
    }
    // End Main Loop


    return 0;
}