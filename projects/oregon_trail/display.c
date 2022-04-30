#include "header/data.h"
#include <stdio.h>

void display_info(struct family *family, char orientation)
{
    if (orientation == 'v')
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("| Clothing: %6d      |\n", family->clothes);
        printf("| Money: %9d      |\n", family->money);
        printf("| Oxen: %10d      |\n", family->oxen);
        printf("| Ammo: %10d      |\n", family->ammo);
        printf("| Food: %10d      |\n", family->food);
        printf("| Meds: %10d      |\n", family->medicine);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    }
    else if (orientation == 'h')
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
               "|Clothing: %1d |Money: %4d |Oxen: %1d |Ammo: %4d|Food: %4d |Meds: %1d|\n"
               "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n",
               family->clothes, family->money, family->oxen, family->ammo, family->food, family->medicine);
    }
}

void display_travel_info(struct family *family, char date[], char weather[])
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
           " %5s | %s | Traveled: %d \n"
           "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n", date, weather, family->miles_traveled);
}

