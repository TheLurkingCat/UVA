/*
    卡塔蘭數、建表
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bool flag = false;
    int n, ans[11] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};
    while (cin >> n) {
        if (flag)
            cout << "\n";
        cout << ans[n] << "\n";
        flag = true;
    }
}