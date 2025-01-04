#include <stdio.h>

int main()
{
    int n;
    printf("Enter the depth of box : \t");
    scanf("%d", &n);
    int check = 0;
    
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int count = 0, temp = n;
        for (int j = 0; j < 2 * n - 1; j++)
        {
            printf("%d ", temp);
            if (check != count && j + i < 2 * n - 2)
            {
                temp--;
                count++;
            }
            if (temp < n && j >= 2 * n - 2 - count)
            {
                temp++;
            }
        }
        if (i < n)
        {
            check++;
        }
        else
        {
            check--;
        }
        printf("\n");
    }
    return 0;
}