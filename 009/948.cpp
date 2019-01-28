/*
    費式進位法
    時間複雜度: O(N)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, n, n_case, Fibonacci[39] = {1, 2};

    for (i = 2; i < 39; i++)
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];

    cin >> n_case;
    while (n_case--) {
        cin >> n;
        cout << n << " = ";

        for (i = 38; Fibonacci[i] > n; i--)
            ;

        while (i > -1) {
            if (n < Fibonacci[i])
                cout << "0";
            else
                cout << "1";
            n %= Fibonacci[i--];
        }
        cout << " (fib)\n";
    }
    return 0;
}