/*
    找零錢問題的變種
    時間複雜度: O(N^2)
*/
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, k, x, backup, ans, count, temp, total, get_dp[101] = {}, currency[6] = {1, 2, 4, 10, 20, 40}, coin[6];
    double n;
    // 建好所有組合的表，找錢時有無限多硬幣
    for (i = 1; i < 101; i++) {
        backup = i, count = 0;
        for (j = 5; j > -1 && backup; j--)
            if (backup >= currency[j]) {
                temp = backup / currency[j];
                count += temp;
                backup -= (currency[j] * temp);
            }
        get_dp[i] = count;
    }

    while (cin >> coin[0] >> coin[1] >> coin[2] >> coin[3] >> coin[4] >> coin[5] >> n) {
        // 把除了 give_dp[0] 以外的值都設成最大值 2139062143
        int give_dp[3001] = {};  // 假設每種不超過500個
        memset(give_dp + 1, 127, sizeof(int) * 3000);

        x = (n + 1e-3) * 20;

        total = 0;
        // 自己手上的錢總和
        for (i = 0; i < 6; i++)
            total += coin[i] * currency[i];

        // 6種錢幣，每種可以取 0 到 coin[i] 個，所以是01背包問題的一個變種
        // 在原來01背包問題上多一個執行 coin[i] 次的迴圈即可

        for (i = 0; i < 6; i++)
            for (j = 0; j < coin[i]; j++)
                for (k = total; k >= currency[i]; k--)
                    give_dp[k] = min(give_dp[k], give_dp[k - currency[i]] + 1);

        ans = give_dp[x];  // 直接付清

        // x最大是 5 * 20 = 100
        // 答案是付 i 元找 i - x 元的最小硬幣數
        for (i = x + 1; i < 101; i++)
            ans = min(ans, give_dp[i] + get_dp[i - x]);

        cout << setw(3) << ans << '\n';
    }
    return 0;
}