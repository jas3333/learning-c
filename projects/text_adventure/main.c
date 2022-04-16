#include "headers/data.h"

int main()
{
    char choice[2];
    char text[100];
    int long temp_choice = 0;
    _Bool game = 1;

    struct locations game_rooms[5] = {
        {
            .room_title         = "Town Square",
            .room_description   = "You're standing in the town square. It's pretty much empty. You see an inn\n"
                                  "nearby and a forest off in the distance.",
            .exit_descriptions  = "1) Inn\n2) Forest",
            .exits              = {1, 2},
        },
        {
            .room_title         = "Inn",
            .room_description   = "You're standing in the inn. It's filled with drunk patrons dancing about.\n"
                                  "You see a door that leads to a back room.",
            .exit_descriptions  = "1) Town Square\n2) Back room",
            .exits              = {0, 3},
        },
        {
            .room_title         = "The Forest",
            .room_description   = "You're standing in a heavily wooded area.",
            .exit_descriptions  = "1) Town Square",
            .exits              = {0},
        },
        {
            .room_title         = "Back Room",
            .room_description   = "You wander into a dimly lit smoke filled room. A group of rough looking\n"
                                  "characters are sitting at a table throwing dice.",
            .exit_descriptions  = "1) Leave\n2) Play dice",
            .exits              = {1, 4},
        },
        {
            .room_title         = "Play Dice",
            .room_description   = "You decide to join the rough group and play a game of dice.",
            .exit_descriptions  = "\n",
            .exits              = {},
        },
    };

    struct character player;
        player.name         = "Jas";
        player.weapon       = "Rusty Short Sword";
        player.armor        = "Leather Armor(full of holes...)";
        player.hit_points   = 10;
        player.defense      = 5;
        player.attack       = 5;
        player.gold         = 50;
        player.location     = 0;
        
    system("clear");
    while(game)
    {

        if (player.location == 4)
            dice(&player.gold, &player.location);

        display_room(player, game_rooms);

        input("Enter your choice: ", choice, 2);
        temp_choice = strtol(choice, NULL, 0);
        system("clear");

        if(exit_is_valid(temp_choice, player.location, game_rooms))
            player.location = game_rooms[player.location].exits[temp_choice - 1];
        
        if (strcmp(choice, "0") == 0)
            game = 0;
    }
       
    return 0;
}

