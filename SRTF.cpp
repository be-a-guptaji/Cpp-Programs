#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 50

using namespace std;

int main()
{
    int processes = 0, total_time = 0, ready_index = 0, smallest = 0;
    int average_turn_around_time = 0, average_waiting_time = 0, average_response_time = 0;

    cout << "Enter the number of PROCESSES: ";
    cin >> processes;

    vector<int> arrival_time(processes), burst_time(processes), burst_copy(processes), completion_time(processes), time_queue(processes), ready_queue(processes);

    cout << "Enter the ARRIVAL TIME of each process: \n";
    for (int i = 0; i < processes; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> arrival_time[i];
    }

    cout << "Enter the BURST TIME of each process: \n";
    for (int i = 0; i < processes; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
        burst_copy[i] = burst_time[i];
    }

    // Check function (replaced with lambda function)
    auto check = [&]()
    {
        for (int i = 0; i < processes; i++)
        {
            if (burst_copy[i] != 0)
            {
                return true;
            }
        }
        return false;
    };

    while (check())
    {
        for (int i = 0; i < processes; i++)
        {
            if (total_time >= arrival_time[i] && burst_copy[i] > 0)
            {
                if (burst_copy[smallest] > burst_copy[i])
                {
                    smallest = i;
                }
            }
        }

        if (ready_queue[ready_index - 1] != smallest || ready_index == 0)
        {
            ready_queue[ready_index++] = smallest;
        }

        burst_copy[smallest]--;

        for (int i = 0; i < processes; i++)
        {
            if (burst_copy[i] > 0)
            {
                smallest = i;
                break;
            }
        }

        total_time++;
        time_queue[ready_index] = total_time;
    }

    cout << "P.No.\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time   Response Time\n";

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < ready_index; j++)
        {
            if (ready_queue[j] == i)
            {
                smallest = j;
            }
        }
        completion_time[i] = time_queue[smallest + 1];
    }

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < ready_index; j++)
        {
            if (ready_queue[j] == i)
            {
                smallest = time_queue[j] - arrival_time[i];
                break;
            }
        }

        average_turn_around_time += completion_time[i] - arrival_time[i];
        average_waiting_time += completion_time[i] - arrival_time[i] - burst_time[i];
        average_response_time += smallest;

        cout << i + 1 << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t"
             << completion_time[i] << "\t\t\t" << completion_time[i] - arrival_time[i]
             << "\t\t\t" << completion_time[i] - arrival_time[i] - burst_time[i]
             << "\t\t" << smallest << endl;
    }

    cout << "\nAverage Turn Around Time: " << (float)average_turn_around_time / processes << endl;
    cout << "Average Waiting Time: " << (float)average_waiting_time / processes << endl;
    cout << "Average Response Time: " << (float)average_response_time / processes << endl;

    return 0;
}
