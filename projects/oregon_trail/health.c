#include "header/data.h"
#include <stdio.h>

void health_check(struct family *family)
{
    int sick_check, disease_index;
    char string[5];
    
    char *disease[] = {
        "Cholera",
        "Typhoid",
        "Measles",
        "Dysentery",
        "Diphtheria",
    };

    
    // Higher value lowers chance of getting diseased
    sick_check = randint(1, 10);

    // Set sick threshold based on health
    if (family->health < 60 && sick_check < 2)
    {
        disease_index = randint(1, 5) - 1;

        if (family->medicine > 0 && family->size > 0)
        {
            printf("A family member has %s. You used a bottle of medicine.\n", disease[disease_index]);
            input("Press enter to continue.", string, 0);
            family->medicine -= 1;

        }

        else if(family->medicine < 1 && family->size == 1)
        {
            printf("You have %s and die.\n", disease[disease_index]);
            input("Press enter to continue.", string, 0);
            family->size -= 1;
        }

        else
        {
            printf("A family member has %s. Sadly you are out of medicine and they die.\n", disease[disease_index]);
            input("Press enter to continue.", string, 0);
            family->size -= 1;
        }
    }
}
