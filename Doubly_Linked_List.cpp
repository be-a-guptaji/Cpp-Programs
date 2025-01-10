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
