#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> stack;
    const int MAX = 10;

public:
    void push()
    {
        int element;
        cout << "\nEnter ELEMENT to PUSH in STACK: ";
        cin >> element;

        if (stack.size() == MAX)
        {
            cout << "\n----------OVERFLOW----------\n";
            return;
        }

        stack.push_back(element);
    }

    void pop()
    {
        if (stack.empty())
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        cout << "\nELEMENT is POPPED from the STACK.\n";
        stack.pop_back();
    }

    void traverse()
    {
        if (stack.empty())
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        cout << "\nELEMENTS in the STACK:\n";
        for (int i = stack.size() - 1, j = 1; i >= 0; i--, j++)
        {
            cout << "The " << j << " ELEMENT is: " << stack[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice = 0;

    while (choice != 4)
    {
        cout << "\nPRESS 1 to PUSH in STACK."
             << "\nPRESS 2 to POP from STACK."
             << "\nPRESS 3 to TRAVERSE the STACK."
             << "\nPRESS 4 to EXIT.\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.push();
            cout << "\n----------DONE----------\n";
            break;
        case 2:
            s.pop();
            cout << "\n----------DONE----------\n";
            break;
        case 3:
            s.traverse();
            cout << "\n----------DONE----------\n";
            break;
        case 4:
            cout << "\n----------EXITING----------\n";
            break;
        default:
            cout << "\n----------PLEASE CHOOSE A VALID CHOICE----------\n";
            break;
        }
    }

    return 0;
}
