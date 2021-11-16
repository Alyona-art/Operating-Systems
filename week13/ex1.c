#include <stdio.h>
#include <stdbool.h>

int main() {
    char str;
    int E[1000];
    int A[1000];
    int C[100][100];
    int R[100][100];
    int P_num;
    int R_num = 0;
    bool resourceReleased = true;
    int totalReleased = 0;
    bool processReleased[100] = {false};

    FILE *file;
    file = fopen("input.txt", "r");

    if(file == NULL)
        printf("Error: file is empty\n");

    else {
        int count_lines = 0;
        for (str = getc(file); str != EOF; str = getc(file))
            if (str == '\n')
                count_lines = count_lines + 1;
        P_num = (count_lines - 5)/2;
        fseek(file, 0, SEEK_SET);

        /// Scan array E
        while (str != '\n') {
            fscanf(file, "%c", &str);
            if (str >= 48 && str <= 57) {
                fseek(file, -1, SEEK_CUR);
                fscanf(file, "%d", &E[R_num]);
                R_num++;
            }
        }

        /// Scan array A
        for (int i = 0; i < R_num; i++)
            fscanf(file, "%d", &A[i]);

        /// Scan array C
        for(int i = 0; i < P_num; i++) {
            for (int j = 0; j < R_num; j++)
                fscanf(file, "%d", &C[i][j]);
        }
        /// Scan array R
        for (int i = 0; i < P_num; i++) {
            for (int j = 0; j < R_num; j++)
                fscanf(file, "%d", &R[i][j]);
        }

        while (resourceReleased) {
            resourceReleased = false;
            for (int i = 0; i < P_num; i++) {
                bool resourceIsEnough = true;
                for (int j = 0; j < R_num; j++) {
                    if (R[i][j] > A[j])
                        resourceIsEnough = false;
                }
                if (resourceIsEnough && !processReleased[i]) {
                    resourceReleased = true;
                    for (int j = 0; j < R_num; j++)
                        A[j] = A[j] + C[i][j];
                    totalReleased++;
                    processReleased[i] = true;
                }
            }
            if (totalReleased == P_num)
                resourceReleased = false;
        }

        int DLnum = 0;
        for (int i = 0; i < P_num; i++) {
            if (!processReleased[i])
                DLnum++;
        }
        if (DLnum == 0)
            printf("No deadlock is detected");
        else if (DLnum == 1) {
            printf("%d process is deadlocked:\n", DLnum);
            for (int i = 0; i < P_num; i++) {
                if (!processReleased[i])
                    printf("p%d", i);
            }
        } else {
            printf("%d processes are deadlocked\n", DLnum);
            for (int i = 0; i < P_num; i++) {
                if (!processReleased[i])
                    printf("p%d ", i);
            }
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}
