#include <iostream>
using namespace std;

class CircularLinkedList
{
private:
    struct Node
    {
        int info;
        Node *next;
    };

    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    ~CircularLinkedList()
    {
        if (head != nullptr)
        {
            Node *current = head;
            do
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            } while (current != head);
        }
    }

    bool checkMemory(int choice)
    {
        if (choice < 4)
        {
            Node *traverser = new Node;
            if (traverser == nullptr)
            {
                cout << "\n----------OVERFLOW----------\n";
                return false;
            }
            delete traverser;
        }
        else
        {
            if (head == nullptr)
            {
                cout << "\n----------UNDERFLOW----------\n";
                return false;
            }
        }
        return true;
    }

    void traversingInReverse(Node *traverser)
    {
        if (traverser->next == head)
        {
            cout << "\nThe DATA in linked list is : " << traverser->info << "\n";
            return;
        }
        traversingInReverse(traverser->next);
        cout << "\nThe DATA in linked list is : " << traverser->info << "\n";
    }

    void insertionAtTheBeginning()
    {
        int data;
        cout << "Enter DATA to insert at the BEGINNING OF THE NODE: ";
        cin >> data;

        Node *traverser = new Node;
        traverser->info = data;

        if (head == nullptr)
        {
            traverser->next = traverser;
            head = traverser;
        }
        else
        {
            Node *temp = head;
            Node *found = traverser;
            found->next = head;
            head = found;
            found = found->next;

            while (found->next != temp)
            {
                found = found->next;
            }
            found->next = head;
        }
        cout << "\n----------DONE----------\n";
    }

    void insertionAtTheMiddle()
    {
        int data, after_node;
        cout << "Enter DATA to insert at the MIDDLE OF THE NODE: ";
        cin >> data;
        cout << "Enter DATA after which you want to INSERT the NODE: ";
        cin >> after_node;

        Node *traverser = new Node;
        traverser->info = data;

        if (head == nullptr)
        {
            cout << "\n----------UNDERFLOW----------\n";
            return;
        }

        if (head->info == after_node)
        {
            Node *temp = head;
            traverser->next = head;
            head = traverser;
            Node *found = traverser;
            while (found->next != temp)
            {
                found = found->next;
            }
            found->next = head;
            return;
        }

        Node *found = head;
        while (found->info != after_node && found->next != head)
        {
            found = found->next;
        }

        if (found->info == after_node)
        {
            traverser->next = found->next;
            found->next = traverser;
        }
        else
        {
            cout << "The Element " << after_node << " is not in Linked List.\n";
        }
        cout << "\n----------DONE----------\n";
    }

    void insertionAtTheEnd()
    {
        int data;
        cout << "Enter DATA to insert at the END OF THE NODE: ";
        cin >> data;

        Node *traverser = new Node;
        traverser->info = data;

        if (head == nullptr)
        {
            head = traverser;
            traverser->next = head;
        }
        else
        {
            Node *found = head;
            while (found->next != head)
            {
                found = found->next;
            }
            found->next = traverser;
            traverser->next = head;
        }
        cout << "\n----------DONE----------\n";
    }

    void deletionAtTheBeginning()
    {
        cout << "DELETION OF NODE FROM THE BEGINNING: \n";

        Node *found = head;
        if (found->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head->next;
        Node *traverser = head;

        while (found->next != head)
        {
            found = found->next;
        }
        found->next = temp;
        head = temp;
        delete traverser;

        cout << "\n----------DONE----------\n";
    }

    void deletionAtTheMiddle()
    {
        cout << "DELETION OF NODE FROM THE MIDDLE: \n";
        int after_node;
        cout << "Enter DATA after which you want to DELETE the NODE: ";
        cin >> after_node;

        if (head->info == after_node && head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *found = head;
        if (head->info == after_node)
        {
            Node *temp = head;
            head = head->next;

            while (found->next != temp)
            {
                found = found->next;
            }
            found->next = head;
            delete temp;
            return;
        }

        while (found->info != after_node && found->next != head)
        {
            Node *traverser = found;
            found = found->next;
        }

        if (found->info == after_node)
        {
            Node *traverser = found;
            found = found->next;
            traverser->next = found->next;
            delete found;
        }
        else
        {
            cout << "The Element " << after_node << " is not in Linked List.\n";
        }
        cout << "\n----------DONE----------\n";
    }

    void deletionAtTheEnd()
    {
        cout << "DELETION OF NODE FROM THE END: \n";

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *found = head;
        while (found->next != head)
        {
            Node *traverser = found;
            found = found->next;
        }
        Node *traverser = found;
        traverser->next = head;
        delete found;

        cout << "\n----------DONE----------\n";
    }

    void traverse()
    {
        int traversing;
        cout << "TRAVERSING OF THE LINKED LIST:\n";
        cout << "\nPRESS 1 for NORMAL TRAVERSING.\nPRESS 2 for REVERSE TRAVERSING.\n";
        cout << "\nEnter your Method: ";
        cin >> traversing;

        Node *traverser = head;

        if (traversing == 1)
        {
            while (traverser->next != head)
            {
                cout << "\nThe DATA in linked list is: " << traverser->info << "\n";
                traverser = traverser->next;
            }
            cout << "\nThe DATA in linked list is: " << traverser->info << "\n";
        }
        else
        {
            traversingInReverse(head);
        }
    }
};

int main()
{
    CircularLinkedList list;
    int choice = 0;

    cout << "PRESS 1 for INSERTING NODE FROM THE BEGINNING.\nPRESS 2 for INSERTING NODE FROM THE MIDDLE.\nPRESS 3 for INSERTING FROM THE END.\nPRESS 4 for DELETION OF NODE FROM THE BEGINNING.\nPRESS 5 for DELETION OF NODE FROM THE MIDDLE.\nPRESS 6 for DELETION OF NODE FROM THE END.\nPRESS 7 for TO TRAVERSE THE LINKED LIST.\nPRESS 8 for EXIT.\n";

    while (choice != 8)
    {
        cout << "\nEnter the CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (list.checkMemory(choice))
            {
                list.insertionAtTheBeginning();
            }
            break;
        case 2:
            if (list.checkMemory(choice))
            {
                list.insertionAtTheMiddle();
            }
            break;
        case 3:
            if (list.checkMemory(choice))
            {
                list.insertionAtTheEnd();
            }
            break;
        case 4:
            if (list.checkMemory(choice))
            {
                list.deletionAtTheBeginning();
            }
            break;
        case 5:
            if (list.checkMemory(choice))
            {
                list.deletionAtTheMiddle();
            }
            break;
        case 6:
            if (list.checkMemory(choice))
            {
                list.deletionAtTheEnd();
            }
            break;
        case 7:
            if (list.checkMemory(choice))
            {
                list.traverse();
            }
            break;
        case 8:
            cout << "\n----------EXITING----------\n";
            break;
        default:
            cout << "\n----------PLEASE CHOOSE VALID CHOICE----------\n";
        }
    }

    return 0;
}
