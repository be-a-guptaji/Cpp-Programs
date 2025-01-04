#include <stdio.h>
#include <conio.h>

void main()
{
    int a, b, k;

start:

    printf("To add number \t\tPRESS 1.\nTo subtract number \tPRESS 2.\nTo multiplye number \tPRESS 3.\nTo division number \tPRESS 4.\n");
    scanf("%d", &k);

    printf("Enter Number 1.\t\t\a");
    scanf("%d", &a);

    printf("Enter Number 2.\t\t\a");
    scanf("%d", &b);

    if (k > 0 && k < 4)
    {
        switch (k)
        {
        case 1:
        {
            printf("The sum of %d and %d is %d.\n", a, b, a + b);
            break;
        }
        case 2:
        {
            printf("The subtraction of %d and %d is %d.\n", a, b, a - b);
            break;
        }
        case 3:
        {
            printf("The multiplication of %d and %d is %d.\n", a, b, a * b);
            break;
        }
        default:
        {
            printf("The division of %d and %d is %f.\n", a, b, (float)a / b);
            break;
        }
        }
    }
    else if (k == 0)
    {
        printf("You choose 0 which is not in option so the reminder of %d and %d is %d.\n", a, b, a % b);
    }
    else
    {
        printf("You choose %d choose again.\n\n\n\n", k);
        goto start;
    }
    getch();
}