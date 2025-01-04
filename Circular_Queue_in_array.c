#include <stdio.h>
#include <conio.h>
#define MAX 10

int choice, front = -1, rear = -1, queue[MAX], data;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void push()
{
    if (isFull())
    {
        printf("\n----------OVERFLOW----------\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX;

        printf("\nEnter the data : ");
        scanf("%d", &data);
        
        queue[rear] = data;
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void traverse()
{
    int i;
    if (isEmpty())
    {
        printf("\n----------UNDERFLOW----------\n");
    }
    else
    {
        printf("\n Front -> %d ", front);
        printf("\n queue -> ");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
        printf("\n Rear -> %d \n", rear);
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