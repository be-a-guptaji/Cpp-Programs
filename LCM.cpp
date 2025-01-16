#include <iostream>
using namespace std;

// Function to calculate the Greatest Common Divisor (GCD)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;

    cout << "Enter two numbers to find the LCM of them." << endl;

    cout << "Enter First number: ";
    cin >> a;

    cout << "Enter Second number: ";
    cin >> b;

    int result = lcm(a, b);

    cout << "The LCM of " << a << " and " << b << " is " << result << "." << endl;

    return 0;
}