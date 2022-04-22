#include "headers/data.h"
#include <stdio.h>

void training(struct character *player)
{
    char string[2];
    int long int_string;
    
    int requirement[20] = {100, 200, 400, 600};

    display_player(player);
    printf("Would you like to advance a level? Cost is %dexp.\n", requirement[player->level - 1]);
    printf("1) Yes\n2) No\n");

    input("What would you like to do?: ", string, 2);
    int_string = strtol(string, NULL, 0);

    
    
    if (int_string == 2)
        player->location = 6;
    else if (int_string == 1 && player->exp >= requirement[player->level - 1]){
        player->exp -= requirement[player->level - 1];
        player->level += 1;
        player->max_hit_points += 15;
        player->attack += 3;
        player->armor += 3;
        player->location = 6;

    }else{
        printf("You don't have enough exp to do that!\n");
        player->location = 6;
    }
}
