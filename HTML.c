#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char a[100];
    int b = 0, c = 1;

    printf("Enter HTML parser.\n");
    gets(a);

    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '<')
        {
            c = 1;
            continue;
        }
        else if (a[i] == '>')
        {
            c = 0;
            continue;
        }
        if (c == 0)
        {
            a[b] = a[i];
            b++;
        }
    }

    a[b] = '\0';

    while (a[0] == ' ')
    {
        for (int i = 0; i < strlen(a); i++)
        {
            a[i] = a[i + 1];
        }
    }

    while (a[strlen(a) - 1] == ' ')
    {
        a[strlen(a) - 1] = '\0';
    }

    printf("The HTML parser is :\n");
    puts(a);

    getch();
}