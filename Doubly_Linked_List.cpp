// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// // Global Variable to use everywhere in code....

// int choice = 0, data, after_node;

// // We make replica of this structure....

// struct Node
// {
//     int info;
//     struct Node *previous, *next;
// };

// // This stores the first address of the structure....

// struct Node *head, *traverser, *found;

// // Functions for Implementation....

// int check_memory(int choice)
// {
//     if (choice < 4)
//     {
//         traverser = (struct Node *)malloc(sizeof(struct Node));

//         if (traverser == NULL)
//         {
//             printf("\n----------OVERFLOW----------\n");
//             return 0;
//         }

//         return 1;
//     }
//     else
//     {
//         if (head == NULL)
//         {
//             printf("\n----------UNDERFLOW----------\n");
//             return 0;
//         }
//         return 1;
//     }
// }

// void mover()
// {
//     while (found->next != NULL)
//     {
//         if (choice == 2 || choice == 5)
//         {
//             if (found->info == after_node && found->next != NULL)
//             {
//                 return;
//             }
//         }
//         found = found->next;
//     }
// }

// int node_remover()
// {
//     free(head);
//     head = NULL;
//     return 1;
// }

// int last_node_remover()
// {
//     if (traverser->next == traverser->previous)
//     {
//         return node_remover();
//     }

//     if (head->next == head->previous && head->info == after_node)
//     {
//         return node_remover();
//     }

//     return 0;
// }

// void insertion_at_the_beginning()
// {
//     printf("Enter DATA to insert at the BEGINNING OF THE NODE : ");
//     scanf("%d", &data);

//     traverser->info = data;

//     if (head != NULL)
//     {
//         head->previous = traverser;
//     }

//     traverser->next = head;
//     head = traverser;
//     head->previous = NULL;
// }

// void insertion_at_the_middle()
// {
//     printf("Enter DATA to insert at the MIDDLE OF THE NODE : ");
//     scanf("%d", &data);

//     printf("Enter DATA after which you want to INSERT the NODE : ");
//     scanf("%d", &after_node);

//     traverser->info = data;

//     if (head == NULL)
//     {
//         printf("\n----------UNDERFLOW----------\n");
//         return;
//     }

//     if (head->info == after_node)
//     {
//         head->previous = traverser;
//         traverser->next = head;
//         head = traverser;
//         head->previous = NULL;
//         return;
//     }

//     found = head;
//     mover();

//     if (found->info == after_node)
//     {
//         traverser->previous = found->previous;
//         traverser->next = found;
//         found->previous = traverser;
//         traverser = traverser->previous;
//         traverser->next = found->previous;
//     }
//     else
//     {
//         printf("The Element %d is not in Linked List.\n", after_node);
//     }
// }

// void insertion_at_the_end()
// {
//     printf("Enter DATA to insert at the END OF THE NODE : ");
//     scanf("%d", &data);

//     traverser->info = data;

//     if (head == NULL)
//     {
//         traverser->next = head;
//         head = traverser;
//         found = traverser;
//         head->previous = NULL;
//         return;
//     }

//     found = head;
//     mover();

//     found->next = traverser;
//     traverser->previous = found;
//     traverser->next = NULL;
// }

// void deletion_at_the_beginning()
// {
//     printf("DELETION OF NODE FROM THE BEGINNING : \n");

//     traverser = head;

//     if (last_node_remover() == 1)
//     {
//         return;
//     }

//     found = head;
//     found = found->next;

//     if (found->next == traverser->previous)
//     {
//         head = traverser->next;
//         head->previous = NULL;
//         free(traverser);
//         return;
//     }

//     head = traverser->next;
//     head->previous = NULL;
//     free(traverser);
// }

// void deletion_at_the_middle()
// {
//     printf("DELETION OF NODE FROM THE MIDDLE : \n");
//     printf("Enter DATA which you want to DELETE the NODE : ");
//     scanf("%d", &after_node);

//     if (last_node_remover() == 1)
//     {
//         return;
//     }

//     traverser = head;

//     if (head->previous == NULL && head->info == after_node)
//     {
//         head = head->next;
//         head->previous = NULL;
//         free(traverser);
//         return;
//     }

//     found = head;
//     mover();

//     if (found->next == NULL && found->info == after_node)
//     {
//         traverser = found->previous;
//         traverser->next = NULL;
//         free(found);
//         return;
//     }

//     if (found->info == after_node)
//     {
//         traverser = found->next;
//         traverser->previous = found->previous;
//         traverser = found->previous;
//         traverser->next = found->next;
//         free(found);
//     }
//     else
//     {
//         printf("The Element %d is not in Linked List.\n", after_node);
//     }
// }

