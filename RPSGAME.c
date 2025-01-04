#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print the chosen option
void gamenamefunction(int option);

// Function to display the score
void score(char *name, int playerpoint, int cpupoint);

int main()
{
    char a[100];
    int n, opt, cpu, playerpoint = 0, cpupoint = 0;

    srand(time(NULL)); // Seed the random number generator

    // Print the game rules and get player's name and the number of rounds
    printf("\nWELCOME TO THE GAME OF ROCK PAPER SCISSORS.\n");
    printf("\nRULES ARE AS FOLLOW :\n1 : The winner of each round awarded with 1 point.\n2 : The loser of each round is awarded with 0 point.\n3 : If both get the same thing, no points will be awarded.\n4 : If you choose an invalid option, you have to choose it again until you choose a valid option.\n");

    printf("\nEnter Your Name :\t");
    fgets(a, 100, stdin);
    a[strcspn(a, "\n")] = 0; // Remove the newline character from the input

    printf("\nEnter the BEST OF SERIES :\t");
    scanf("%d", &n);

    // Play the game for the specified number of rounds
    for (int i = 0; i < n; i++)
    {
        printf("\nROUND %d :\n", i + 1);
        printf("\nChoose your option\nPRESS 1 for ROCK\nPRESS 2 for PAPER\nPRESS 3 for SCISSORS\n");

        // Input validation using a do-while loop
        do
        {
            printf("\n%s's Turn : \t", a);
            scanf("%d", &opt);
            if (opt < 1 || opt > 3)
            {
                printf("\nYou choose an invalid option, choose again.\n");
            }
        } while (opt < 1 || opt > 3);

        // Display the chosen options and determine the winner
        printf("\n%s Chooses :\t", a);
        gamenamefunction(opt);
        cpu = rand() % 3 + 1;
        printf("\nComputer Chooses :\t");
        gamenamefunction(cpu);

        if (opt == cpu)
        {
            printf("\nIt's a TIE.\nNo points AWARDED.\n");
        }
        else if ((opt == 1 && cpu == 3) || (opt == 2 && cpu == 1) || (opt == 3 && cpu == 2))
        {
            printf("\n%s Wins 1 point AWARDED\n", a);
            playerpoint++;
        }
        else
        {
            printf("\nComputer Wins 1 point AWARDED\n");
            cpupoint++;
        }

        // Display the score after each round
        score(a, playerpoint, cpupoint);
    }

    // Determine the overall winner based on the total points
    if (playerpoint == cpupoint)
    {
        printf("\n%s score %d points.\nComputer score %d points\n", a, playerpoint, cpupoint);
        printf("\nIt's a TIE.\n");
    }
    else if (playerpoint > cpupoint)
    {
        printf("\n%s score %d points.\nComputer score %d points\n", a, playerpoint, cpupoint);
        printf("\n%s WINS\n", a);
    }
    else if (playerpoint < cpupoint)
    {
        printf("\n%s score %d points.\nComputer score %d points\n", a, playerpoint, cpupoint);
        printf("\nComputer WINS\n");
    }

    return 0;
}

// Function to print the chosen option
void gamenamefunction(int option)
{
    if (option == 1)
    {
        printf("ROCK\n");
    }
    else if (option == 2)
    {
        printf("PAPER\n");
    }
    else
    {
        printf("SCISSOR\n");
    }
}

// Function to display the score
void score(char *name, int playerpoint, int cpupoint)
{
    printf("\nSCORE\n%s's Score :\t%d\nComputer's Score :\t%d\n", name, playerpoint, cpupoint);
}