/*
    找零錢問題
    時間複雜度: O(MN) (M種幣值，最大輸入N)
*/
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long dp[6001] = {1};
    int i, j, x, y, index, currency[11] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
    char point;
    // 建好所有組合的表
    for (i = 0; i < 11; ++i)
        for (j = currency[i]; j < 6001; ++j)
            dp[j] += dp[j - currency[i]];

    while (cin >> x >> point >> y && (x || y)) {
        index = 20 * x + y / 5;  // 避免浮點數誤差，最小是0.05所以乘20就好，陣列也只要開6000
        cout << setw(6) << fixed << setprecision(2) << double(index) / 20 << setw(17) << dp[index] << '\n';
    }
    return 0;
}