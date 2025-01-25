#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int info;
        Node *next;
    };

    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool checkMemory()
    {
        Node *newNode = new (std::nothrow) Node;
        if (!newNode)
        {
            cout << "\n----------OVERFLOW----------\n";
            return false;
        }
        delete newNode; // Immediately delete to avoid memory leak
        return true;
    }

    void insertionAtTheBeginning(int data)
    {
        Node *newNode = new Node;
        newNode->info = data;
        newNode->next = head;
        head = newNode;
    }

    void insertionAtTheMiddle(int data, int afterNode)
    {
        Node *newNode = new Node;
        newNode->info = data;

        Node *current = head;
        while (current != nullptr && current->info != afterNode)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            newNode->next = current->next;
            current->next = newNode;
        }
        else
        {
            cout << "Element " << afterNode << " not found in the list.\n";
            delete newNode;
        }
    }

    void insertionAtTheEnd(int data)
    {
        Node *newNode = new Node;
        newNode->info = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deletionAtTheBeginning()
    {
        if (head == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deletionAtTheMiddle(int afterNode)
    {
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

        if (current != nullptr && current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            cout << "Element " << afterNode << " not found in the list or no next node to delete.\n";
        }
    }

    void deletionAtTheEnd()
    {
        if (head == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr && current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    void traverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *current = head;
        cout << "The DATA in linked list is: ";
        while (current != nullptr)
        {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }

    void traverseInReverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        traverseInReverse(node->next);
        cout << node->info << " ";
    }

    void traverseReverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "The DATA in reverse order: ";
        traverseInReverse(head);
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    int choice = 0;
    int data, afterNode;

    while (choice != 8)
    {
        cout << "\nPRESS 1 for INSERTING NODE AT THE BEGINNING.\n";
        cout << "PRESS 2 for INSERTING NODE AT THE MIDDLE.\n";
        cout << "PRESS 3 for INSERTING AT THE END.\n";
        cout << "PRESS 4 for DELETION OF NODE AT THE BEGINNING.\n";
        cout << "PRESS 5 for DELETION OF NODE AT THE MIDDLE.\n";
        cout << "PRESS 6 for DELETION OF NODE AT THE END.\n";
        cout << "PRESS 7 for TO TRAVERSE THE LINKED LIST.\n";
        cout << "PRESS 8 for EXIT.\n";
        cout << "\nEnter your CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (list.checkMemory())
            {
                cout << "Enter DATA to insert at the BEGINNING OF THE NODE: ";
                cin >> data;
                list.insertionAtTheBeginning(data);
                cout << "----------DONE----------\n";
            }
            break;
        case 2:
            if (list.checkMemory())
            {
                cout << "Enter DATA to insert at the MIDDLE OF THE NODE: ";
                cin >> data;
                cout << "Enter DATA after which you want to INSERT the NODE: ";
                cin >> afterNode;
                list.insertionAtTheMiddle(data, afterNode);
                cout << "----------DONE----------\n";
            }
            break;
        case 3:
            if (list.checkMemory())
            {
                cout << "Enter DATA to insert at the END OF THE NODE: ";
                cin >> data;
                list.insertionAtTheEnd(data);
                cout << "----------DONE----------\n";
            }
            break;
        case 4:
            list.deletionAtTheBeginning();
            cout << "----------DONE----------\n";
            break;
        case 5:
            cout << "Enter DATA after which you want to DELETE the NODE: ";
            cin >> afterNode;
            list.deletionAtTheMiddle(afterNode);
            cout << "----------DONE----------\n";
            break;
        case 6:
            list.deletionAtTheEnd();
            cout << "----------DONE----------\n";
            break;
        case 7:
            list.traverse();
            list.traverseReverse();
            break;
        case 8:
            cout << "----------EXITING----------\n";
            break;
        default:
            cout << "----------PLEASE CHOOSE A VALID CHOICE----------\n";
        }
    }

    return 0;
}
