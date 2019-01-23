/*
    盈數、虧數、完全數
    時間複雜度: O(logN) (在輸入是 N = 2^M 次時最多要除 logN = M 次)
*/
#include <iomanip>
#include <iostream>

using namespace std;
// 建好根號60000以內質數表
int primes[53] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, t, factor_sum, count, temp;
    cout << "PERFECTION OUTPUT\n";

    while (cin >> n && n) {
        factor_sum = 1;
        t = 0;
        k = n;
        // 因數和公式
        while (k != 1 && t < 53) {
            count = temp = 1;
            while (k % primes[t] == 0) {
                k /= primes[t];
                temp *= primes[t];
                count += temp;
            }
            factor_sum *= count;
            t++;
        }
        // 多出來的要乘回去
        if (k != 1)
            factor_sum *= (k + 1);

        factor_sum -= n;  // 自己不算

        if (factor_sum > n)
            cout << setw(5) << n << "  ABUNDANT\n";
        else if (factor_sum < n)
            cout << setw(5) << n << "  DEFICIENT\n";
        else
            cout << setw(5) << n << "  PERFECT\n";
    }

    cout << "END OF OUTPUT\n";
    return 0;
}