#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char *replaceword(const char *string, const char *oldword, const char *newword)
{
    char *resultstring;
    int i, newwordlength = strlen(newword), oldwordlength = strlen(oldword), count = 0;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (strstr(&string[i], oldword) == &string[i])
        {
            count++;
            i += oldwordlength - 1;
        }
    }

    resultstring = (char *)malloc((i + count * (newwordlength - oldwordlength) + 1) * (sizeof(char)));

    i = 0;

    while (*string)
    {
        if (strstr(string, oldword) == string)
        {
            strcpy(&resultstring[i], newword);
            i += newwordlength;
            string += oldwordlength;
        }
        else
        {
            resultstring[i] = *string;
            i += 1;
            string += 1;
        }
    }

    resultstring[i] = '\0';

    return resultstring;
}

void main()
{
    char name[20], item[20], outlet[20], string[200];
    FILE *bill = NULL, *genrated = NULL;
    bill = fopen("bill.txt", "r");
    genrated = fopen("genrated.txt", "w+");

    fgets(string, 200, bill);
    printf("\nThe old format was : \n\n%s\n\n", string);

    printf("Enter Payer's name :\t");
    gets(name);
    printf("Enter item purchsed :\t");
    gets(item);
    printf("Enter outlet name :\t");
    gets(outlet);

    char *genratedbill;

    genratedbill = replaceword(string, "{{name}}", name);
    genratedbill = replaceword(genratedbill, "{{item}}", item);
    genratedbill = replaceword(genratedbill, "{{outlet}}", outlet);

    printf("\nThe actual bill genrated is : \n\n%s\n\n", genratedbill);
    fprintf(genrated, "%s", genratedbill);

    fclose(bill);
    fclose(genrated);

    getch();
}