#include <iostream>

using namespace std;

class Stack
{
private:
    struct Node
    {
        int info;
        Node* next;
    };

    Node* head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push()
    {
        Node* traverser = new Node;

        if (traverser == nullptr)
        {
            cout << "\n----------OVERFLOW----------\n";
            return;
        }

        int element;
        cout << "\nEnter ELEMENT to PUSH in STACK: ";
        cin >> element;

        traverser->info = element;
        traverser->next = head;
        head = traverser;
    }

    void pop()
    {
        cout << "\nELEMENT is POPED from the STACK.\n";

        if (head == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        Node* traverser = head;

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        head = traverser->next;
        delete traverser;
    }

    void traverse()
    {
        cout << "\nELEMENTS in the STACK.\n";

        if (head == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        Node* traverser = head;

        while (traverser != nullptr)
        {
            cout << "\nThe ELEMENT is: " << traverser->info << endl;
            traverser = traverser->next;
        }
    }

    void menu()
    {
        int choice = 0;

        cout << "\nPRESS 1 to PUSH in STACK.\nPRESS 2 to POP from STACK.\nPRESS 3 to TRAVERSE the STACK.\nPRESS 4 to EXIT.\n";

        while (choice != 4)
        {
            cout << "\nEnter choice: ";
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
                cout << "\n----------PLEASE CHOOSE VALID CHOICE----------\n";
                break;
            }
        }
    }
};

int main()
{
    Stack stack;
    stack.menu();

    return 0;
}
