#include <math.h>
#include <stdio.h>

int main() {
    int i, n, num, last, flag, overflow_check;
    while (scanf("%d", &n) == 1) {
        if (n == 1) {
            scanf("%d", &num);
            printf("Jolly\n");
            continue;
        }
        int seen[3001] = {0};
        flag = 1;
        for (i = 0; i < n; i++) {
            scanf("%d", &num);
            if (i == 0) {
                last = num;
            } else {
                overflow_check = abs(num - last);
                if (overflow_check < 3000) {
                    seen[overflow_check] = 1;
                    last = num;
                }
            }
        }
        for (i = 1; i < n; i++) {
            if (seen[i] == 0) {
                printf("Not jolly\n");
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("Jolly\n");
        }
    }
    return 0;
}