#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50

int process = 0, processes = 0, total_time = 0, time_quantum = 0;
vector<int> arrival_time(MAX), burst_time(MAX), completion_time(MAX), turn_around_time(MAX), waiting_time(MAX), response_time(MAX);
vector<int> burst_copy(MAX), ready_queue(MAX), time_queue(MAX);

void calculate_times()
{
    int ready_index = 0, running_index = 0;

    while (process < processes)
    {
        total_time += time_quantum;

        while (arrival_time[process] <= total_time && process < processes)
        {
            ready_queue[ready_index++] = process;
            process++;
        }

        if (burst_copy[ready_queue[running_index]] > time_quantum)
        {
            burst_copy[ready_queue[running_index]] -= time_quantum;
            ready_queue[ready_index++] = ready_queue[running_index];
            time_queue[running_index + 1] = time_queue[running_index] + time_quantum;
        }
        else
        {
            time_queue[running_index + 1] = time_queue[running_index] + burst_copy[ready_queue[running_index]];
            burst_copy[ready_queue[running_index]] = 0;
        }

        running_index++;
    }

    while (running_index != ready_index)
    {
        if (burst_copy[ready_queue[running_index]] > time_quantum)
        {
            burst_copy[ready_queue[running_index]] -= time_quantum;
            ready_queue[ready_index++] = ready_queue[running_index];
            time_queue[running_index + 1] = time_queue[running_index] + time_quantum;
        }
        else
        {
            time_queue[running_index + 1] = time_queue[running_index] + burst_copy[ready_queue[running_index]];
            burst_copy[ready_queue[running_index]] = 0;
        }
        running_index++;
    }

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < ready_index; j++)
        {
            if (ready_queue[j] == i)
            {
                running_index = j;
            }
        }
        completion_time[i] = time_queue[running_index + 1];
    }
}

int main()
{
    cout << "Enter the number of PROCESSES: ";
    cin >> processes;

    cout << "Enter the TIME QUANTUM: ";
    cin >> time_quantum;

    cout << "Enter the ARRIVAL TIME of each process:\n";
    for (int i = 0; i < processes; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> arrival_time[i];
    }

    cout << "Enter the BURST TIME of each process:\n";
    for (int i = 0; i < processes; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
        burst_copy[i] = burst_time[i];
    }

    time_queue[0] = 0;
    calculate_times();

    float average_turn_around_time = 0, average_waiting_time = 0, average_response_time = 0;

    cout << "P.No.\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n";

    for (int i = 0; i < processes; i++)
    {
        turn_around_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];

        for (int j = 0; j < ready_queue.size(); j++)
        {
            if (ready_queue[j] == i)
            {
                response_time[i] = time_queue[j] - arrival_time[i];
                break;
            }
        }

        average_turn_around_time += turn_around_time[i];
        average_waiting_time += waiting_time[i];
        average_response_time += response_time[i];

        cout << i + 1 << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t" << completion_time[i]
             << "\t\t\t" << turn_around_time[i] << "\t\t\t" << waiting_time[i] << "\t\t" << response_time[i] << endl;
    }

    cout << "\nAverage Turn Around Time: " << (float)average_turn_around_time / processes << endl;
    cout << "Average Waiting Time: " << (float)average_waiting_time / processes << endl;
    cout << "Average Response Time: " << (float)average_response_time / processes << endl;

    return 0;
}
