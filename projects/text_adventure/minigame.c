#include "headers/data.h"
#include <stdio.h>

void dice(int *gold, int *location)
{
    srand((unsigned)time(NULL));
    char string[2];
    char bet_amount[10];
    long int_bet_amount;
    long int_string;
    int player_dice, computer_dice;
    int player_gold = *gold;
    int computer_gold = 500;
    _Bool game = 1;

    printf("You join the rough looking gang and play some dice!\n\n");  
    printf("A rough beared angry looking man is playing against you.\n");

    while(game)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=--=\n");
        printf("Your gold: %d\nAngry Mans gold: %d\n", player_gold, computer_gold);
        printf("=-=-=-=-=-=-=-=-=-=-=-=--=\n\n\n");
        printf("1) Make bet and roll\n2) Run away\n");
        input("What would you like to do?: ", string, 2);
        int_string = strtol(string, NULL, 0);

        if(int_string == 1 && player_gold > 0)
        {
            input("How much would you like to bet?: ", bet_amount, 5);
            int_bet_amount = strtol(bet_amount, NULL, 0);
            system("clear");

            if (int_bet_amount > player_gold || int_bet_amount > computer_gold){
                printf("You can't make that bet!\n");
                system("clear");
            }else{
                player_dice = random_number(1, 6);
                computer_dice = random_number(1, 6);
                printf("You rolled a: %d\n", player_dice);
                printf("Angry man a:  %d\n", computer_dice);

                if (player_dice > computer_dice) {
                    player_gold += int_bet_amount;
                    computer_gold -= int_bet_amount;
                    printf("Nice, you beat the angry man and won %ld!\n", int_bet_amount);
                }else if (player_dice < computer_dice) {
                    player_gold -= int_bet_amount;
                    computer_gold += int_bet_amount;
                    printf("Looks like you lost and gave up %ld gold.\n", int_bet_amount);
                }

            }
            
        }
        if (int_string == 2){
            *gold = player_gold;
            *location = 1;
            game = 0;
        }

        if (player_gold < 1 || computer_gold < 1){
            *gold = player_gold;
            *location = 1;
            game = 0;
        }
    }
}
