#include <iostream>
using namespace std;

int main()
{
    int a, b, k;

start:

    cout << "To add numbers \t\tPRESS 1." << endl;
    cout << "To subtract numbers \tPRESS 2." << endl;
    cout << "To multiply numbers \tPRESS 3." << endl;
    cout << "To divide numbers \tPRESS 4." << endl;
    cin >> k;

    cout << "Enter Number 1: ";
    cin >> a;

    cout << "Enter Number 2: ";
    cin >> b;

    if (k > 0 && k < 5)
    {
        switch (k)
        {
        case 1:
            cout << "The sum of " << a << " and " << b << " is " << a + b << "." << endl;
            break;
        case 2:
            cout << "The subtraction of " << a << " and " << b << " is " << a - b << "." << endl;
            break;
        case 3:
            cout << "The multiplication of " << a << " and " << b << " is " << a * b << "." << endl;
            break;
        case 4:
            if (b != 0)
                cout << "The division of " << a << " and " << b << " is " << static_cast<float>(a) / b << "." << endl;
            else
                cout << "Error: Division by zero is not allowed!" << endl;
            break;
        }
    }
    else if (k == 0)
    {
        cout << "You chose 0, which is not an option. The remainder of " << a << " and " << b << " is " << a % b << "." << endl;
    }
    else
    {
        cout << "You chose " << k << ", which is not an option. Please try again." << endl;
        goto start;
    }

    return 0;
}
