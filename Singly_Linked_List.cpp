#include <iostream>
using namespace std;

// Global Variable to use everywhere in code....
int choice = 0, data, after_node;

// We make replica of this structure....
struct Node
{
    int info;
    Node *next;
};

// This stores the first address of the structure....
Node *head = nullptr, *traverser, *found, *temp;

// Functions for Implementation....
bool check_memory(int choice)
{
    if (choice < 4)
    {
        traverser = new Node;

        if (traverser == nullptr)
        {
            cout << "\n----------OVERFLOW----------\n";
            return false;
        }

        return true;
    }
    else
    {
        if (head == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return false;
        }
        return true;
    }
}

void mover()
{
    found = head;

    while (found->next != nullptr)
    {
        if (choice == 6)
        {
            traverser = found;
        }
        found = found->next;
        if (choice == 7)
        {
            cout << "\nThe DATA in linked list is : " << found->info << endl;
        }
    }
}

void traversing_in_reverse(Node *traverser)
{
    if (traverser->next == nullptr)
    {
        cout << "\nThe DATA in linked list is : " << traverser->info << endl;
        return;
    }
    traversing_in_reverse(traverser->next);
    cout << "\nThe DATA in linked list is : " << traverser->info << endl;
}

bool node_remover()
{
    delete head;
    head = nullptr;
    return true;
}

bool last_node_remover()
{
    if (head->next == nullptr)
    {
        return node_remover();
    }

    if (head->info == after_node && head->next == nullptr)
    {
        return node_remover();
    }
    return false;
}

void insertion_at_the_beginning()
{
    cout << "Enter DATA to insert at the BEGINNING OF THE NODE : ";
    cin >> data;

    traverser->info = data;
    traverser->next = head;
    head = traverser;
}

void insertion_at_the_middle()
{
    cout << "Enter DATA to insert at the MIDDLE OF THE NODE : ";
    cin >> data;

    cout << "Enter DATA after which you want to INSERT the NODE : ";
    cin >> after_node;

    traverser->info = data;

    if (head->info == after_node)
    {
        traverser->next = head;
        head = traverser;
        return;
    }

    found = head;

    while (found->info != after_node && found->next != nullptr)
    {
        temp = found;
        found = found->next;
    }

    if (found->info == after_node && found->next == nullptr)
    {
        traverser->next = found;
        temp->next = traverser;
        return;
    }

    if (found->info == after_node)
    {
        traverser->next = found;
        temp->next = traverser;
    }
    else
    {
        cout << "The Element " << after_node << " is not in Linked List.\n";
    }
}

void insertion_at_the_end()
{
    cout << "Enter DATA to insert at the END OF THE NODE : ";
    cin >> data;

    traverser->info = data;

    if (head == nullptr)
    {
        traverser->next = head;
        head = traverser;
        return;
    }

    mover();
    found->next = traverser;
    traverser->next = nullptr;
}

void deletion_at_the_beginning()
{
    cout << "DELETION OF NODE FROM THE BEGINNING : \n";

    traverser = head;

    if (last_node_remover() == true)
    {
        return;
    }

    head = traverser->next;
    delete traverser;
}

void deletion_at_the_middle()
{
    cout << "DELETION OF NODE FROM THE MIDDLE : \n";
    cout << "Enter DATA after which you want to DELETE the NODE : ";
    cin >> after_node;

    if (last_node_remover() == true)
    {
        return;
    }

    traverser = head;

    if (head->info == after_node)
    {
        head = head->next;
        delete traverser;
        return;
    }

    found = head;

    while (found->info != after_node && found->next != nullptr)
    {
        traverser = found;
        found = found->next;
    }

    if (found->info == after_node)
    {
        traverser->next = found->next;
        delete found;
    }
    else
    {
        cout << "The Element " << after_node << " is not in Linked List.\n";
    }
}

void deletion_at_the_end()
{
    cout << "DELETION OF NODE FROM THE END : \n";

    if (last_node_remover() == true)
    {
        return;
    }

    mover();
    traverser->next = nullptr;
    delete found;
}

void traverse()
{
    int traversing;
    cout << "TRAVERSING OF THE LINKED LIST :\n";
    cout << "\nPRESS 1 for NORMAL TRAVERSING.\nPRESS 2 for REVERSE TRAVERSING.\n";
    cout << "\nEnter your method.\n";
    cin >> traversing;

    if (traversing == 1)
    {
        cout << "\nThe DATA in linked list is : " << head->info << endl;
        mover();
    }
    else
    {
        traversing_in_reverse(head);
    }
}

// Driver Function....
int main()
{
    cout << "PRESS 1 for INSERTING NODE AT THE BEGINNING.\nPRESS 2 for INSERTING NODE AT THE MIDDLE.\nPRESS 3 for INSERTING AT THE END.\nPRESS 4 for DELETION OF NODE AT THE BEGINNING.\nPRESS 5 for DELETION OF NODE AT THE MIDDLE.\nPRESS 6 for DELETION OF NODE AT THE END.\nPRESS 7 for TO TRAVERSE THE LINKED LIST.\nPRESS 8 for EXIT.\n";

    while (choice != 8)
    {
        cout << "\nEnter the CHOICE : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (check_memory(choice) == true)
            {
                insertion_at_the_beginning();
            }
            cout << "\n----------DONE----------\n";
            break;
        }
        case 2:
        {
            if (check_memory(choice) == true)
            {
                insertion_at_the_middle();
            }
            cout << "\n----------DONE----------\n";
            break;
        }
        case 3:
        {
            if (check_memory(choice) == true)
            {
                insertion_at_the_end();
            }
            cout << "\n----------DONE----------\n";
            break;
        }
        case 4:
        {
            if (check_memory(choice) == true)
            {
                deletion_at_the_beginning();
            }
            cout << "\n----------DONE----------\n";
            break;
        }
        case 5:
        {
            if (check_memory(choice) == true)
            {
                deletion_at_the_middle();
            }
            cout << "\n----------DONE----------\n";
            break;
        }
        case 6:
        {
            if (check_memory(choice) == true)
            {
                deletion_at_the_end();
            }
            cout << "\n----------DONE----------\n";
            break;
        }
        case 7:
        {
            if (check_memory(choice) == true)
            {
                traverse();
            }
            cout << "\n----------DONE----------\n";
            break;
        }

        case 8:
        {
            cout << "\n----------EXITING----------\n";
            break;
        }
        default:
        {
            cout << "\n----------PLEASE CHOOSE A VALID CHOICE----------\n";
        }
        }
    }

    return 0;
}
