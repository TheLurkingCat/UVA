/*
    模擬
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, cnt = 0;
    char c;
    while (cin >> n >> m and n) {
        if (cnt)
            cout << "\n";
        cout << "Field #" << ++cnt << ":\n";
        cin.ignore(1024, '\n');
        vector<vector<char>> map(n, vector<char>(m, '0'));
        for (int row = 0; row < n; row++) {
            int column = 0;
            while ((c = cin.get()) != '\n') {
                if (c == '*') {
                    map[row][column] = '*';
                    if (column != 0) {
                        if (map[row][column - 1] >= '0')
                            ++map[row][column - 1];
                        if (row != 0)
                            if (map[row - 1][column - 1] >= '0')
                                ++map[row - 1][column - 1];
                        if (row != n - 1)
                            if (map[row + 1][column - 1] >= '0')
                                ++map[row + 1][column - 1];
                    }
                    if (row != 0)
                        if (map[row - 1][column] >= '0')
                            ++map[row - 1][column];
                    if (row != n - 1)
                        if (map[row + 1][column] >= '0')
                            ++map[row + 1][column];
                    if (column != m - 1) {
                        if (map[row][column + 1] >= '0')
                            ++map[row][column + 1];
                        if (row != 0)
                            if (map[row - 1][column + 1] >= '0')
                                ++map[row - 1][column + 1];
                        if (row < n - 1)
                            if (map[row + 1][column + 1] >= '0')
                                ++map[row + 1][column + 1];
                    }
                }
                column++;
            }
        }
        for (const auto& i : map) {
            for (const auto& c : i)
                cout << c;
            cout << "\n";
        }
    }
}