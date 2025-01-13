#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers to find the HCF of them." << endl;

    cout << "Enter First number: ";
    cin >> a;

    cout << "Enter Second number: ";
    cin >> b;

    // Using Euclid's algorithm to find HCF
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "The HCF of the entered numbers is " << a << "." << endl;

    return 0;
}
