#include <stdio.h>
struct process
{
    int finished;
    int pid;
    int at;
    int bt;
};
int main()
{
    int n;
    printf("Enter the no of process: ");
    scanf("%d", &n);
    struct process p[n + 1];
    for (int i = 1; i <= n; i++)
    {
        p[i].finished = 0;
        printf("\nEnter the process id of the process : ");
        scanf("%d", &p[i].pid);
        printf("Enter the arrival of the process %d : ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of the process %d : ", p[i].pid);
        scanf("%d", &p[i].bt);
    }
    int turnAround[n + 1], waitTime[n + 1];
    int timeElapsed = 0;
    int avgTurnAround = 0, avgWaitTime = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = 1e5;
        int nextprocess = -1;
        for (int j = 1; j <= n; j++)
        {
            if (p[j].finished == 0 && p[j].at < cur)
            {
                cur = p[j].at;
                nextprocess = p[j].pid;
            }
        }
        if (p[nextprocess].at > timeElapsed)
        {
            timeElapsed = p[nextprocess].at;
        }
        timeElapsed += p[nextprocess].bt;
        turnAround[nextprocess] = timeElapsed - p[nextprocess].at;
        waitTime[nextprocess] = turnAround[nextprocess] - p[nextprocess].bt;
        p[nextprocess].finished = 1;
        avgTurnAround += turnAround[nextprocess];
        avgWaitTime += waitTime[nextprocess];
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nPID: %d | TurnaroundTime: %d | Waiting Time: %d\n", i + 1, turnAround[i + 1], waitTime[i + 1]);
    }
    printf("\nAvg waiting time : %f\nAvg Turnaround time : %f \n", avgWaitTime / (n + 0.0), avgTurnAround / (n + 0.0));
}