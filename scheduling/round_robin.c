#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    long int pid;
    int bt;
    int at;
} process;
void roundrobin(process pro[], int n, int quantum)
{
    int i, j;
    float avg, avg1, sum = 0.0, sum1 = 0.0;
    int flag = 0;
    int t = 0;
    int lines = 0, checkpoints[100], ckindex = 0;
    int tt[100], done[100], wt[100], bt[100];
    for (i = 0; i < n; i++)
    {
        done[i] = 0, wt[i] = 0, bt[i] = pro[i].bt;
        lines += pro[i].bt / quantum;
        if (pro[i].bt % quantum != 0)
            lines++;
    }
    i = 0;
    printf("\nGantt Chart:\n\n");
    for (i = 0; i < lines; i++)
        printf("------");
    printf("\n");
    i = 0;
    while (flag < n)
    {
        if (done[i] == 0 && bt[i] >= quantum)
        {
            bt[i] -= quantum;
            if (bt[i] == 0)
                done[i] = 1, flag++;
            t += quantum;
            checkpoints[ckindex++] = t;
            for (j = 0; j < n; j++)
                if (done[j] == 0 && j != i)
                    wt[j] += quantum;
            for (int k = 0; k < quantum / 2; k++)
                printf(" ");
            printf("P%ld ", pro[i].pid);
            for (int k = 0; k < quantum / 2; k++)
                printf(" ");
            printf("|");
        }
        else
        {
            if (done[i] == 1)
                goto label;
            int temp = bt[i];
            bt[i] = 0;
            done[i] = 1;
            flag++;
            t += temp;
            checkpoints[ckindex++] = t;
            for (j = 0; j < n; j++)
                if (done[j] == 0 && j != i)
                    wt[j] += temp;
            for (int k = 0; k < quantum / 2; k++)
                printf(" ");
            printf("P%ld ", pro[i].pid);
            for (int k = 0; k < quantum / 2; k++)
                printf(" ");
            printf("|");
        }
    label:
        i = (i + 1) % n;
    }
    printf("\n");
    for (i = 0; i < lines; i++)
        printf("------");
    printf("\n0 ");
    for (i = 0; i < lines; i++)
    {
        for (int k = 0; k < quantum / 2; k++)
            printf(" ");
        printf("%d ", checkpoints[i]);
        for (int k = 0; k < quantum / 2; k++)
            printf(" ");
    }
    for (i = 0; i < n; i++)
        tt[i] = wt[i] + pro[i].bt - pro[i].at, wt[i] -= pro[i].at;
    printf("\n\nProcess ID\t Burst Time\t Waiting Time\t Turn around Time \n");
    for (i = 0; i < n; i++)
    {
        printf(" P%ld\t\t", pro[i].pid);
        printf(" %d\t\t", pro[i].bt);
        printf(" %d\t\t", wt[i]);
        printf(" %d\t\t", tt[i]);
        printf("\n");
    }
    for (i = 0; i < n; i++)
        sum += wt[i], sum1 += tt[i];
    avg = sum / n;
    avg1 = sum1 / n;
    printf("\nAverage Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg, avg1);
}

void main()
{
    int pno;
    int quantum;
    process pro[100];
    printf("\nEnter the no. of Processes: ");
    scanf("%d", &pno);
    for (int i = 0; i < pno; i++)
    {
        printf("\nEnter the process ID: ");
        scanf("%ld", &pro[i].pid);
        printf("Enter the burst time: ");
        scanf("%d", &pro[i].bt);
        printf("Enter the arrival time: ");
        scanf("%d", &pro[i].at);
    }
    printf("\n\nEnter the quantum time slice: ");
    scanf("%d", &quantum);
    roundrobin(pro, pno, quantum);
}