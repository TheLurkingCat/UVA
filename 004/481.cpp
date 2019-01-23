/*
    最長遞增子序列
    時間複雜度: O(NlogN)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> sequence, LIS, pos(1, 0);
    sequence.reserve(500000);

    int i, n, LIS_length;

    while (cin >> i)
        sequence.push_back(i);

    n = sequence.size();
    pos.reserve(n);
    LIS.reserve(n);

    LIS.push_back(sequence[0]);

    // 這裡只能算出 LIS 長度和 pos 資料
    for (i = 1; i < n; i++) {
        if (sequence[i] > LIS.back()) {
            pos.push_back(LIS.size());
            LIS.push_back(sequence[i]);  // sequence[i] 比全部都大
        } else {
            vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), sequence[i]);  // 找到大於 sequence[i] 的最小元素
            *it = sequence[i];
            pos.push_back(distance(LIS.begin(), it));
        }
    }

    LIS_length = LIS.size();
    cout << LIS_length-- << "\n-\n";

    for (i = n - 1; i > -1; i--)
        if (pos[i] == LIS_length)
            LIS[LIS_length--] = sequence[i];  // 真正的 LIS 要用長度和 pos 算

    for (const int& i : LIS)
        cout << i << "\n";

    return 0;
}