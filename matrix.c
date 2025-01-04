#include <stdio.h>
#include <conio.h>

void main()
{
    int a[10][10], b[10][10], c[10][10], rowsofa, coloumsofa, rowsofb, coloumsofb, sum = 0;

    printf("Enter the number of rows of matrix A.\n");
    scanf("%d", &rowsofa);
    printf("Enter the number of coloums of matrix A.\n");
    scanf("%d", &coloumsofa);
    printf("Enter the elements of matrix A.\n");
    for (int i = 0; i < rowsofa; i++)
    {
        for (int j = 0; j < coloumsofa; j++)
        {
            printf("A[%d][%d]\t\t", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows of matrix B.\n");
    scanf("%d", &rowsofb);
    printf("Enter the number of coloums of matrix B.\n");
    scanf("%d", &coloumsofb);
    printf("Enter the elements of matrix B.\n");
    for (int i = 0; i < rowsofb; i++)
    {
        for (int j = 0; j < coloumsofb; j++)
        {
            printf("B[%d][%d]\t\t", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    if (coloumsofa == rowsofb)
    {
        printf("The multiplication of matrix A and B.\n");
        for (int i = 0; i < rowsofa; i++)
        {
            for (int j = 0; j < coloumsofb; j++)
            {
                for (int k = 0; k < coloumsofa; k++)
                {
                    sum += a[i][k] * b[k][j];
                }
                c[i][j] = sum;
                sum = 0;
            }
        }

        for (int i = 0; i < rowsofa; i++)
        {
            for (int j = 0; j < coloumsofb; j++)
            {
                printf("C[%d][%d]\t%d\t", i + 1, j + 1, c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The mutiplication of matrix is not possible.\n");
    }

    getch();
}