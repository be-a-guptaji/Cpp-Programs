#include <stdio.h>
#include <conio.h>

void main()
{
    int a, b, i;

    printf("Enter two number to find LCM of them.\n");

    printf("Enter First number.\n");
    scanf("%d", &a);

    printf("Enter second number.\n");
    scanf("%d", &b);

    for (i = 2; i < a + 2; i++)
    {
        if (i == a + 1 || i == b + 1)
        {
            i = 1;
            break;
        }
        if (a % i == 0 && b % i == 0)
        {
            break;
        }
    }
    printf("The LCM of %d and %d is %d.\n", a, b, i);
    getch();
}