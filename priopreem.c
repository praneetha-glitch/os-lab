#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], pr[n];
    int wt[n], tat[n];
    for(i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    int highest;
    int min_pr;
    int finish_time;

    while(completed != n) {
        highest = -1;
        min_pr = 9999;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                highest = i;
            }
        }

        if(highest == -1) {
            time++;
            continue;
        }
        rt[highest]--;
        if(rt[highest] == 0) {
            completed++;
            finish_time = time + 1;

            wt[highest] = finish_time - bt[highest] - at[highest];
            if(wt[highest] < 0)
                wt[highest] = 0;
        }

        time++;
    }
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
