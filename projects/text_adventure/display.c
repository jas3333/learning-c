#include "headers/data.h"
#include <stdio.h>

void display_room(struct character player, struct locations *rooms)
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Name: %s\n", player.name);
    printf("HP: %d\n", player.hit_points);
    printf("Gold: %d\n", player.gold);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("%s\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n", rooms[player.location].room_title );
    printf("%s\n\n", rooms[player.location].room_description);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n%s\n", rooms[player.location].exit_descriptions);

}
