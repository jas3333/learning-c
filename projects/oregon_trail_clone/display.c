#include "headers/data.h"
#include <stdio.h>

void display_stats(struct trail_crew *family){

    printf("Family size: %d\n", family->kids + family->parents);
    printf("Oxen: %d\n", family->oxen);
    printf("Medicine: %d\n", family->medicine);
    printf("Clothes: %d\n", family->clothes);
    printf("Food: %d\n", family->food);
    printf("Ammo: %d\n", family->ammo);
    printf("Money: $%d\n", family->money);

}

void trail_stats(struct trail_crew *family)
{
    printf("Oxen: %d Medicine: %d Food: %d Ammo: %d\n", family->oxen, family->medicine, family->food, family->ammo);
}
