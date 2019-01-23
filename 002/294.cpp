/*
    質因數分解
    時間複雜度: O(NlogN)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int i, t = 2, j, not_prime[65540] = {0, 0, 1}, prime[6545] = {0, 2};
    int x, y, n_case, ans, m, not_found = 1, cnt, num = 1, k, ans_occur;

    // 建質數表
    for (j = 4; j < 65540; j += 2) {
        not_prime[j] = 1;
    }
    for (i = 3; i < 257; i += 2) {
        if (!not_prime[i]) {
            prime[t++] = i;
            for (j = i * i; j < 65540; j += i) {
                not_prime[j] = 1;
            }
        }
    }
    for (i = 257; i < 65540; i++) {
        if (!not_prime[i]) {
            prime[t++] = i;
            if (t == 6543) {
                break;
            }
        }
    }

    cin >> n_case;
    while (n_case--) {
        ans = 0;
        cin >> x >> y;
        // 每個值代公式算因數個數
        for (m = x; m <= y; m++) {
            k = m;
            t = 1;
            i = prime[t];
            num = 1;
            not_found = 1;

            while (k != 1 && t < 6543) {
                cnt = 0;
                if (k % i == 0) {
                    cnt = 0;
                    not_found = 0;
                    while (k % i == 0) {
                        k /= i;
                        cnt++;
                    }
                    num *= (cnt + 1);
                }
                t++;
                i = prime[t];
            }

            if (k != 1) {
                if (not_found) {
                    if (2 > ans) {
                        ans = 2;
                        ans_occur = m;
                    }
                } else {
                    if (num * 2 > ans) {
                        ans = num * 2;
                        ans_occur = m;
                    }
                }
            } else {
                if (num > ans) {
                    ans = num;
                    ans_occur = m;
                }
            }
        }
        cout << "Between " << x << " and " << y << ", " << ans_occur << " has a maximum of " << ans << " divisors.\n";
    }
    return 0;
}