#include "headers/data.h"
#include <stdio.h>

void hunt (struct trail_crew *family)
{
    int hunt_amount;
    hunt_amount = random_number(50, 120);

    if ( family->ammo == 0 )
        printf("Sorry, you don't have any ammo. Should have bought some.\n");
    else {
        printf("Nice shooting, the hunt was a success, you come back with\n");
        printf("%d lbs of meat!\n\n", hunt_amount);
        family->food += hunt_amount;
        family->ammo -= random_number(5, 10);
    }
}
