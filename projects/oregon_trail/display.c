#include "header/data.h"

void display_info(struct family *family)
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
