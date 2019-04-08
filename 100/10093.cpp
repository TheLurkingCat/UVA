/*
    進位、餘數
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string base = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", n;
    int dp[128] = {}, i = 1;

    for (const char& c : base)
        dp[c] = ++i;

    dp['0'] = 2;

    while (cin >> n) {
        int i;
        for (i = dp[*max_element(n.begin(), n.end())]; i < 63; i++) {
            long long temp = 0;

            for (const char& c : n)
                if (c != '0' and isalnum(c))
                    temp += dp[c] - 1;

            if (temp % (i - 1) == 0)
                break;
        }

        if (i == 63)
            cout << "such number is impossible!\n";
        else
            cout << i << "\n";
    }
}