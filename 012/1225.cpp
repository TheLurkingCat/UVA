/*
    建表
    時間複雜度: O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<vector<int>> table;
    table.reserve(10000);
    table.push_back(vector<int>(10, 0));  // 沒有 0 所以把它拿來初始化
    int n;
    cin >> n;

    for (int i = 1; i < 10000; i++) {
        auto temp = table.back();  // 每一項的值是以上一項為基礎
        int j = i;
        while (j) {
            temp[j % 10]++;
            j /= 10;
        }
        table.push_back(temp);
    }

    while (n--) {
        int m;
        cin >> m;
        for (int i = 0; i < 9; i++)
            cout << table[m][i] << " ";
        cout << table[m][9] << "\n";
    }

    return 0;
}