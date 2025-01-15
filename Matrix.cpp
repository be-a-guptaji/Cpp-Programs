#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rowsofa, coloumsofa, rowsofb, coloumsofb;

    // Input for matrix A
    cout << "Enter the number of rows of matrix A: ";
    cin >> rowsofa;
    cout << "Enter the number of columns of matrix A: ";
    cin >> coloumsofa;

    // Declare matrix A
    vector<vector<int>> a(rowsofa, vector<int>(coloumsofa));
    cout << "Enter the elements of matrix A:\n";
    for (int i = 0; i < rowsofa; i++)
    {
        for (int j = 0; j < coloumsofa; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> a[i][j];
        }
    }

    // Input for matrix B
    cout << "Enter the number of rows of matrix B: ";
    cin >> rowsofb;
    cout << "Enter the number of columns of matrix B: ";
    cin >> coloumsofb;

    // Declare matrix B
    vector<vector<int>> b(rowsofb, vector<int>(coloumsofb));
    cout << "Enter the elements of matrix B:\n";
    for (int i = 0; i < rowsofb; i++)
    {
        for (int j = 0; j < coloumsofb; j++)
        {
            cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> b[i][j];
        }
    }

    // Matrix multiplication condition
    if (coloumsofa == rowsofb)
    {
        // Declare matrix C for the result of multiplication
        vector<vector<int>> c(rowsofa, vector<int>(coloumsofb, 0));

        // Matrix multiplication
        cout << "The multiplication of matrix A and B is:\n";
        for (int i = 0; i < rowsofa; i++)
        {
            for (int j = 0; j < coloumsofb; j++)
            {
                for (int k = 0; k < coloumsofa; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        // Print the result matrix C
        for (int i = 0; i < rowsofa; i++)
        {
            for (int j = 0; j < coloumsofb; j++)
            {
                cout << c[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Matrix multiplication is not possible. The number of columns in A must be equal to the number of rows in B.\n";
    }

    return 0;
}
