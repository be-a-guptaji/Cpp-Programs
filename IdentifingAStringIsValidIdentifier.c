#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid C identifier
int isValidIdentifier(const char *str)
{
    // Check if it's empty
    if (str == NULL || str[0] == '\0')
        return 0;

    // First character must be a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    // Rest can be letters, digits, or underscore
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]))
            return 0;
    }

    // If it passed all checks, it's a valid identifier
    return 1;
}

int main()
{
    char identifier[100];

    // Take input
    printf("Enter an identifier: ");
    gets(identifier);

    if (isValidIdentifier(identifier))
    {
        printf("'%s' is a valid identifier in C.\n", identifier);
    }
    else
    {
        printf("'%s' is NOT a valid identifier in C.\n", identifier);
    }

    return 0;
}
