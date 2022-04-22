#include "headers/data.h"
#include <stdio.h>
#include <string.h>

void battle(struct character *player)
{

    int monster_selector;
    char user_input[2];
    int int_user_input;

    struct monster monsters[3][3] = {
        {
            {
                .name          = "Puny Goblin",
                .hit_points    = 8,
                .attack        = 2,
                .defense       = 2,
                .gold          = random_number(2, 16),
                .exp_given     = 5,
            },
            {
                .name          = "Rabbid Bunny",
                .hit_points    = 6,
                .attack        = 1,
                .defense       = 1,
                .gold          = random_number(5, 15),
                .exp_given     = 3,
            },
            {
                .name          = "Giant Rat",
                .hit_points    = 5,
                .attack        = 1,
                .defense       = 1,
                .gold          = random_number(5, 13),
                .exp_given     = 3,
            }
        },
        {
            {
                .name          = "Orc",
                .hit_points    = 15,
                .attack        = 6,
                .defense       = 5,
                .gold          = random_number(20, 35),
                .exp_given     = 13,
            },
            {
                .name          = "Wolf",
                .hit_points    = 17,
                .attack        = 7,
                .defense       = 3,
                .gold          = random_number(20, 45),
                .exp_given     = 17,
            },
            {
                .name          = "Bandit",
                .hit_points    = 14,
                .attack        = 8,
                .defense       = 4,
                .gold          = random_number(65, 120),
                .exp_given     = 20,
            }
        }
    };


    monster_selector = random_number(0, 3);
    char *monster_name      = monsters[player->level - 1][monster_selector].name;
    int monster_hp          = monsters[player->level - 1][monster_selector].hit_points;
    int monster_attack      = monsters[player->level - 1][monster_selector].attack;
    int monster_gold        = monsters[player->level - 1][monster_selector].gold;
    int monster_defense     = monsters[player->level - 1][monster_selector].defense;
    int monster_exp_given   = monsters[player->level - 1][monster_selector].exp_given;
    int monster_damage      = monsters[player->level - 1][monster_selector].attack - player->defense;

    if (monster_damage < 1)
        monster_damage = 1;

    _Bool game = 1;
    while (game)
    {
        printf("You whip out your %s and look for a fight.\n", player->weapon);
        display_battle(player, monster_hp, monster_name);
        printf("\n1) Attack\n2) Run away\n");
        printf("Monster Damage : %d\n", monster_damage);
        input("What would you like to do?: ", user_input, 2);
        system("clear");
        int_user_input = strtol(user_input, NULL, 0);

        // Player Attacks
        if (int_user_input == 1){
            printf("You swing and hit the %s for %d damage\n", monster_name, player->attack - monster_defense);
            monster_hp -= player->attack - monster_defense;

            // Check if monster is still alive
            if (monster_hp > 0){
                printf("The %s hits back for %d damage\n", monster_name, monster_damage);
                player->hit_points -= monster_damage;
            }else {
                printf("You slayed the %s.\nYou gain %d exp and found %d gold.\n", monster_name, monster_exp_given, monster_gold);
                player->exp += monster_exp_given;
                player->gold += monster_gold;
                game = 0;
            }
        }
        // Player Runs
        else if (int_user_input == 2){
            game = 0;
        }



      }




    player->location = 2;








}
