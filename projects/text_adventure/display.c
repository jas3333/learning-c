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

void display_battle(struct character *player, int hp, char *name)
{
    printf("=-=-=-=-=-=-=-=\t\t=-=-=-=-=-=-=-=\n");
    printf("%s\t\t\t%s\n", player->name, name);
    printf("HP: %d\t\t\tHP: %d\n", player->hit_points, hp);
}

void display_player(struct character *player)
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%s\n", player->name);
    printf("Level: %d\n", player->level);
    printf("Gold: %d\n", player->gold);
    printf("Exp: %d\n", player->exp);
}
