#include <stdio.h>
struct process {
    int arrival_time;
    int burst_time;
    int ID;
    int wt;
    int ct;
    int tat;
};

void compute_statistics(struct process *p, int size) {
    int x;
    x = p[0].arrival_time;
    for(int i = 0; i < size; i++) {
        p[i].wt = x - p[i].arrival_time;
        x = x + p[i].burst_time;
        p[i].tat = p[i].burst_time + p[i].wt;
        p[i].ct = p[i].tat +  p[i].arrival_time;
    }
}

void print_statistics(struct process *p, int size) {
    int tat_average = 0, wt_average = 0;
    printf("-----------------------------------------------------------------------\n");
    printf("STATISTICS:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("PID    Arrival Time      Burst Time          CT          WT         TAT\n");

    for(int i = 0; i < size; i++) {
        tat_average = tat_average + p[i].tat;
        wt_average =  wt_average + p[i].wt;
        printf("%d %17d %15d %11d %11d %11d\n", p[i].ID, p[i].arrival_time, p[i].burst_time, p[i].ct, p[i].wt, p[i].tat);
    }
    tat_average = tat_average / size;
    wt_average =  wt_average / size;
    printf("-----------------------------------------------------------------------\n");
    printf("AVERAGE: %50d %11d\n", wt_average, tat_average);
}

int main() {
    int N;
    struct process p[1000];

    printf("Enter number of processes:\n");
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        printf("-------------------------\n");
        printf("Enter data for process %d:\n", i+1);
        printf("Arrival time =");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time =");
        scanf("%d", &p[i].burst_time);
        p[i].ID = i + 1;
    }

    int t0 = p[0].arrival_time;
    for(int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (p[j].arrival_time <= t0 &&
                p[j].burst_time < p[i].burst_time) {
                struct process tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
        t0 = t0 + p[i].burst_time;
    }

    compute_statistics(&p, N);
    print_statistics(&p, N);

    return 0;
}
