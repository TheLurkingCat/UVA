/*
    連通塊數量
    時間複雜度: O(N^2)
*/
#include <iostream>
#include <vector>

using namespace std;

void DFS(int row, int column, vector<vector<char>> &field, const int &m, const int &n) {
    if (row < 0 || row >= m || column < 0 || column >= n || field[row][column] != '@')
        return;

    field[row][column] = '*';
    // 八個方向
    DFS(row + 1, column + 1, field, m, n);
    DFS(row + 1, column, field, m, n);
    DFS(row + 1, column - 1, field, m, n);
    DFS(row, column + 1, field, m, n);
    DFS(row, column - 1, field, m, n);
    DFS(row - 1, column + 1, field, m, n);
    DFS(row - 1, column, field, m, n);
    DFS(row - 1, column - 1, field, m, n);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, answer, m, n;
    while (cin >> m >> n && (m || n)) {
        vector<vector<char>> field(m, vector<char>(n));
        answer = 0;

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> field[i][j];

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (field[i][j] == '@') {
                    answer++;
                    DFS(i, j, field, m, n);  // 找到一個 @ 的時候 answer + 1 然後消去所有相連的 @
                }
        cout << answer << "\n";
    }
    return 0;
}