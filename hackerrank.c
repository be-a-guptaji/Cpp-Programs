#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, digit[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char s[100];

    scanf("%s", &s);

    for (int i = 0; i < strlen(s); i++)
    {
        n = s[i] - '0';
        if (n >= 0 && n <= 9)
        {
            digit[n]++;
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", digit[i]);
    }

    return 0;
}