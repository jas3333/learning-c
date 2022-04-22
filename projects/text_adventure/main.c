#include "headers/data.h"

int main()
{
    char choice[2];
    char text[100];
    int long temp_choice = 0;
    _Bool game = 1;

    struct locations game_rooms[8] = {
        {
            .room_title         = "Town Square",
            .room_description   = "You're standing in the town square. It's pretty much empty. You see an inn\n"
                                  "nearby and a forest off in the distance. You also see a new training camp.",
            .exit_descriptions  = "1) Inn\n2) Forest\n3) Training Camp\nh) Heal up(Cost 10g)",
            .exits              = {1, 2, 6},
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
            .exit_descriptions  = "1) Town Square\n2) Look for a fight",
            .exits              = {0, 5},
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
        {
            .room_title         = "Fight",
            .room_description   = "You pull out your weapon and look for a fight.",
            .exit_descriptions  = "\n",
            .exits              = {},
        },
        {
            .room_title         = "Training Camp",
            .room_description   = "You're standing in the training camp. You see warriors training\n"
                                  "and grunting as they swing their weapons at dummies.",
            .exit_descriptions  = "1) Level up\n2) Leave",
            .exits              = {7, 0},
        },
        {
            .room_title         = "Training Camp",
            .room_description   = "You pull out your weapon and start swinging at a dummy.",
            .exit_descriptions  = "\n",
            .exits              = {},
        }



    };

    struct character player;
        player.name             = "Jas";
        player.weapon           = "Rusty Short Sword";
        player.armor            = "Leather Armor(full of holes...)";
        player.hit_points       = 10;
        player.max_hit_points   = 10;
        player.defense          = 5;
        player.attack           = 5;
        player.gold             = 50;
        player.location         = 0;
        player.exp              = 100;
        player.level            = 1;
        
    system("clear");
    while(game)
    {
        if (player.location == 4)
            dice(&player.gold, &player.location, &player.hit_points);

        if (player.location == 5)
            battle(&player);

        if (player.location == 7)
            training(&player);

        display_room(player, game_rooms);

        input("Enter your choice: ", choice, 2);
        temp_choice = strtol(choice, NULL, 0);
        system("clear");

        if(exit_is_valid(temp_choice, player.location, game_rooms))
            player.location = game_rooms[player.location].exits[temp_choice - 1];

        if (strcmp(choice, "h") == 0){
            player.hit_points = player.max_hit_points;
            player.gold -= 10;
        }
        
        if (strcmp(choice, "0") == 0)
            game = 0;
        if (strcmp(choice, "g") == 0)
            player.gold += 500;
    }
       
    return 0;
}

