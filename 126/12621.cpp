/*
    01背包問題
*/
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int calories, n_testcase, course, x;
    cin >> n_testcase;

is_printed:
    while (n_testcase--) {
        bitset<500> dp;
        dp[0] = true;

        cin >> calories >> course;
        calories /= 10;

        for (int i = 0; i < course; i++) {
            cin >> x;
            x /= 10;
            for (int j = 250; j > -1; j--)
                if (dp[j])
                    dp[j + x] = 1;
        }

        for (int i = calories; i < 500; i++)
            if (dp[i]) {
                cout << i * 10 << "\n";
                goto is_printed;
            }

        cout << "NO SOLUTION\n";
    }
    return 0;
}