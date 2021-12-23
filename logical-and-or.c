#include <stdio.h>

int main(void)
{
    // Declare variables
    int grade_a = 0, grade_b = 0, grade_c = 0, grade_d = 0, grade_f = 0;
    int counter, total_grades, grade;

    // Get the amount of grades to be entered
    printf("Number of grades to be entered: ");
    scanf("%d", &total_grades);

    for (counter = 1; counter <= total_grades; counter += 1)
    {
        printf("Enter grade %d: ", counter);
        scanf("%d", &grade);

        // Logical operator OR to make sure user stays in bounds
        if ( grade < 0 || grade > 100)
        {
            printf("Sorry, that is out of the grade range!\n");
            counter -= 1;
        }
        // Track grades using AND
        else if (grade >= 90 && grade <= 100)
            grade_a += 1;
        else if (grade >= 80 && grade <= 89)
            grade_b += 1;
        else if (grade >= 70 && grade <= 79)
            grade_c += 1;
        else if (grade >= 60 && grade <= 69)
            grade_d += 1;
        else if (grade >= 0 && grade <= 59)
            grade_f += 1;
    }

    // Display grade totals
    printf("Number of A students:\t%d\n", grade_a);
    printf("Number of B students:\t%d\n", grade_b);
    printf("Number of C students:\t%d\n", grade_c);
    printf("Number of D students:\t%d\n", grade_d);
    printf("Number of F students:\t%d\n", grade_f);
}
