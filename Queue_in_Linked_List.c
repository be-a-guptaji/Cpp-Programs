#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int choice = 0, data, after_node;

struct Node
{
    int info;
    struct Node *next;
};

struct Node *front, *rear, *found, *temp;

void push()
{
    printf("Enter DATA to insert at the END OF THE NODE : ");
    scanf("%d", &data);

    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("\n----------OVERFLOW----------\n");
        return;
    }

    temp->info = data;
    temp->next = NULL;

    if (front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void pop()
{
    printf("Element is POPED : \n");

    if (front == NULL)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    if (front == rear)
    {
        free(front);
        rear = NULL;
        front = NULL;
        return;
    }

    temp = front;
    front = front->next;
    free(temp);
}

void traverse()
{
    printf("TRAVAERSING OF THE QUEUE :\n");
    

    if (front == NULL)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }
    
    temp = front;

    while (temp->next != NULL)
    {
        printf("\nThe DATA in linked list is : %d\n", temp->info);
        temp = temp->next;
    }

    printf("\nThe DATA in linked list is : %d\n", temp->info);
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