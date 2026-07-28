#include <stdio.h>

int main()
{
    int n, tq;
    int burst[20], remaining[20];
    int waiting[20], turnaround[20];
    int completed = 0;
    int time = 0;

    printf("===== Round Robin CPU Scheduling =====\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(int i = 0; i < n; i++)
    {
        printf("Burst Time for Process P%d: ", i + 1);
        scanf("%d", &burst[i]);

        remaining[i] = burst[i];
    }

    while(completed < n)
    {
        for(int i = 0; i < n; i++)
        {
            if(remaining[i] > 0)
            {
                if(remaining[i] <= tq)
                {
                    time += remaining[i];
                    remaining[i] = 0;

                    turnaround[i] = time;
                    waiting[i] = turnaround[i] - burst[i];

                    completed++;
                }
                else
                {
                    remaining[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("\n-------------------------------------------------\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-------------------------------------------------\n");

    float totalWaiting = 0;
    float totalTurnaround = 0;

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1,
               burst[i],
               waiting[i],
               turnaround[i]);

        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }

    printf("-------------------------------------------------\n");

    printf("\nAverage Waiting Time    : %.2f", totalWaiting / n);
    printf("\nAverage Turnaround Time : %.2f\n", totalTurnaround / n);

    return 0;
}
