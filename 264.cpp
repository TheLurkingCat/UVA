/*
    分析題
    時間複雜度: O(N)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, i, line, total, pos;

    while (cin >> n) {
        total = 0;

        for (i = 1; total < n; i++)
            total += i;

        line = i - 1;     // n 在第 i - 1 斜排
        pos = total - n;  // n 是第 i - 1 斜排的倒數第 total - n + 1 個

        cout << "TERM " << n << " IS ";

        if (line & 1)
            cout << pos + 1 << '/' << line - pos << '\n';
        else
            cout << line - pos << '/' << pos + 1 << '\n';
    }
    return 0;
}