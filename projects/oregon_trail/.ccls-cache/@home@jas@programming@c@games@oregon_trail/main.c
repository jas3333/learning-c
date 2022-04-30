#include "header/data.h"
#include <stdio.h>

int main()
{
    srand((unsigned)time(NULL));

    int trading_post = 0;
    int date_index = 0;
    int event_amount;

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

    // Intro 
    intro(&family);

    while (family.is_alive)
    {
        // The Trail
        puts(dates[date_index]);
        printf("%d\n", family.miles_traveled);
        trail(&family, trading_post);

        // Set how many events you want
        event_amount = 1;
        while (event_amount)
        {
            events(&family);
            event_amount -= 1;
        }

        food(&family);

        // Advance the Date
        date_index += 1;
        
        // Miles traveled today based on oxen amount
        family.miles_traveled +=  randint(20, 30) * family.oxen;

        if (date_index == 18 && family.miles_traveled < 2000)
        {
            printf("You and your family gave it all, but unfortunately you didn't make it.\n"
                   "You got caught in a blizzard and your whole family froze to death.");
            family.is_alive = 0;
        }

        if (date_index <= 18 && family.miles_traveled >= 2000)
        {
            printf("You and your family pull into Oregon City after a long grueling trek.\n"
                   "You find a plot of land and live happily ever after.\n");
            family.is_alive = 0;
        }
           
    }


    return 0;
}
