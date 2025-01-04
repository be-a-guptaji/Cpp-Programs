#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Global Variable to use everywhere in code....
int choice = 0, data, after_node;

// We make replica of this structure....

struct Node
{
    int info;
    struct Node *next;
};

// This stores the first address of the structure....

struct Node *head, *traverser, *found, *temp;

// Functions for Implementation....

int check_memory(int choice)
{
    if (choice < 4)
    {
        traverser = (struct Node *)malloc(sizeof(struct Node));

        if (traverser == NULL)
        {
            printf("\n----------OVERFLOW----------\n");
            return 0;
        }

        return 1;
    }
    else
    {
        if (head == NULL)
        {
            printf("\n----------UNDERFLOW----------\n");
            return 0;
        }
        return 1;
    }
}

void traversing_in_reverse(struct Node *traverser)
{
    if (traverser->next == head)
    {
        printf("\nThe DATA in linked list is : %d\n", traverser->info);
        return;
    }
    traversing_in_reverse(traverser->next);
    printf("\nThe DATA in linked list is : %d\n", traverser->info);
}

void insertion_at_the_beginning()
{
    printf("Enter DATA to insert at the BEGINNING OF THE NODE : ");
    scanf("%d", &data);

    traverser->info = data;

    if (head == NULL)
    {
        traverser->next = traverser;
        head = traverser;
    }
    else
    {
        temp = head;
        found = traverser;
        found->next = head;
        head = found;
        found = found->next;

        while (found->next != temp)
        {
            found = found->next;
        }

        found->next = head;
    }
}

void insertion_at_the_middle()
{
    printf("Enter DATA to insert at the MIDDLE OF THE NODE : ");
    scanf("%d", &data);

    printf("Enter DATA after which you want to INSERT the NODE : ");
    scanf("%d", &after_node);

    traverser->info = data;

    if (head == NULL)
    {
        printf("\n----------UNDERFLOW----------\n");
        return;
    }

    if (head->info == after_node)
    {
        temp = head;
        traverser->next = head;
        found = traverser;
        head = found;
        found = found->next;

        while (found->next != temp)
        {
            found = found->next;
        }

        found->next = head;
        return;
    }

    found = head;

    while (found->info != after_node && found->next != head)
    {
        temp = found;
        found = found->next;
    }

    if (found->info == after_node && found->next == head)
    {
        traverser->next = found;
        temp->next = traverser;
        return;
    }

    if (found->info == after_node)
    {
        traverser->next = found;
        temp->next = traverser;
    }
    else
    {
        printf("The Element %d is not in Linked List.\n", after_node);
    }
}

void insertion_at_the_end()
{
    printf("Enter DATA to insert at the END OF THE NODE : ");
    scanf("%d", &data);

    traverser->info = data;

    if (head == NULL)
    {
        head = traverser;
        traverser->next = head;
        return;
    }

    found = head;

    while (found->next != head)
    {
        found = found->next;
    }

    found->next = traverser;
    traverser->next = head;
}

void deletion_at_the_beginning()
{
    printf("DELETION OF NODE FROM THE BEGINNING : \n");

    found = head;

    if (found->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head->next;
    traverser = head;

    while (found->next != head)
    {
        found = found->next;
    }

    found->next = temp;
    head = temp;
    free(traverser);
}

void deletion_at_the_middle()
{
    printf("DELETION OF NODE FROM THE MIDDLE : \n");
    printf("Enter DATA after which you want to DELETE the NODE : ");
    scanf("%d", &after_node);

    if (head->info == after_node && head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    found = head;

    if (head->info == after_node)
    {
        temp = head;
        head = head->next;

        while (found->next != temp)
        {
            found = found->next;
        }

        found->next = head;

        free(temp);
        return;
    }

    while (found->info != after_node && found->next != head)
    {
        traverser = found;
        found = found->next;
    }

    if (found->info == after_node)
    {
        traverser->next = found->next;
        free(found);
    }
    else
    {
        printf("The Element %d is not in Linked List.\n", after_node);
    }
}

void deletion_at_the_end()
{
    printf("DELETION OF NODE FROM THE END : \n");

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    found = head;

    while (found->next != head)
    {
        traverser = found;
        found = found->next;
    }

    traverser->next = head;
    free(found);
}

void traverse()
{
    int traversing;
    printf("TRAVAERSING OF THE LINKED LIST :\n");
    printf("\nPRESS 1 for NORMAL TRAVERSING.\nPRESS 2 for REVERSE TRAVERSING.\n");
    printf("\nEnter your Methord.\n");
    scanf("%d", &traversing);

    traverser = head;

    if (traversing == 1)
    {
        while (traverser->next != head)
        {
            printf("\nThe DATA in linked list is : %d\n", traverser->info);
            traverser = traverser->next;
        }
        printf("\nThe DATA in linked list is : %d\n", traverser->info);
    }
    else
    {
        traversing_in_reverse(head);
    }
}

// Driver Function
int main()
{

    printf("PRESS 1 for INSERTING NODE FROM THE BEGINNING.\nPRESS 2 for INSERTING NODE FROM THE MIDDLE.\nPRESS 3 for INSERTING FROM THE END.\nPRESS 4 for DELETION OF NODE FROM THE BEGINNING.\nPRESS 5 for DELETION OF NODE FROM THE MIDDLE.\nPRESS 6 for DELETION OF NODE FROM THE END.\nPRESS 7 for TO TRAVERSR THE LINKED LIST.\nPRESS 8 for EXIT.\n");

    while (choice != 8)
    {
        printf("\nEnter the CHOICE : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (check_memory(choice) == 1)
            {
                insertion_at_the_beginning();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 2:
        {

            if (check_memory(choice) == 1)
            {
                insertion_at_the_middle();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 3:
        {
            if (check_memory(choice) == 1)
            {
                insertion_at_the_end();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 4:
        {
            if (check_memory(choice) == 1)
            {
                deletion_at_the_beginning();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 5:
        {
            if (check_memory(choice) == 1)
            {
                deletion_at_the_middle();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 6:
        {
            if (check_memory(choice) == 1)
            {
                deletion_at_the_end();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 7:
        {
            if (check_memory(choice) == 1)
            {
                traverse();
            }
            printf("\n----------DONE----------\n");
            break;
        }
        case 8:
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

    return 0;
}