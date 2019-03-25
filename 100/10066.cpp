/*
    最長公共子序列
    時間複雜度: O(N^2)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, case_n = 1;
    while (cin >> n >> m && (n || m)) {
        ++m;
        ++n;
        vector<int> tower_1(n, 0), tower_2(m, 0);
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 1; i < n; i++)
            cin >> tower_1[i];

        for (int i = 1; i < m; i++)
            cin >> tower_2[i];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (tower_1[i] == tower_2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << "Twin Towers #" << case_n++ << "\nNumber of Tiles : " << dp.back().back() << "\n\n";
    }
}