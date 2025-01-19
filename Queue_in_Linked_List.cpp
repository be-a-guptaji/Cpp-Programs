#include <iostream>
#include <queue>

using namespace std;

int choice = 0, data;

void push(queue<int> &q)
{
    cout << "Enter DATA to insert at the END OF THE QUEUE: ";
    cin >> data;
    q.push(data);
    cout << "----------DONE----------\n";
}

void pop(queue<int> &q)
{
    if (q.empty())
    {
        cout << "----------UNDERFLOW----------\n";
        return;
    }

    cout << "Element POPPED: " << q.front() << endl;
    q.pop();
    cout << "----------DONE----------\n";
}

void traverse(queue<int> &q)
{
    if (q.empty())
    {
        cout << "----------UNDERFLOW----------\n";
        return;
    }

    cout << "TRAVERSING THE QUEUE:\n";
    queue<int> tempQueue = q;
    while (!tempQueue.empty())
    {
        cout << "The DATA in queue is: " << tempQueue.front() << endl;
        tempQueue.pop();
    }
    cout << "----------DONE----------\n";
}

int main()
{
    queue<int> q;

    cout << "\nPRESS 1 for PUSHING element in QUEUE.\nPRESS 2 for POPPING an element in QUEUE.\nPRESS 3 for TRAVERSING the QUEUE.\nPRESS 4 for EXIT.\n";

    while (choice != 4)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push(q);
            break;
        case 2:
            pop(q);
            break;
        case 3:
            traverse(q);
            break;
        case 4:
            cout << "\n----------EXITING----------\n";
            break;
        default:
            cout << "\n----------PLEASE CHOOSE A VALID OPTION----------\n";
        }
    }

    return 0;
}
