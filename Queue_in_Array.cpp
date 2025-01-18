#include <iostream>
using namespace std;

#define MAX 10

int choice, front = -1, rear = -1, queue[MAX], data;

void push()
{
    if (rear + 1 == MAX)
    {
        cout << "\n----------OVERFLOW----------\n";
        return;
    }

    cout << "\nEnter the data to queue: ";
    cin >> data;

    queue[++rear] = data;
    front = 0;
}

void pop()
{
    if (rear == -1)
    {
        cout << "\n----------UNDERFLOW----------\n";
        return;
    }

    cout << "\nElement is popped\n";

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
        cout << "\n----------UNDERFLOW----------\n";
        return;
    }

    cout << "\nThe elements in the queue are:\n";

    for (int i = 0; i <= rear; i++)
    {
        cout << "\nThe element is: " << queue[i] << endl;
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
