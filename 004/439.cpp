/*
    廣度優先搜索 BFS
    時間複雜度: V = 64，E < 8 * V，O(V+E) = O(1)
*/
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
const int pos[8][2] = {-1, 2,
                       1, 2,
                       2, 1,
                       2, -1,
                       1, -2,
                       -1, -2,
                       -2, -1,
                       -2, 1};

int BFS(int x1, int x2, int y1, int y2) {
    int i, step, x, y;

    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<tuple<int, int, int>> bfs_queue;

    bfs_queue.push(make_tuple(x1, y1, 0));

    while (!bfs_queue.empty()) {
        tie(x, y, step) = bfs_queue.front();
        bfs_queue.pop();

        if (x == x2 && y == y2)
            return step;

        step++;
        // 每個位置騎士有八個新位置可以移動
        for (i = 0; i < 8; i++) {
            x1 = x + pos[i][0];
            y1 = y + pos[i][1];

            if (x1 < 0 || y1 < 0 || x1 > 7 || y1 > 7 || visited[x1][y1])
                continue;  // 超出邊界或是之前走過了

            if (x1 == x2 && y1 == y2)
                return step;

            visited[x1][y1] = true;
            bfs_queue.push(make_tuple(x1, y1, step));
        }
    }
    return -1;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char start[3], end[3];
    int x1, x2, y1, y2;

    while (cin >> start >> end) {
        x1 = start[0] - 'a';
        x2 = end[0] - 'a';
        y1 = start[1] - '1';
        y2 = end[1] - '1';
        cout << "To get from " << start << " to " << end << " takes " << BFS(x1, x2, y1, y2) << " knight moves.\n";
    }
}