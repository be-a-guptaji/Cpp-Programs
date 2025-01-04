// Aurthor := Aryan Baadlas
// Date    := 14th May 2024

#include <stdio.h>
#define max 50

int processes = 0, completion_time[max], arrival_time[max], burst_time[max], burst_copy[max], time_queue[max], total_time = 0, ready_queue[max], ready_index = 0, smallest = 0, average_turn_around_time = 0, average_waiting_time = 0, average_response_time = 0;

int check()
{
    for (int i = 0; i < processes; i++)
    {
        if (burst_copy[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the number of PROCESSES: \t");
    scanf("%d", &processes);

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

    printf("P.No.\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time   Response Time\n");

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

        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], completion_time[i] - arrival_time[i], completion_time[i] - arrival_time[i] - burst_time[i], smallest);
    }

    printf("\nAverage Turn Around Time: %f\n", (float)average_turn_around_time / processes);
    printf("Average Waiting Time: %f\n", (float)average_waiting_time / processes);
    printf("Average Response Time: %f\n", (float)average_response_time / processes);

    return 0;
}