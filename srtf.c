#include <stdio.h>
#define size 10
struct process {
    int id;
    int at, bt, rt;
    int ct, wt, tat;
};
void SRTF(struct process p[], int n);
int main() {
    int n;
    struct process p[size];

    printf("Enter no of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].id = i;
        printf("Enter arrival time & burst time for P%d: ", i);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }
    SRTF(p, n);

    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }

    printf("\nAvg Waiting Time: %.2f", total_wt / n);
    printf("\nAvg Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
void SRTF(struct process p[], int n) {
    int completed = 0, t = 0, min_time = 999, idx = -1;

    while (completed != n) {
        idx = -1;
        min_time = 999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt > 0 && p[i].rt < min_time) {
                min_time = p[i].rt;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].rt--;

            if (p[idx].rt == 0) {
                completed++;
                p[idx].ct = t + 1;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        }
        t++;
    }
}
