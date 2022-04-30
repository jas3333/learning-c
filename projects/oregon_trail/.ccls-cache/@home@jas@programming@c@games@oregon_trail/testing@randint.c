#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int min, int max);

int main()
{

    srand((unsigned)time(NULL));

    int number; 
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int should_be_zero = 0;

    for (int counter = 0; counter < 100; counter++)
    {
        number = randint(1, 6);
        if (number == 1)
            one += 1;
        else if (number == 2)
            two += 1;
        else if (number == 3)
            three += 1;
        else if (number == 4)
            four += 1;
        else if (number == 5)
            five += 1;
        else if (number == 6)
            six += 1;
        else
            should_be_zero += 1;
    }

    printf("One: %d\n", one);
    printf("Two: %d\n", two);
    printf("Three: %d\n", three);
    printf("Four: %d\n", four);
    printf("Five: %d\n", five);
    printf("Six: %d\n", six);
    printf("Zero: %d\n", should_be_zero);

    return 0;
}

int randint(int min, int max)
{
    int number;

    number = (rand() % max) + min;


    return number;
}
