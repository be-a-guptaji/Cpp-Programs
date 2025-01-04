#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *operation;
    int i, num[10], result = 0;
    float div;

    operation = argv[1];

    for (i = 2; i < argc; i++)
    {
        num[i] = atoi(argv[i]);
    }

    if (strcmp(operation, "add") == 0)
    {
        for (i = 2; i < argc; i++)
        {
            result += num[i];
        }
        printf("The addition is %d. \n", result);
    }
    if (strcmp(operation, "sub") == 0)
    {
        for (i = 2; i < argc - 1; i++)
        {
            num[2] = num[2] - num[i + 1];
            result = num[2];
        }
        printf("The subtraction is %d. \n", result);
    }
    if (strcmp(operation, "mul") == 0)
    {
        for (i = 2; i < argc - 1; i++)
        {
            num[2] = num[2] * num[i + 1];
            result = num[2];
        }
        printf("The multiplication is %d. \n", result);
    }
    if (strcmp(operation, "div") == 0)
    {
        for (i = 2; i < argc - 1; i++)
        {
            div = num[2] / num[i + 1];
        }
        printf("The division is %f. \n", div);
    }

    return 0;
}