/*
    質數、建表
    時間複雜度: O(N)
*/
#include <iostream>
#include <vector>

using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, n, ans;
    // 建質數表
    vector<int> prime_table;
    vector<bool> is_prime(32769, true);
    is_prime[1] = false;
    for (i = 2; i < 32769; i++) {
        if (is_prime[i])
            prime_table.push_back(i);
        for (j = 0; i * prime_table[j] < 32769; j++) {
            is_prime[i * prime_table[j]] = false;
            if (i % prime_table[j] == 0)
                break;
        }
    }

    while (cin >> n && n) {
        ans = j = 0;
        i = n / 2;

        // 找到大於 n 的最小質數位置
        while (prime_table[j] <= i)
            j++;

        // 判斷 n - (1 ~ n 之間的質數) 是不是質數
        for (i = 0; i < j; i++)
            if (is_prime[n - prime_table[i]])
                ans++;

        cout << ans << "\n";
    }
    return 0;
}