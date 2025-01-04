#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Circular_Queue_in_Linked_List
{
    int info;
    struct Circular_Queue_in_Linked_List *next;
} Queue;

int choice = 0, data;
Queue *front, *rear, *temp;

void push()
{
    temp = (Queue *)malloc(sizeof(Queue));

    if (temp == NULL)
    {
        printf("\n----------OVERFLOW----------\n ");
        return;
    }

    printf("\nEnter the data : ");
    scanf("%d", &data);

    temp->info = data;

    if (front == NULL)
    {
        front = temp;
        front->next = front;
        rear = front;
        return;
    }

    rear->next = temp;
    rear = temp;
    rear->next = front;
}

void pop()
{
    if (front == NULL)
    {
        printf("\n----------UNDERFLOW----------\n ");
        return;
    }

    printf("\nThe element poped is : %d\n", front->info);

    if (front == rear)
    {
        free(front);
        front = NULL;
        return;
    }

    temp = front;
    front = front->next;
    rear->next = front;
    free(temp);
}

void traverse()
{
    if (front == NULL)
    {
        printf("\n----------UNDERFLOW----------\n ");
        return;
    }

    temp = front->next;

    printf("\nThe DATA in linked list is : %d\n", front->info);

    while (temp != front)
    {
        printf("\nThe DATA in linked list is : %d\n", temp->info);
        temp = temp->next;
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
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            traverse();
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

        printf("\n----------DONE----------\n");
    }

    getch();
}