/*
    約瑟夫問題、建表、離線計算
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k, ans[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

    while (cin >> k && k)
        cout << ans[k] << "\n";
    return 0;
}