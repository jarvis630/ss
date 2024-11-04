#include <stdio.h>

int main() {
    int pid[15];
    int bt[15];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process id of all the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    int wt[n];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurn Around Time\n");

    float twt = 0.0;
    float tat = 0.0;

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], bt[i] + wt[i]);
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }

    float awt = twt / n;
    float att = tat / n;

    printf("Avg. waiting time = %.2f\n", awt);
    printf("Avg. turnaround time = %.2f\n", att);

    return 0;
}
