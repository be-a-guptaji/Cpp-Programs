#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    while (1)
    {
        printf("\nMemory Allocated\n");
        int *ptr = (int *)malloc(100000000);
    }

    getch();
}