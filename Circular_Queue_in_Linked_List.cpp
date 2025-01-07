// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// typedef struct Circular_Queue_in_Linked_List
// {
//     int info;
//     struct Circular_Queue_in_Linked_List *next;
// } Queue;

// int choice = 0, data;
// Queue *front, *rear, *temp;

// void push()
// {
//     temp = (Queue *)malloc(sizeof(Queue));

//     if (temp == NULL)
//     {
//         printf("\n----------OVERFLOW----------\n ");
//         return;
//     }

//     printf("\nEnter the data : ");
//     scanf("%d", &data);

//     temp->info = data;

//     if (front == NULL)
//     {
//         front = temp;
//         front->next = front;
//         rear = front;
//         return;
//     }

//     rear->next = temp;
//     rear = temp;
//     rear->next = front;
// }

// void pop()
// {
//     if (front == NULL)
//     {
//         printf("\n----------UNDERFLOW----------\n ");
//         return;
//     }

//     printf("\nThe element poped is : %d\n", front->info);

//     if (front == rear)
//     {
//         free(front);
//         front = NULL;
//         return;
//     }

//     temp = front;
//     front = front->next;
//     rear->next = front;
//     free(temp);
// }

// void traverse()
// {
//     if (front == NULL)
//     {
//         printf("\n----------UNDERFLOW----------\n ");
//         return;
//     }

//     temp = front->next;

//     printf("\nThe DATA in linked list is : %d\n", front->info);

//     while (temp != front)
//     {
//         printf("\nThe DATA in linked list is : %d\n", temp->info);
//         temp = temp->next;
//     }
// }

// void main()
// {
//     printf("\nPRESS 1 for PUSHING element in QUEUE.\nPRESS 2 for POPING a element in QUEUE.\nPRESS 3 for TRAVERSING the QUEUE.\nPRESS 4 for EXIT.\n");

//     while (choice != 4)
//     {
//         printf("\nEnter your choice : ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//         {
//             push();
//             break;
//         }
//         case 2:
//         {
//             pop();
//             break;
//         }
//         case 3:
//         {
//             traverse();
//             break;
//         }
//         case 4:
//         {
//             printf("\n----------EXITING----------\n");
//             break;
//         }
//         default:
//         {
//             printf("\n----------PLEASE CHOOSE VALID CHOICE----------\n");
//         }
//         }

//         printf("\n----------DONE----------\n");
//     }

//     getch();
// }

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *front, *rear;

public:
    CircularQueue()
    {
        front = rear = nullptr;
    }

    void push()
    {
        Node *newNode = new Node;

        if (!newNode)
        {
            cout << "\n----------OVERFLOW----------\n";
            return;
        }

        cout << "\nEnter the data: ";
        cin >> newNode->data;
        newNode->next = nullptr;

        if (front == nullptr)
        {
            front = rear = newNode;
            rear->next = front; // Circular link
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Circular link
        }
    }

    void pop()
    {
        if (front == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        Node *temp = front;
        cout << "\nThe element popped is: " << front->data << endl;

        if (front == rear)
        {
            delete front;
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
            rear->next = front; // Adjust the rear's next pointer
            delete temp;
        }
    }

    void traverse()
    {
        if (front == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        Node *temp = front;
        cout << "\nThe DATA in the circular queue is: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main()
{
    CircularQueue cq;
    int choice = 0;

    cout << "\nPRESS 1 for PUSHING an element into the QUEUE.\n";
    cout << "PRESS 2 for POPPING an element from the QUEUE.\n";
    cout << "PRESS 3 for TRAVERSING the QUEUE.\n";
    cout << "PRESS 4 for EXIT.\n";

    while (choice != 4)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cq.push();
            break;
        case 2:
            cq.pop();
            break;
        case 3:
            cq.traverse();
            break;
        case 4:
            cout << "\n----------EXITING----------\n";
            break;
        default:
            cout << "\n----------PLEASE CHOOSE A VALID CHOICE----------\n";
        }

        cout << "\n----------DONE----------\n";
    }

    return 0;
}
