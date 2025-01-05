#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the depth of the box: \t";
    cin >> n;
    int check = 0;

    // Outer loop for rows (total 2 * n - 1 rows)
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int count = 0, temp = n; // Start with the topmost number (n)

        // Inner loop for columns (total 2 * n - 1 columns)
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << temp << " "; // Print current number

            // Decrease numbers to the center of the box
            if (check != count && j + i < 2 * n - 2)
            {
                temp--;
                count++;
            }

            // Increase numbers symmetrically after the center
            if (temp < n && j >= 2 * n - 2 - count)
            {
                temp++;
            }
        }

        // Adjust 'check' value for the next row (this controls the number's flow)
        if (i < n)
        {
            check++;
        }
        else
        {
            check--;
        }

        cout << endl; // New line after each row
    }

    return 0; // Exit successfully
}
