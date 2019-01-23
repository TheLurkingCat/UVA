/*
    最小子矩陣問題(升維的最大連續和問題)
    時間複雜度: O(N^3)
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int i, j, k, n, ans = -2147438648, sum_now;
    int array[100][100] = {};
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> array[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        int dp[100] = {};
        // 壓縮二維陣列(把i~n的陣列壓成一維)
        // 就可以當作最大連續和(一維)問題計算
        for (j = i; j < n; j++) {
            sum_now = 0;

            for (k = 0; k < n; k++) {
                dp[k] += array[j][k];

                // 當前和>=0，那就試著加入下一個
                if (sum_now >= 0)
                    sum_now += dp[k];
                // 當前和<0，那就當作第一個重新開始
                else
                    sum_now = dp[k];

                ans = max(sum_now, ans);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}