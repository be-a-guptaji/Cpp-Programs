#include <iostream>
using namespace std;

#define MAX 10

int choice, front = -1, rear = -1, queue[MAX], data;

bool isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    return false;
}

void push()
{
    if (isFull())
    {
        cout << "\n----------OVERFLOW----------\n";
    }
    else
    {
        if (front == -1)
        {
            front = 0; // Initially set front to 0 when the first element is inserted
        }
        rear = (rear + 1) % MAX; // Circular increment
        cout << "\nEnter the data: ";
        cin >> data;
        queue[rear] = data;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "\n----------UNDERFLOW----------\n";
    }
    else
    {
        cout << "\nPopped element: " << queue[front] << endl;
        if (front == rear)
        { // Only one element is in the queue
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX; // Circular increment
        }
    }
}

void traverse()
{
    if (isEmpty())
    {
        cout << "\n----------UNDERFLOW----------\n";
    }
    else
    {
        cout << "\nFront -> " << front << " ";
        cout << "\nQueue -> ";
        int i = front;
        while (i != rear)
        {
            cout << queue[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << queue[rear] << " ";
        cout << "\nRear -> " << rear << endl;
    }
}

int main()
{
    cout << "\nPRESS 1 for PUSHING element in QUEUE.\nPRESS 2 for POPPING an element in QUEUE.\nPRESS 3 for TRAVERSING the QUEUE.\nPRESS 4 for EXIT.\n";

    while (choice != 4)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            cout << "\n----------DONE----------\n";
            break;
        case 2:
            pop();
            cout << "\n----------DONE----------\n";
            break;
        case 3:
            traverse();
            cout << "\n----------DONE----------\n";
            break;
        case 4:
            cout << "\n----------EXITING----------\n";
            break;
        default:
            cout << "\n----------PLEASE CHOOSE A VALID CHOICE----------\n";
        }
    }

    return 0;
}
