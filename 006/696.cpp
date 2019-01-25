/*
    N騎士問題
    時間複雜度: O(1)
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, large, small, div, mod;
    while (cin >> n >> m && n) {
        if (n > m) {
            large = n;
            small = m;
        } else {
            large = m;
            small = n;
        }

        if (small == 1)
            cout << large;  // 一條線放滿
        else if (small == 2) {
            div = large / 4;  // 把 2 * large 拆成很多 2 * 4 的狀態
            mod = large % 4;
            cout << div * 4 + (mod > 1 ? 4 : 2 * mod);
        } else
            cout << (large * small + 1) / 2;  // 交錯放

        cout << " knights may be placed on a " << n << " row " << m << " column board.\n";
    }
}