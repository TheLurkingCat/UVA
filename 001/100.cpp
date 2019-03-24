/*
    3n+1 問題
*/
#include <algorithm>
#include <iostream>

using namespace std;

int dp[1000001] = {1, 1};

int calculate(int n) {
    // 大於 10^6 的就不暫存直接暴力算
    // 因為會很快就收斂到較小的數值
    if (n > 1000000) {
        if (n & 1)
            return calculate(3 * n + 1) + 1;
        else
            return calculate(n / 2) + 1;
    }
    // 使用動態規劃避免重複計算
    if (dp[n])
        return dp[n];
    if (n & 1)
        dp[n] = calculate(3 * n + 1) + 1;
    else
        dp[n] = calculate(n / 2) + 1;

    return dp[n];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j;
    while (cin >> i >> j) {
        cout << i << " " << j << " ";
        // 這題 i 不一定小於 j
        // 這點要注意一下
        if (i > j)
            swap(i, j);

        int ans = 0;

        for (int k = i; k <= j; k++)
            ans = max(ans, calculate(k));

        cout << ans << "\n";
    }
    return 0;
}