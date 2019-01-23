#include <stdio.h>

int main() {
    int i, j, n, m, t, day, sum;
    scanf("%d", &t);
    while (t--) {
        sum = 0;
        int arr[3650] = {};
        scanf("%d %d", &day, &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &m);
            for (j = m - 1; j < day; j += m) {
                arr[j] = 1;
            }
        }
        for (i = 0; i < day; i++) {
            if (arr[i] && i % 7 < 5)
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}