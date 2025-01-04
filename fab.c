#include <stdio.h>
#include <conio.h>

int fabrec(int z);

int re = 1, loop = 1;

int fabloop(int z)
{
    register int a = 0, b = 1;

    for (int i = 1; i < z; i++)
    {
        loop++;
        b = a + b;
        a = b - a;
    }

    return a;
}

void main()
{
    int a;

    printf("Enter number upto you want fabonachi series.\n");
    scanf("%d", &a);

    printf("The fabonachi series upto %d by using loop is \t %d.\n", a, fabloop(a));
    printf("The fabonachi series upto %d by using recursion is \t %d.\n", a, fabrec(a));

    printf("The fabonachi series by using loop runs %d times.\n", loop);
    printf("The fabonachi series by using recursion runs %d times.\n", re);

    getchar();
}

int fabrec(int z)
{
    re++;
    if (z == 1 || z == 2)
    {
        return (z - 1);
    }
    else
    {
        return (fabrec(z - 1) + fabrec(z - 2));
    }
}