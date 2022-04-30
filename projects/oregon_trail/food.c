#include "header/data.h"
#include <stdio.h>

void food(struct family *family)
{
    int game = 1;
    int choice;
    char string[5];


    struct game_text food_consumption = {

        .description        = "=-=-=-=-=-=-=-=-=\n"
                              "|     Camp      |\n"
                              "=-=-=-=-=-=-=-=-=\n\n",
        
        .dialog             = "The sun begins to set and you setup camp for the night.\n"
                              "How much food will you eat?\n\n",

        .choices            = "1) Eat Poorly\n2) Eat Moderately\n3) Eat Like a King\n\n",
        .positive           = {
                                "You decide it's best to eat light for the night.\n",
                                "You deicde to eat moderately. Don't want your family getting sick.\n",
                                "You decide you have a lot of food in reserve, so might as well eat like\n"
                                "a king!\n",
                              }, 
        .negative           = {
                                "That isn't an option. Try again.\n",
                                "Sorry, looks like you are out of food. You and your family starve\n"
                                "to death. What a sad way to go. Next time buy more food or hunt more.\n\n",
                              },
    };
    
    
    if (family->food < 10)
    {
        puts(food_consumption.negative[1]);
        game = 0;
        family->is_alive = 0;
    }

    while (game)
    {

        display_info(family);
        printf("%s%s%s", food_consumption.description, food_consumption.dialog, food_consumption.choices[0]);
        choice = int_input("What will you choose?: ", string, 2);

        // Eat Poorly
        if (choice == 1)
        {
            puts(food_consumption.positive[0]);
            family->food -= randint(10, 20);
            game = 0;
        }

        // Eat Moderately
        else if (choice == 2)
        {
            puts(food_consumption.positive[1]);
            family->food -= randint(20, 40);
            game = 0;
        }

        // Eat Like a King
        else if (choice == 3)
        {
            puts(food_consumption.positive[2]);
            family->food -= randint(40, 60);
            game = 0;
        }
        else 
            puts(food_consumption.negative[0]);
    }
}
