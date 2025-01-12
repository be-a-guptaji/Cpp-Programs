#include <iostream>
using namespace std;

int fabrec(int z);
int fabloop(int z);

int re = 1, loop = 1; // Global variables to track recursion and loop counts

// Iterative Fibonacci function
int fabloop(int z)
{
    int a = 0, b = 1;

    for (int i = 1; i < z; i++)
    {
        loop++;
        b = a + b;
        a = b - a;
    }
    return a;
}

// Recursive Fibonacci function
int fabrec(int z)
{
    re++;
    if (z == 1 || z == 2)
    {
        return (z - 1);
    }
    else
    {
        return (fabrec(z - 1) + fabrec(z - 2));
    }
}

int main()
{
    int a;

    cout << "Enter number up to which you want Fibonacci series." << endl;
    cin >> a;

    cout << "The Fibonacci number at position " << a << " by using loop is \t" << fabloop(a) << "." << endl;
    cout << "The Fibonacci number at position " << a << " by using recursion is \t" << fabrec(a) << "." << endl;

    cout << "The Fibonacci series using loop ran " << loop << " times." << endl;
    cout << "The Fibonacci series using recursion ran " << re << " times." << endl;

    return 0;
}
