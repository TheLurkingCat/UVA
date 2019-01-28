/*
    建表
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, n, dp[51] = {0, 1, 2};

    for (i = 3; i < 51; i++)
        dp[i] = dp[i - 1] + dp[i - 2];  // i - 1 加一塊直的或 i - 2 加一塊橫的

    while (cin >> n && n)
        cout << dp[n] << "\n";

    return 0;
}