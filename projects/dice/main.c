#include "header/data.h"
#include <stdio.h>

int main()
{
    srand((unsigned)time(NULL));
    int player_money = 500;
    int computer_money = 5000;
    int player_dice, computer_dice;
    char bet_amount[5];
    long int_bet_amount;
    _Bool game = 1;

    
    while(game)
    {
        printf("=-=-=-=-=-=-=-=-=\n");
        printf("Player: $%d\nComputer: $%d\n", player_money, computer_money);
        printf("=-=-=-=-=-=-=-=-=\n");

        input("How much would you like to bet?: ", bet_amount, 5);
        int_bet_amount = strtol(bet_amount, NULL, 0);
        if (int_bet_amount > player_money || int_bet_amount > computer_money) {
            printf("You can't make that bet.\n");
        }else {
            player_dice = random_number(1, 6);
            computer_dice = random_number(1, 6);
            printf("Player rolled: %d\n", player_dice);
            printf("Computer rolled: %d\n", computer_dice);

            if (player_dice > computer_dice) {
                printf("Nice, you won $%ld\n", int_bet_amount);
                player_money += int_bet_amount;
                computer_money -= int_bet_amount;
            }else if (player_dice  < computer_dice) {
                printf("Sorry, you lost $%ld\n", int_bet_amount);
                player_money -= int_bet_amount;
                computer_money += int_bet_amount;
            }
        
        }
        if (player_money < 1 || computer_money < 1)
            game = 0;

    }

    system("clear");
    if (player_money > computer_money)
        printf("Nice, you won!\n");
    else
        printf("Sorry you lost, better luck next time.\n") ;
    
    return 0;
}
