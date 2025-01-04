#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int choice, element;

typedef struct Node
{
    int info;
    struct Node *next;
} node;

node *head, *traverser;

void push()
{
    traverser = (node *)malloc(sizeof(node));

    if (traverser == NULL)
    {
        printf("\n----------OVERFLOW----------\n");
        return;
    }

    printf("\nEnter ELEMENT to PUSH in STACK : ");
    scanf("%d", &element);

    traverser->info = element;
    traverser->next = head;
    head = traverser;
}

void pop()
{
    printf("\nELEMENT is POPED from the STACK.\n");

    traverser = head;

    if (head == NULL)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    head = traverser->next;
    free(traverser);
}

void traverse()
{
    printf("\nELEMENTS in the STACK.\n");

    if (head == NULL)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    printf("\nThe ELEMENT is : %d\n", head->info);

    traverser = head;

    while (traverser->next != NULL)
    {
        traverser = traverser->next;
        printf("\nThe ELEMENT is : %d\n", traverser->info);
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