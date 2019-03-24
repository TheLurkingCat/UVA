/*
    天際線問題
    時間複雜度: O(N)
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int height[10001] = {};
    int i, l, h, r, end = 0;

    while (cin >> l >> h >> r) {
        // 每一個點只儲存該點最高高度
        for (i = l; i < r; i++)
            height[i] = max(height[i], h);
        // 紀錄最右邊座標
        end = max(end, r);
    }

    // 高度變換時就印出一組答案
    for (i = 1; i < end; i++)
        if (height[i] != height[i - 1])
            cout << i << " " << height[i] << " ";

    // 最後記得補上0
    cout << i << " 0\n";
    return 0;
}