// void deletion_at_the_end()
// {
//     printf("DELETION OF NODE FROM THE END : \n");

//     traverser = head;

//     if (last_node_remover() == 1)
//     {
//         return;
//     }

//     found = head;
//     mover();

//     traverser = found->previous;
//     traverser->next = NULL;
//     free(found);
// }

// void traverse_the_list()
// {
//     int chooses = 0;
//     char ch;

//     printf("TRAVAERSING OF THE LINKED LIST :\n");

//     while (chooses != 4)
//     {
//         found = head;

//         printf("\nPRESS 1 to TRAVERSE BACKWARD in Link List.\nPRESS 2 to TRAVERSE NORMALY in Link List.\nPRESS 3 to TRAVERSE MANUALY in Link List.\nPRESS 4 to EXIT.\n");

//         printf("\nEnter the CHOICE for traversing : ");
//         scanf("%d", &chooses);
//         getchar();

//         switch (chooses)
//         {
//         case 1:
//         {
//             while (found->next != NULL)
//             {
//                 printf("\nThe DATA in linked list is : %d\n", found->info);
//                 found = found->next;
//             }

//             printf("\nThe DATA in linked list is : %d\n", found->info);
//             break;
//         }
//         case 2:
//         {
//             while (found->next != NULL)
//             {
//                 found = found->next;
//             }

//             while (found->previous != NULL)
//             {
//                 printf("\nThe DATA in linked list is : %d\n", found->info);
//                 found = found->previous;
//             }

//             printf("\nThe DATA in linked list is : %d\n", found->info);
//             break;
//         }
//         case 3:
//         {
//             while (ch != 'n' && ch != 'N')
//             {
//                 printf("\nPRESS Y to CONTINUE TRAVERSING.\nPRESS N to EXIT.\n");
//                 printf("Enter your choice : ");
//                 scanf("%c", &ch);
//                 getchar();

//                 if (ch != 'n' && ch != 'N')
//                 {
//                     printf("\nPRESS F to TRAVERSE FORWARD.\nPRESS B to TRAVERSE BACKWARD.\n");
//                     printf("Enter your choice : ");
//                     scanf("%c", &ch);
//                     getchar();

//                     if (ch != 'b' && ch != 'B')
//                     {
//                         if (found == NULL)
//                         {
//                             printf("\nThis is END OF LIST\n");
//                             break;
//                         }

//                         printf("\nThe DATA in linked list is : %d\n", found->info);
//                         found = found->next;
//                     }
//                     else
//                     {
//                         if (found->previous == NULL)
//                         {
//                             printf("\nThis is END OF LIST\n");
//                             break;
//                         }

//                         printf("\nThe DATA in linked list is : %d\n", found->info);
//                         found = found->previous;
//                     }
//                 }
//                 else
//                 {
//                     printf("\nYou choose N.\n");
//                     printf("\n----------EXITING THE MANUAL TRAVERSING SECTION----------\n");
//                     break;
//                 }
//             }

//             break;
//         }
//         case 4:
//         {
//             printf("\n----------EXITING THE TRAVERSING SECTION----------\n");
//             break;
//         }
//         default:
//         {
//             printf("\n----------PLEASE CHOOSE VALID CHOICE----------\n");
//         }
//         }
//     }
// }

// // Driver Function
// int main()
// {
//     char traverse;

//     printf("PRESS 1 for INSERTING NODE AT THE BEGINNING.\nPRESS 2 for INSERTING NODE AT THE MIDDLE.\nPRESS 3 for INSERTING AT THE END.\nPRESS 4 for DELETION OF NODE AT THE BEGINNING.\nPRESS 5 for DELETION OF NODE AT THE MIDDLE.\nPRESS 6 for DELETION OF NODE AT THE END.\nPRESS 7 for TO TRAVERSR THE LINKED LIST.\nPRESS 8 for EXIT.\n");

//     while (choice != 8)
//     {
//         printf("\nEnter the CHOICE : ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 insertion_at_the_beginning();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 2:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 insertion_at_the_middle();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 3:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 insertion_at_the_end();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 4:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 deletion_at_the_beginning();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 5:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 deletion_at_the_middle();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 6:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 deletion_at_the_end();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 7:
//         {
//             if (check_memory(choice) == 1)
//             {
//                 traverse_the_list();
//             }
//             printf("\n----------DONE----------\n");
//             break;
//         }
//         case 8:
//         {
//             printf("\n----------EXITING----------\n");
//             break;
//         }
//         default:
//         {
//             printf("\n----------PLEASE CHOOSE VALID CHOICE----------\n");
//         }
//         }
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node
{
    int info;
    Node *previous;
    Node *next;
};

