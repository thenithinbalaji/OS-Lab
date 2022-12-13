#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid, bt, priority, at, wt, tat, st, rem_bt, started;
} Process;

typedef struct Gantt {
    int pid, time;
} Gantt;

Process * min_priority(Process processes[], int n, int clock) {
    Process * min_process = & processes[0];
    for (int i = 1; i < n; i++) {
        if (processes[i].priority < min_process -> priority && processes[i].at <= clock) {
            min_process = & processes[i];
        }
    }
    return min_process;
}

void remove_element(Process * array, int index, int array_length) {
    for (int i = index; i < array_length - 1; i++)
        array[i] = array[i + 1];
}

int main() {
    int n;
    n = 5;
    Process processes[n]; // List of all Processes
    printf("Enter number of processes: ");
    scanf("%d", & n);
    Gantt chart[100];
    int chart_len = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for process %d: ", i + 1);
        scanf("%d %d %d", & processes[i].at, & processes[i].bt, & processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].started = 0;
        processes[i].rem_bt = processes[i].bt;
    }
    printf("\nPID\t AT\t BT\t PR\t ST\t CT\t WT\t TAT\n");

    int clock = 0;
    int prev = 0; // Previous Process ID
    while (n > 0) {
        Process * min_process = min_priority(processes, n, clock);
        // Gant Chart Calulation below
        if (prev && min_process -> pid == prev) {
            chart[chart_len - 1].time = clock;
        } else {
            prev = min_process -> pid;
            chart[chart_len].pid = min_process -> pid;
            chart[chart_len].time = clock + 1;
            chart_len++;
        }

        if (min_process -> rem_bt == 0) {
            min_process -> tat = clock - min_process -> at;
            min_process -> wt = min_process -> tat - min_process -> bt;
            printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t\n", min_process -> pid, min_process -> at, min_process -> bt, min_process -> priority, min_process -> st, clock, min_process -> wt, min_process -> tat);
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (processes[i].pid == min_process -> pid)
                    idx = i;
            }
            remove_element(processes, idx, n);
            n--;
            continue;
        }
        if (min_process -> started == 0) {
            min_process -> started = 1;
            min_process -> st = clock;
        }
        min_process -> rem_bt--;
        clock++;
    }
    printf("\nGantt Chart %d:\n", chart_len);
    for (int i = 0; i < chart_len; i++) {
        printf("| P%d %d ", chart[i].pid, chart[i].time);
    }
    printf("|\n");
}
