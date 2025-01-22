#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to print the chosen option
void gamenamefunction(int option);

// Function to display the score
void score(const string &name, int playerpoint, int cpupoint);

int main()
{
    string name;
    int n, opt, cpu, playerpoint = 0, cpupoint = 0;

    srand(time(0)); // Seed the random number generator

    // Print the game rules and get player's name and the number of rounds
    cout << "\nWELCOME TO THE GAME OF ROCK PAPER SCISSORS.\n";
    cout << "\nRULES ARE AS FOLLOW :\n1 : The winner of each round awarded with 1 point.\n2 : The loser of each round is awarded with 0 point.\n3 : If both get the same thing, no points will be awarded.\n4 : If you choose an invalid option, you have to choose it again until you choose a valid option.\n";

    cout << "\nEnter Your Name: ";
    getline(cin, name);

    cout << "\nEnter the BEST OF SERIES: ";
    cin >> n;

    // Play the game for the specified number of rounds
    for (int i = 0; i < n; i++)
    {
        cout << "\nROUND " << i + 1 << ":\n";
        cout << "\nChoose your option\nPRESS 1 for ROCK\nPRESS 2 for PAPER\nPRESS 3 for SCISSORS\n";

        // Input validation using a do-while loop
        do
        {
            cout << "\n"
                 << name << "'s Turn: ";
            cin >> opt;
            if (opt < 1 || opt > 3)
            {
                cout << "\nYou chose an invalid option, choose again.\n";
            }
        } while (opt < 1 || opt > 3);

        // Display the chosen options and determine the winner
        cout << "\n"
             << name << " Chooses: ";
        gamenamefunction(opt);
        cpu = rand() % 3 + 1;
        cout << "\nComputer Chooses: ";
        gamenamefunction(cpu);

        if (opt == cpu)
        {
            cout << "\nIt's a TIE.\nNo points AWARDED.\n";
        }
        else if ((opt == 1 && cpu == 3) || (opt == 2 && cpu == 1) || (opt == 3 && cpu == 2))
        {
            cout << "\n"
                 << name << " Wins 1 point AWARDED\n";
            playerpoint++;
        }
        else
        {
            cout << "\nComputer Wins 1 point AWARDED\n";
            cpupoint++;
        }

        // Display the score after each round
        score(name, playerpoint, cpupoint);
    }

    // Determine the overall winner based on the total points
    if (playerpoint == cpupoint)
    {
        cout << "\n"
             << name << " score " << playerpoint << " points.\nComputer score " << cpupoint << " points\n";
        cout << "\nIt's a TIE.\n";
    }
    else if (playerpoint > cpupoint)
    {
        cout << "\n"
             << name << " score " << playerpoint << " points.\nComputer score " << cpupoint << " points\n";
        cout << "\n"
             << name << " WINS\n";
    }
    else
    {
        cout << "\n"
             << name << " score " << playerpoint << " points.\nComputer score " << cpupoint << " points\n";
        cout << "\nComputer WINS\n";
    }

    return 0;
}

// Function to print the chosen option
void gamenamefunction(int option)
{
    if (option == 1)
    {
        cout << "ROCK\n";
    }
    else if (option == 2)
    {
        cout << "PAPER\n";
    }
    else
    {
        cout << "SCISSOR\n";
    }
}

// Function to display the score
void score(const string &name, int playerpoint, int cpupoint)
{
    cout << "\nSCORE\n"
         << name << "'s Score: " << playerpoint << "\nComputer's Score: " << cpupoint << "\n";
}