// Head of the doubly linked list
Node *head = nullptr;

// Function to check memory allocation
bool checkMemory()
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        cout << "\n----------OVERFLOW----------\n";
        return false;
    }
    delete newNode; // Free the memory immediately
    return true;
}

// Function to insert node at the beginning
void insertionAtTheBeginning()
{
    int data;
    cout << "Enter DATA to insert at the BEGINNING OF THE NODE: ";
    cin >> data;

    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = head;
    newNode->previous = nullptr;

    if (head != nullptr)
    {
        head->previous = newNode;
    }

    head = newNode;
}

// Function to insert node at the middle
void insertionAtTheMiddle()
{
    int data, afterNode;
    cout << "Enter DATA to insert at the MIDDLE OF THE NODE: ";
    cin >> data;

    cout << "Enter DATA after which you want to INSERT the NODE: ";
    cin >> afterNode;

    Node *newNode = new Node;
    newNode->info = data;

    if (head == nullptr)
    {
        cout << "\n----------UNDERFLOW----------\n";
        return;
    }

    Node *current = head;
    while (current != nullptr && current->info != afterNode)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "The Element " << afterNode << " is not in Linked List.\n";
        return;
    }

    newNode->next = current->next;
    newNode->previous = current;

    if (current->next != nullptr)
    {
        current->next->previous = newNode;
    }

    current->next = newNode;
}

// Function to insert node at the end
void insertionAtTheEnd()
{
    int data;
    cout << "Enter DATA to insert at the END OF THE NODE: ";
    cin >> data;

    Node *newNode = new Node;
    newNode->info = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        newNode->previous = nullptr;
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;
}

// Function to delete node at the beginning
void deletionAtTheBeginning()
{
    if (head == nullptr)
    {
        cout << "\n----------UNDERFLOW----------\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->previous = nullptr;
    }

    delete temp;
}

// Function to delete node at the middle
void deletionAtTheMiddle()
{
    int afterNode;
    cout << "Enter DATA which you want to DELETE from the MIDDLE: ";
    cin >> afterNode;

    if (head == nullptr)
    {
        cout << "\n----------UNDERFLOW----------\n";
        return;
    }

    Node *current = head;
    while (current != nullptr && current->info != afterNode)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "The Element " << afterNode << " is not in Linked List.\n";
        return;
    }

    if (current->previous != nullptr)
    {
        current->previous->next = current->next;
    }

    if (current->next != nullptr)
    {
        current->next->previous = current->previous;
    }

    delete current;
}

// Function to delete node at the end
void deletionAtTheEnd()
{
    if (head == nullptr)
    {
        cout << "\n----------UNDERFLOW----------\n";
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    if (current->previous != nullptr)
    {
        current->previous->next = nullptr;
    }

    if (current == head)
    {
        head = nullptr;
    }

    delete current;
}

// Function to traverse and print the list
void traverseTheList()
{
    Node *current = head;
    cout << "Traversing the list:\n";
    while (current != nullptr)
    {
        cout << current->info << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

// Function to display the menu and handle user choices
void displayMenu()
{
    int choice = 0;

    while (choice != 8)
    {
        cout << "\nPress 1 to Insert Node at the Beginning.\n";
        cout << "Press 2 to Insert Node at the Middle.\n";
        cout << "Press 3 to Insert Node at the End.\n";
        cout << "Press 4 to Delete Node at the Beginning.\n";
        cout << "Press 5 to Delete Node at the Middle.\n";
        cout << "Press 6 to Delete Node at the End.\n";
        cout << "Press 7 to Traverse the Linked List.\n";
        cout << "Press 8 to Exit.\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (checkMemory())
                insertionAtTheBeginning();
            break;
        case 2:
            if (checkMemory())
                insertionAtTheMiddle();
            break;
        case 3:
            if (checkMemory())
                insertionAtTheEnd();
            break;
        case 4:
            deletionAtTheBeginning();
            break;
        case 5:
            deletionAtTheMiddle();
            break;
        case 6:
            deletionAtTheEnd();
            break;
        case 7:
            traverseTheList();
            break;
        case 8:
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nPlease choose a valid option.\n";
            break;
        }
    }
}

// Main function
int main()
{
    displayMenu();
    return 0;
}
