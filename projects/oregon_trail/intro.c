#include "header/data.h"
#include <stdio.h>

void intro(struct family *family)
{

    char string[5];
    int choice;
    int game = 1;

    struct game_text game_intro[10] = {
        {
            
            .description        = "Game Intro:\n",
            .dialog             = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
                                  "                            Welcome to the Oregon Trail\n"
                                  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"
                                  "Before you and your family set off on your journey, you will need to put together\n"
                                  "a travel kit. You can enter the various shops around town and buy what you need.\n"
                                  "You will start your journey with $700. Spend wisely, the trail is very unforgiving.\n\n",

            .choices            = "1) Buy Oxen\n2) Buy Ammo\n3) Buy Food\n4) Buy Medicine\n5) Buy Clothes\n6) Set Out\n\n",

        },
        {
            .description        = "=-=-=-=-=-=-=-=-=\n"
                                  "|    Oxen Pen   |\n"
                                  "=-=-=-=-=-=-=-=-=\n",

            .dialog             = "You make your way over to the oxen pen. A farmer greets you and informs you he is\n"
                                  "selling oxen at $100 a head.\n\n",

            .negative           = "You don't have enough money!\n",
            .positive           = "The farmer thanks you for your purchase.\n",
                                  
        },
        {
            .description        = "=-=-=-=-=-=-=-=-=\n"
                                  "|   Gun Store   |\n"
                                  "=-=-=-=-=-=-=-=-=\n",

            .dialog             = "You make your way over to the gun store. The clerk greets you and tells you that\n"
                                  "he is selling boxes of 25 rounds for $5.\n\n",
            .negative           = "You don't have enough money!\n",
            .positive           = "The clerk thanks you for your purchase.\n",
          
            

        },
        {
            .description        = "=-=-=-=-=-=-=-=-=\n"
                                  "|   Food Store  |\n"
                                  "=-=-=-=-=-=-=-=-=\n",

            .dialog             = "You make your way over to the food store. The clerk greets you and tells you that\n"
                                  "he is selling bulk foods of 25 lbs for $25.\n\n",
            .negative           = "You don't have enough money!\n",
            .positive           = "The clerk thanks you for your purchase.\n",


        },
        {
            .description        = "=-=-=-=-=-=-=-=-=\n"
                                  "|    Pharmacy   |\n"
                                  "=-=-=-=-=-=-=-=-=\n",

            .dialog             = "You make your way over to the pharmacy. The clerk greets you and tells you that\n"
                                  "he is selling bottles of medicine for $10 a bottle.\n\n",
            .negative           = "You don't have enough money!\n",
            .positive           = "The clerk thanks you for your purchase.\n",




        },
        {
            .description        = "=-=-=-=-=-=-=-=-=-=-=\n"
                                  "|   Clothes Store   |\n"
                                  "=-=-=-=-=-=-=-=-=-=-=\n",

            .dialog             = "You make your way over to the clothing store. The clerk greets you and tells you that\n"
                                  "she is selling bundles of clothes for $20 a bundle.\n\n",
            .negative           = "You don't have enough money!\n",
            .positive           = "The clerk thanks you for your purchase.\n",
        },
    };

    system("clear");
    printf("%s\n", game_intro[0].dialog);

    while (game)
    {
        display_info(family, 'h');
        printf("%s", game_intro[0].choices[0]);
        choice = int_input("Where do you want to go?: ", string, 2);

        // Oxen Pen
        if (choice == 1)
        {
            printf("%s\n%s", game_intro[1].description, game_intro[1].dialog);
            choice = int_input("How many oxen would you like to buy?: ", string, 2);

            if (choice * 100 > family->money)
               puts(game_intro[1].negative[0]);

            else if (choice > 0)
            {
                puts(game_intro[1].positive[0]);
                family->oxen += choice;
                family->money -= choice * 100;
            }
        }

        // Gun Store
        else if (choice == 2)
        {
            printf("%s\n%s", game_intro[2].description, game_intro[2].dialog);
            choice = int_input("How many boxes of ammo do you want to buy?: ", string, 2);

            if (choice * 5 > family->money)
                puts(game_intro[2].negative[0]);
            
            else if (choice > 0)
            {
                puts(game_intro[2].positive[0]);
                family->ammo += choice * 25;
                family->money -= choice * 5;
            }
        }

        // Food Store
        else if (choice == 3)
        {
            printf("%s\n%s", game_intro[3].description, game_intro[3].dialog);
            choice = int_input("How many boxes of food do you want to buy?: ", string, 2);

            if (choice * 5 > family->money)
                puts(game_intro[3].negative[0]);
            
            else if (choice > 0)
            {
                puts(game_intro[3].positive[0]);
                family->food += choice * 25;
                family->money -= choice * 25;
            }
        }

        // Pharmacy
        else if (choice == 4)
        {
            printf("%s\n%s", game_intro[4].description, game_intro[4].dialog);
            choice = int_input("How many bottles of medicine do you want to buy?: ", string, 2);

            if (choice * 10 > family->money)
                puts(game_intro[4].negative[0]);
            
            else if (choice > 0)
            {
                puts(game_intro[4].positive[0]);
                family->medicine += choice;
                family->money -= choice * 10;
            }
        }

        // Clothing Store 
        else if (choice == 5)
        {
            printf("%s\n%s", game_intro[5].description, game_intro[5].dialog);
            choice = int_input("How many bundles will you buy?: ", string, 2);

            if (choice * 20 > family->money)
                puts(game_intro[5].negative[0]);
            
            else if (choice > 0)
            {
                puts(game_intro[5].positive[0]);
                family->clothes += choice;
                family->money -= choice * 20;
            }
        }
       
        // Get on the Trail
        if (choice == 6)
            game = 0;
    }
}
