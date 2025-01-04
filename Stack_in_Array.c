#include <stdio.h>
#include <conio.h>
#define MAX 10

int choice, element, stack[MAX], top = 0;

void push()
{
    printf("\nEnter ELEMENT to PUSH in STACK : ");
    scanf("%d", &element);

    if (top == MAX - 1)
    {
        printf("\n----------OVERFLOW----------\n");
        return;
    }

    stack[top++] = element;
}

void pop()
{
    if (top == 0)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    printf("\nELEMENT is POPED from the STACK.\n");

    top--;
}

void traverse()
{
    if (top == 0)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    printf("\nELEMENTS in the STACK.\n");

    for (int i = top - 1, j = 1; i >= 0; i--)
    {
        printf("\nThe %d ELEMENT is : %d\n", j++, stack[i]);
    }
}

void main()
{

    printf("\nPRESS 1 to PUSH in STACK.\nPRESS 2 to POP from STACK.\nPRESS 3 to TRAVERSE yhe STACK.\nPRESS 4 to EXIT.\n");

    while (choice != 4)
    {
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            printf("\n----------DONE----------\n");
            break;
        }
        case 2:
        {
            pop();
            printf("\n----------DONE----------\n");
            break;
        }
        case 3:
        {
            traverse();
            printf("\n----------DONE----------\n");
            break;
        }
        case 4:
        {
            printf("\n----------EXITING----------\n");
            break;
        }

        default:
        {
            printf("\n----------PLEASE CHOOSE VALID CHOICE----------\n");
        }
        }
    }

    getch();
}