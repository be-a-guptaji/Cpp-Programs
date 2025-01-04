#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Global Variable to use everywhere in code....

int choice = 0, data, after_node;

// We make replica of this structure....

struct Node
{
    int info;
    struct Node *previous ,*next;
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

void insertion_at_the_beginning()
{
    printf("Enter DATA to insert at the BEGINNING OF THE NODE : ");
    scanf("%d", &data);

    traverser->info = data;

    if (head == NULL)
    {
        head = traverser;
        head->next = head;
        head->previous = head;
        return;
    }

    if (head != NULL)
    {
        head->previous = traverser;
    }

    traverser->next = head;
    temp = head;
    head = traverser;
    traverser = traverser->next;

    while (traverser->next != temp)
    {
        traverser = traverser->next;
    }

    traverser->next = head;
    head->previous = traverser;
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
        printf("\nNO ELEMENT FOUND IN LINK LIST\n");
        return;
    }

    if (head->info == after_node)
    {
        head->previous = traverser;
        traverser->next = head;
        temp = traverser;
        traverser = traverser->next;

        while (traverser->next != head)
        {
            traverser = traverser->next;
        }

        head = temp;
        traverser->next = head;
        head->previous = traverser;
        return;
    }

    found = head;

    while (found->info != after_node && found->next != head)
    {
        found = found->next;
    }

    if (found->info == after_node)
    {
        traverser->previous = found->previous;
        traverser->next = found;
        found->previous = traverser;
        traverser = traverser->previous;
        traverser->next = found->previous;
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
        head->next = head;
        head->previous = head;
        return;
    }

    found = head;

    while (found->next != head)
    {
        found = found->next;
    }

    found->next = traverser;
    traverser->previous = found;
    traverser->next = head;
    head->previous = traverser;
}

void deletion_at_the_beginning()
{
    printf("DELETION OF NODE FROM THE BEGINNING : \n");

    traverser = head;

    if (head->next == head && head->previous == head)
    {
        free(head);
        head = NULL;
        return;
    }

    if (traverser->next == traverser->previous)
    {
        head = traverser->next;
        head->next = head;
        head->previous = head;
        free(traverser);
        return;
    }

    found = head;
    temp = head->next;
    found = found->next;

    while (found->next != head)
    {
        found = found->next;
    }

    temp->previous = found;
    found->next = temp;
    free(head);
    head = temp;
}

void deletion_at_the_middle()
{

    printf("DELETION OF NODE FROM THE MIDDLE : \n");
    printf("Enter DATA which you want to DELETE the NODE : ");
    scanf("%d", &after_node);

    if (head->info == after_node && head->next == head && head->previous == head)
    {
        free(head);
        head = NULL;
        return;
    }

    traverser = head;
    temp = head;

    while (traverser->next != head)
    {
        traverser = traverser->next;
    }

    if (head->previous == traverser && head->info == after_node)
    {
        head = head->next;
        head->previous = traverser;
        traverser->next = head;
        free(temp);
        return;
    }

    found = head;

    while (found->info != after_node && found->next != head)
    {
        found = found->next;
    }

    if (found->next == head && found->info == after_node)
    {
        traverser = found->previous;
        traverser->next = head;
        head->previous = traverser;
        free(found);
        return;
    }

    if (found->info == after_node)
    {
        traverser = found->next;
        traverser->previous = found->previous;
        traverser = found->previous;
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

    traverser = head;

    if (head->next == head && head->previous == head)
    {
        free(head);
        head = NULL;
        printf("\n----------DONE----------\n");
        return;
    }

    found = head;

    while (found->next != head)
    {
        found = found->next;
    }

    traverser = found->previous;
    traverser->next = head;
    head->previous = traverser;
    free(found);
}

void traverse_the_list()
{
    int choose;
    printf("TRAVAERSING OF THE LINKED LIST :\n");

    while (choose != 4)
    {
        char ch;

        traverser = head;

        printf("\nPRESS 1 to TRAVERSE BACKWARD in Link List.\nPRESS 2 to TRAVERSE NORMALY in Link List.\nPRESS 3 to TRAVERSE MANUALLY in Link List.\nPRESS 4 to EXIT.\n");

        printf("\nEnter the CHOICE for traversing : ");
        scanf("%d", &choose);
        getchar();

        switch (choose)
        {
        case 1:
        {
            while (traverser->next != head)
            {
                printf("\nThe DATA in linked list is : %d\n", traverser->info);
                traverser = traverser->next;
            }

            printf("\nThe DATA in linked list is : %d\n", traverser->info);

            break;
        }
        case 2:
        {
            while (traverser->previous != head)
            {
                traverser = traverser->previous;
                printf("\nThe DATA in linked list is : %d\n", traverser->info);
            }

            traverser = traverser->previous;

            printf("\nThe DATA in linked list is : %d\n", traverser->info);
            break;
        }
        case 3:
        {
            while (ch != 'n' && ch != 'N')
            {
                printf("\nPRESS Y to CONTINUE TRAVERSING.\nPRESS N to EXIT.\n");
                printf("Enter your choice : ");
                scanf("%c", &ch);
                getchar();

                if (ch != 'n' && ch != 'N')
                {
                    printf("\nPRESS F to TRAVERSE FORWARD.\nPRESS B to TRAVERSE BACKWARD.\n");
                    printf("Enter your choice : ");
                    scanf("%c", &ch);
                    getchar();

                    if (ch != 'b' && ch != 'B')
                    {
                        if (traverser == head)
                        {
                            printf("\nYou are at the STARTING of the LINKED LIST\n");
                        }

                        printf("\nThe DATA in linked list is : %d\n", traverser->info);

                        traverser = traverser->next;
                    }
                    else
                    {
                        traverser = traverser->previous;

                        if (traverser->next == head)
                        {
                            printf("\nYou are at the STARTING of the LINKED LIST\n");
                        }

                        printf("\nThe DATA in linked list is : %d\n", traverser->info);
                    }
                }
                else
                {
                    printf("\nYou choose N.\n");
                    printf("\n----------EXITING THE MANUAL TRAVERSING SECTION----------\n");
                    break;
                }
            }

            break;
        }
        case 4:
        {
            printf("\n----------EXITING THE TRAVERSING SECTION----------\n");
            break;
        }
        default:
        {
            printf("\n----------PLEASE CHOOSE VALID CHOICE----------\n");
        }
        }
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
                traverse_the_list();
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