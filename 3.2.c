#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int execution;
    int period;
    int deadline;
    int remaining;
    int next_release;
    int abs_deadline;
    float weight;
} Task;

void resetTasks(Task t[], int n) {
    for (int i = 0; i < n; i++) {
        t[i].remaining = 0;
        t[i].next_release = 0;
        t[i].abs_deadline = 0;
    }
}
void rateMonotonic(Task t[], int n, int time_limit) {
    printf("\n--- Rate Monotonic Scheduling ---\n");

    for (int time = 0; time < time_limit; time++) {
        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].next_release += t[i].period;
            }
        }

        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (selected == -1 || t[i].period < t[selected].period) {
                    selected = i;
                }
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, t[selected].id);
            t[selected].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }
}
void earliestDeadlineFirst(Task t[], int n, int time_limit) {
    printf("\n--- Earliest Deadline First Scheduling ---\n");

    for (int time = 0; time < time_limit; time++) {

        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].abs_deadline = time + t[i].deadline;
                t[i].next_release += t[i].period;
            }
        }

        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (selected == -1 || t[i].abs_deadline < t[selected].abs_deadline) {
                    selected = i;
                }
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, t[selected].id);
            t[selected].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }
}

void proportionalScheduling(Task t[], int n, int time_limit) {
    printf("\n--- Proportional Scheduling ---\n");

    float total_weight = 0;
    for (int i = 0; i < n; i++) {
        total_weight += t[i].weight;
    }

    float share[MAX] = {0};

    for (int time = 0; time < time_limit; time++) {


        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].next_release += t[i].period;
            }
        }

        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                share[i] += t[i].weight / total_weight;
            }
        }


        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (selected == -1 || share[i] > share[selected]) {
                    selected = i;
                }
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, t[selected].id);
            t[selected].remaining--;
            share[selected] -= 1.0;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }
}

int main() {
    int n, time_limit;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[MAX];

    for (int i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);
        tasks[i].id = i + 1;

        printf("Execution time: ");
        scanf("%d", &tasks[i].execution);

        printf("Period: ");
        scanf("%d", &tasks[i].period);

        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);

        printf("Weight (for proportional): ");
        scanf("%f", &tasks[i].weight);
    }

    printf("\nEnter simulation time: ");
    scanf("%d", &time_limit);

    resetTasks(tasks, n);
    rateMonotonic(tasks, n, time_limit);

    resetTasks(tasks, n);
    earliestDeadlineFirst(tasks, n, time_limit);

    resetTasks(tasks, n);
    proportionalScheduling(tasks, n, time_limit);

    return 0;
}
