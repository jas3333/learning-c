#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand((unsigned)time(NULL));
    int number;

    for (int counter = 0; counter < 10; counter++)
    {
        number = rand() % 10 + 5;
        if (number > 10)
            number -= 5;
        printf("%d\n", number);
    }

    return 0;
}
