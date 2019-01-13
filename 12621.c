#include <stdio.h>

int main() {
    int i, n, t, j, p, x;
    scanf("%d", &t);
    while (t--) {
        int dp[500] = {1};
        scanf("%d %d", &n, &p);
        n /= 10;
        for (i = 0; i < p; i++) {
            scanf("%d", &x);
            x /= 10;
            for (j = 250; j > -1; j--)
                if (dp[j])
                    dp[j + x] = 1;
        }
        for (i = n; i < 500; i++)
            if (dp[i]) {
                printf("%d\n", i * 10);
                break;
            }
        if (i == 500)
            printf("NO SOLUTION\n");
    }
    return 0;
}