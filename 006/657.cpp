/*
    區域連通塊
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void DFS(const int i, const int j, const int& row, const int& column, vector<vector<char>>& field) {
    // 清掉所有相鄰的 X
    if (i < 0 || i >= row || j < 0 || j >= column || field[i][j] != 'X')
        return;

    field[i][j] = '*';

    DFS(i + 1, j, row, column, field);
    DFS(i - 1, j, row, column, field);
    DFS(i, j + 1, row, column, field);
    DFS(i, j - 1, row, column, field);
}

int DFS(const int i, const int j, const int& row, const int& column, vector<vector<char>>& field, int& ans) {
    // 在地圖上找 X
    if (i < 0 || i >= row || j < 0 || j >= column || field[i][j] == '.')
        return 0;

    if (field[i][j] == 'X') {
        ans++;
        DFS(i, j, row, column, field);
    }

    field[i][j] = '.';

    DFS(i + 1, j, row, column, field, ans);
    DFS(i - 1, j, row, column, field, ans);
    DFS(i, j + 1, row, column, field, ans);
    DFS(i, j - 1, row, column, field, ans);
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int case_num = 1, row, column, i, j, k;

    while (cin >> column >> row && row) {
        vector<vector<char>> field(row, vector<char>(column));
        vector<int> answers;
        k = 0;

        for (i = 0; i < row; i++)
            for (j = 0; j < column; j++)
                cin >> field[i][j];

        for (i = 0; i < row; i++)
            for (j = 0; j < column; j++)
                if (field[i][j] == '*' || field[i][j] == 'X') {
                    answers.push_back(0);
                    DFS(i, j, row, column, field, answers[k++]);
                }

        sort(answers.begin(), answers.end());

        cout << "Throw " << case_num++ << "\n"
             << answers[0];
        for (i = 1; i < k; i++)
            cout << " " << answers[i];
        cout << "\n\n";
    }
    return 0;
}