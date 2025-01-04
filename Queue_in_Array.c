#include <stdio.h>
#include <conio.h>
#define MAX 10

int choice, front = -1, rear = -1, queue[MAX], data;

void push()
{
    if (rear + 1 == MAX)
    {
        printf("\n----------OVERFLOW----------\n");
        return;
    }

    printf("\nEnter the data to queue : ");
    scanf("%d", &data);

    queue[++rear] = data;
    front = 0;
}

void pop()
{
    if (rear == -1)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    printf("\nElement is poped\n");

    for (int i = 0; i < rear; i++)
    {
        queue[i] = queue[i + 1];
    }

    rear--;
}

void traverse()
{
    if (rear == -1)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    printf("\nThe elements in the queue are : \n");

    for (int i = 0; i <= rear; i++)
    {
        printf("\nThe element is : %d\n", queue[i]);
    }
}

void main()
{
    printf("\nPRESS 1 for PUSHING element in QUEUE.\nPRESS 2 for POPING a element in QUEUE.\nPRESS 3 for TRAVERSING the QUEUE.\nPRESS 4 for EXIT.\n");

    while (choice != 4)
    {
        printf("\nEnter your choice : ");
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