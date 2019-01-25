/*
    三維迷宮、BFS
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int l, r, c, level, column, row, step;
    tuple<int, int, int> exit_position;

    while (cin >> l >> r >> c && l) {
        queue<pair<tuple<int, int, int>, int>> bfs_queue;
        vector<vector<vector<char>>> maze(l, vector<vector<char>>(r, vector<char>(c)));

        for (level = 0; level < l; level++)
            for (row = 0; row < r; row++)
                for (column = 0; column < c; column++) {
                    cin >> maze[level][row][column];
                    if (maze[level][row][column] == 'S')
                        bfs_queue.push(make_pair(make_tuple(level, row, column), 0));
                    else if (maze[level][row][column] == 'E')
                        exit_position = make_tuple(level, row, column);
                }

        while (!bfs_queue.empty()) {
            step = bfs_queue.front().second;

            if (exit_position == bfs_queue.front().first)
                break;
            tie(level, row, column) = bfs_queue.front().first;
            bfs_queue.pop();

            if (level < 0 || level >= l || row < 0 || row >= r || column < 0 || column >= c || maze[level][row][column] == '#')
                continue;

            maze[level][row][column] = '#';

            bfs_queue.push(make_pair(make_tuple(level + 1, row, column), step + 1));
            bfs_queue.push(make_pair(make_tuple(level - 1, row, column), step + 1));
            bfs_queue.push(make_pair(make_tuple(level, row + 1, column), step + 1));
            bfs_queue.push(make_pair(make_tuple(level, row - 1, column), step + 1));
            bfs_queue.push(make_pair(make_tuple(level, row, column + 1), step + 1));
            bfs_queue.push(make_pair(make_tuple(level, row, column - 1), step + 1));
        }

        if (bfs_queue.empty())
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << step << " minute(s).\n";
    }
    return 0;
}