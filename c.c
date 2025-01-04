#include <stdio.h>
#include <stdlib.h>

void traverse();

struct l
{
    int data;
    struct l *next;
};
struct l *head;

void main()
{
    int choice = 1, info;

    while (choice != 0)
    {
        printf("Do you want to insert data in Linked list?\nPRESS 1 for YES \nPRESS 0 for NO\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            struct l *ptr = (struct l *)malloc(sizeof(struct l));
            if (ptr == NULL)
            {
                printf("\nSTACK OVERFLOW\n");
            }
            else
            {
                printf("Enter the information.\n");
                scanf("%d", &info);
                ptr->data = info;
                ptr->next = head;
                head = ptr;
            }
        }
        else if (choice == 0)
        {
            continue;
        }
        else
        {
            printf("Enter Valid option.\n");
            continue;
        }
    }
    traverse();
}

void traverse()
{
    struct l *ptr;
    ptr = head;

    printf("The Linked List is :\n");
    if (ptr == NULL)
    {
        printf("Empty list..\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}