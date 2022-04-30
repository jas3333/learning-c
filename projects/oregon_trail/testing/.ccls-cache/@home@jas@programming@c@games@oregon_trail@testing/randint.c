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
    int greater_than_100 = 0;
    int between = 0;

    for (int counter = 0; counter < 100; counter++)
    {
        number = randint(1, 6);
        printf("%d\n", number);
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
        else if (number > 100)
            greater_than_100 += 1;
        else if (number >= 50 && number <= 51)
            between += 1;
    }

    printf("One: %d\n", one);
    printf("Two: %d\n", two);
    printf("Three: %d\n", three);
    printf("Four: %d\n", four);
    printf("Five: %d\n", five);
    printf("Six: %d\n", six);
    printf("Zero: %d\n", should_be_zero);
    printf("Greater than 100: %d\n", greater_than_100);
    printf("Between(Should equal counter): %d", between);
    

    return 0;
}

int randint(int min, int max)
{
    int number;

    number = (rand() % (max - min + 1)) + min;

    return number;
}
