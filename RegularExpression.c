#include <stdio.h>
#include <string.h>

int currentChar(int i, char str[]);
int check011(int i, char str[]);

int currentChar(int i, char str[])
{
    if (str[i] == '\0')
    {
        return 0;
    }
    else if (str[i] == '1')
    {
        return currentChar(i + 1, str);
    }
    else if (str[i] == '0')
    {
        return check011(i, str);
    }
    else
    {
        return 0;
    }
}

int check011(int i, char str[])
{
    if (str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '1' && str[i + 3] == '\0')
    {
        return 1;
    }
    else
    {
        return currentChar(i + 1, str);
    }
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    gets(str);

    if (currentChar(0, str))
    {
        printf("The string matches the regular expression (1+0)*011.\n");
    }
    else
    {
        printf("The string does not match the regular expression (1+0)*011.\n");
    }

    return 0;
}
