#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;

public:
    // Constructor to initialize head as NULL
    LinkedList() : head(nullptr) {}

    // Destructor to free allocated memory
    ~LinkedList()
    {
        freeList();
    }

    // Function to insert data at the beginning
    void insert(int value)
    {
        Node *newNode = new Node();
        if (newNode == nullptr)
        {
            cout << "Memory allocation failed!" << endl;
            return;
        }
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to traverse and print the linked list
    void traverse() const
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node *current = head;
        cout << "The Linked List is:" << endl;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Function to free the allocated memory
    void freeList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList list;
    int choice = 1, info;

    while (choice != 0)
    {
        cout << "Do you want to insert data into the Linked list?" << endl;
        cout << "PRESS 1 for YES" << endl;
        cout << "PRESS 0 for NO" << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the information: ";
            cin >> info;
            list.insert(info);
        }
        else if (choice == 0)
        {
            continue;
        }
        else
        {
            cout << "Enter a valid option." << endl;
            continue;
        }
    }

    list.traverse(); // Traverse the list and print it

    return 0; // Return 0 to indicate successful execution
}
