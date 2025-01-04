//Aurthor := Aryan Baadlas
//Date    := 9th May 2024

#include <stdio.h>
#include <conio.h>

#define MAX 50

int process = 0, processes = 0, total_time = 0, time_quantum = 0, arrival_time[MAX], burst_time[MAX], completion_time[MAX], turn_around_time[MAX], waiting_time[MAX], response_time[MAX], burst_copy[MAX], ready_queue[MAX], ready_index = 0, running_index = 0, time_queue[MAX], average_turn_around_time = 0, average_waiting_time = 0, average_response_time = 0;

void main()
{
    printf("Enter the number of PROCESSES: \t");
    scanf("%d", &processes);

    printf("Enter the TIME QUANTUM: \t");
    scanf("%d", &time_quantum);

    printf("Enter the ARRIVAL TIME of each process: \n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: \t", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    printf("Enter the BURST TIME of each process: \n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: \t", i + 1);
        scanf("%d", &burst_time[i]);
        burst_copy[i] = burst_time[i];
    }

    time_queue[0] = 0;

    while (process < processes)
    {
        total_time += time_quantum;

        while (arrival_time[process] <= total_time && process < processes)
        {
            ready_queue[ready_index] = process;
            ready_index++;
            process++;
        }
        if (burst_copy[ready_queue[running_index]] > time_quantum)
        {
            burst_copy[ready_queue[running_index]] -= time_quantum;
            ready_queue[ready_index] = ready_queue[running_index];
            ready_index++;
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
            ready_queue[ready_index] = ready_queue[running_index];
            time_queue[running_index + 1] = time_queue[running_index] + time_quantum;
            ready_index++;
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

    printf("P.No.\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time   Response Time\n");

    for (int i = 0; i < processes; i++)
    {
        turn_around_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];

        for (int j = 0; j < ready_index; j++)
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

        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turn_around_time[i], waiting_time[i], response_time[i]);
    }

    printf("\nAverage Turn Around Time: %f\n", (float)average_turn_around_time / processes);
    printf("Average Waiting Time: %f\n", (float)average_waiting_time / processes);
    printf("Average Response Time: %f\n", (float)average_response_time / processes);

    getch();
}