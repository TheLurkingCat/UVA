/*
    最小子矩陣問題(升維的最大連續和問題)
    時間複雜度: O(N^3)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<vector<int>> array(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> array[i][j];

    int ans = 0x80000000;

    for (int i = 0; i < n; i++) {
        vector<int> dp(n, 0);
        // 壓縮二維陣列(把 i ~ n 的陣列壓成一維)
        // 就可以當作最大連續和(一維)問題計算
        for (int j = i; j < n; j++) {
            int sum_now = 0;

            for (int k = 0; k < n; k++) {
                dp[k] += array[j][k];

                // 當前和 >=0，那就試著加入下一個
                if (sum_now >= 0)
                    sum_now += dp[k];
                // 當前和<0，那就當作第一個重新開始
                else
                    sum_now = dp[k];

                ans = max(sum_now, ans);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}