/*
    連通塊大小
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(const int x, const int y, const int& row, const int& column, vector<string>& field, int& ans) {
    if (x < 0 || x >= row || y < 0 || y >= column || field[x][y] == '1')
        return;

    field[x][y] = '1';
    ans++;

    DFS(x + 1, y, row, column, field, ans);
    DFS(x - 1, y, row, column, field, ans);
    DFS(x, y + 1, row, column, field, ans);
    DFS(x, y - 1, row, column, field, ans);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_case, i, j, ans, row, column;
    string k;
    vector<string> field;

    cin >> n_case;
    while (n_case--) {
        cin >> i >> j;
        cin.ignore(1024, '\n');

        ans = 0;

        while (getline(cin, k) && k[0])
            field.push_back(k);

        row = field.size();
        column = field[0].length();

        DFS(i - 1, j - 1, row, column, field, ans);

        cout << ans << "\n";

        if (n_case)
            cout << "\n";

        field.clear();
    }
}