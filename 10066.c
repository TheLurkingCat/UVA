#include <stdio.h>

#define max(x, y) (x) > (y) ? (x) : (y)

int main() {
    int a[101], b[101], i, j, n, m, k = 1;
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
        int dp[101][101] = {};
        n++;
        m++;
        for (i = 1; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 1; i < m; i++)
            scanf("%d", &b[i]);
        for (i = 1; i < n; i++) {
            for (j = 1; j < m; j++) {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", k++, dp[n - 1][m - 1]);
    }
}