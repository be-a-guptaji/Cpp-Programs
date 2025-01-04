#include <stdio.h>
#include <windows.h>

int main()
{
    int h, m, s;
    int d = 1000;

    printf("Set time :\n");
    printf("Enter hours : ");
    scanf("%d", &h);
    printf("Enter minutes : ");
    scanf("%d", &m);
    printf("Enter seconds : ");
    scanf("%d", &s);

    if (h > 12 || m > 60 || s > 60)
    {
        printf("ERROR ! \n");
        exit(0);
    }

    while (1)
    {
        s++;
        if (s >= 60)
        {
            m++;
            s = 0;
        }
        if (m >= 60)
        {
            h++;
            m = 0;
        }
        if (h >= 12)
        {
            h = 0;
            m = 0;
            s = 0;
        }
        printf("\nClock : \n %02d : %02d : %02d", h, m, s);
        Sleep(d);
        system("cls");
    }

    return 0;
}