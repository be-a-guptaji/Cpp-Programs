#include <stdio.h>
#include <conio.h>

void main()
{
    int a, b, i;

    printf("Enter two number to find HCF of them.\n");

    printf("Enter First number.\n");
    scanf("%d", &a);

    printf("Enter second number.\n");
    scanf("%d", &b);

    for (i = 1; i <= a * b; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            break;
        }
    }

    printf("The HCF of %d and %d is %d.\n", a, b, i);

    getch();
}
