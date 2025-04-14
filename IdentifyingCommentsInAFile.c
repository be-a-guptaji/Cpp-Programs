#include <stdio.h>
#include <string.h>

// Function to check for comments
int checkForComments(char line[], int *isCommentStarted, int lineNumber)
{
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '/' && line[i + 1] == '/' && *isCommentStarted == 0)
        {
            *isCommentStarted = 1;
            printf("\nSingle line comment at line number %d: \n", lineNumber);
        }
        if (line[i] == '/' && line[i + 1] == '*' && *isCommentStarted == 0)
        {
            *isCommentStarted = 2;
            printf("\nMulti line comment started at line number %d: \n", lineNumber);
        }
        if (line[i] == '*' && line[i + 1] == '/' && *isCommentStarted == 2)
        {
            printf("*/\n");
            printf("Multi line comment ended at line number %d: \n", lineNumber);
            *isCommentStarted = 0;
        }
        if (*isCommentStarted != 0)
        {
            printf("%c", line[i]);
        }
    }
    if (*isCommentStarted == 1)
    {
        *isCommentStarted = 0;
    }
}

int main()
{
    FILE *file;
    char line[256];
    int isCommentStarted = 0, lineNumber = 1;

    // Open File in read mode
    file = fopen("comments.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    // Read each line and print it
    while (fgets(line, sizeof(line), file))
    {
        checkForComments(line, &isCommentStarted, lineNumber);
        lineNumber++;
    }

    // Close the file
    fclose(file);
    return 0;
}