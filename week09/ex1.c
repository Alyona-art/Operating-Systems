#include <stdio.h>

int main() {
    int n, m;
    int t[10001];
    int a[10001];
    int b[10001];
    int r[101] = {};
    int counter[101] = {};
    int hitcount = 0;
    int misscount;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++) {
        scanf("%d %d", &t[i], &a[i]);
        b[i] = 0;
    }
    int pages[101] = {};

    for(int i = 0; i<m; i++) {

        if(i>0 && t[i] > t[i-1]) {
            for (int j = 0; j < n; j++) {
                counter[j] = (counter[j] >> 1) | (r[j] << 7);
                r[j] = 0;
            }
        }

        int min_counter = counter[0];
        int index = 0;
        for(int j = 0; j<n; j++) {

            if(min_counter > counter[j] || min_counter == counter[j] && pages[j]<pages[index] || pages[j] == a[i]) {
                min_counter = counter[j];
                index = j;
                if(pages[j] == a[i])
                    break;
            }
        }

        if(pages[index] == a[i]) {
            printf("%d\n", 1);
            hitcount++;
        }
        else {
            printf("%d\n", 0);
            pages[index] = a[i];
            counter[index] = 0;
        }
        r[index] = 1;
    }

    misscount = m - hitcount;
    double ratio = (double)hitcount/misscount;
    printf("%06f\n", ratio);
    return 0;
}
