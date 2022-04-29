#include "headers/data.h"
#include <stdio.h>

void intro(struct trail_crew *family)
{
    char string[5];
    int int_string;
    int total;
    _Bool shopping = 1;


    system("clear");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\tWelcome to the Oregon Trail.\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("You have a wife and two kids and decided to seek out a better life.\n");
    printf("Before you head out, you will need to put together a kit.\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");


    while(shopping)
    {
        display_stats(family);
        printf("\n1) Buy oxen\n2) Buy food\n3) Buy ammo\n4) Buy medicine\n5) Buy clothes\n6) Set out\n\n");
        input("What would you like to do?: ", string, 2);
        int_string = strtol(string, NULL, 0);

        switch (int_string) 
        {
            case 1:
                printf("You make your way over to the oxen pen. The farmer working\n");
                printf("the pen informs you each oxen will cost you $100.\n");
                input("How many oxen would you like to buy?: ", string, 2);
                int_string = strtol(string, NULL, 0);

                total = int_string * 100;

                if (total > family->money)
                {
                    printf("You and your family excitedly leave town with all your oxen.\n");
                    printf("You get 20 miles out and realize you didn't think to save a little\n");
                    printf("and buy other supplies. You and your family all die of starvation and\n");
                    printf("become wolf food.\nYOU DIED\n");
                    shopping = 0;
                    family->alive = 0;
                }

                else
                {
                    printf("You buy %d oxen.\n", int_string);
                    family->money -= total;
                    family->oxen += int_string;
                }
                break;

            case 2:
                printf("You make your way over to the general store to buy some food.\n");
                printf("The store clerk greets you and lets you know 1 lb of food cost $1\n");
                input("How much food would you like to buy?: ", string, 5);
                int_string = strtol(string, NULL, 0);

                if ( int_string > family->money )
                {
                    printf("Sorry, you don't have that much money.\n");
                    break;
                }

                else 
                {
                    printf("You bought %d lbs of food\n", int_string);
                    family->money -= int_string;
                    family->food += int_string;
                }
                break;

            case 3:
                printf("You make your way over to the gun store. The store clerk lets\n");
                printf("you know that a box of 25 rounds cost $5\n");
                input("How many boxes of ammo would you like to buy?: ", string, 2);
                int_string = strtol(string, NULL, 0);

                if ( int_string * 5 > family->money )
                {
                    printf("Sorry, you don't have that much money.\n");
                    break;
                }

                else 
                {
                    printf("You buy %d boxes of ammo.\n", int_string);
                    family->ammo += int_string * 25;
                    family->money -= int_string * 5;
                }
                break;

            case 4:
                printf("You make your way over to the drug store. The clerk lets you know\n");
                printf("Each bottle of medicine will cost $10.\n");
                input("How many bottles do you want to buy?: ", string, 2);
                int_string = strtol(string, NULL, 0);

                if ( int_string * 10 > family->money ) 
                {
                    printf("Sorry, you don't have enough money.\n");
                    break;
                }

                else 
                {
                    printf("You buy %d bottles of medicine.\n", int_string);
                    family->medicine += int_string;
                    family->money -= int_string * 10;
                }
                break;

            case 5:
                printf("You make your way over to the clothing store. The clerk greets you\n");
                printf("and lets you know each bundle of clothes will cost $10.\n");
                input("How many bundles do you want to buy?: ", string, 2);
                int_string = strtol(string, NULL, 0);

                if ( int_string * 10 > family->money )
                {
                    printf("Sorry you don't have enough money.\n");
                    break;
                }

                else 
                {
                    printf("You buy %d bundles of clothing.\n", int_string);
                    family->clothes += int_string;
                    family->money -= int_string * 10;
                }
                break;

            case 6:
                system("clear");
                printf("You decide it's time to set out on the trail. Good luck.\n");
                shopping = 0;
                break;

            default:
                printf("That's not an option. Try again.\n");

        }
    }
}
