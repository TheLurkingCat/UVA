/*
    一筆畫 (尤拉環)
    時間複雜度: O(V+E)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

vector<vector<pair<int, int>>> adjacency_list(2000);
vector<int> path;
vector<bool> visited(2000);

void DFS(int x) {
    // 隨便繞圈圈
    for (const pair<int, int> &edge : adjacency_list[x])
        if (!visited[edge.second]) {
            visited[edge.second] = true;
            DFS(edge.first);
            path.push_back(edge.second);
        }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, x, y, z, odd_edges, start_point;
    path.reserve(2000);
    while (cin >> x >> y && x) {
        // 建立相鄰表
        start_point = min(x, y);
        for (auto &&edges : adjacency_list)
            edges.clear();
        cin >> z;
        adjacency_list[x].push_back(make_pair(y, z));
        adjacency_list[y].push_back(make_pair(x, z));
        while (cin >> x >> y && x) {
            cin >> z;
            adjacency_list[x].push_back(make_pair(y, z));
            adjacency_list[y].push_back(make_pair(x, z));
        }

        odd_edges = 0;
        // 一筆畫不能有頂點有奇數邊(或2個奇數邊)
        for (const vector<pair<int, int>> &edges : adjacency_list)
            if (edges.size() & 1)
                odd_edges++;

        if (odd_edges != 0)
            cout << "Round trip does not exist.\n\n";
        else {
            for (auto &&edges : adjacency_list)
                sort(edges.begin(), edges.end(), compare);  //街道編號要先排序

            path.clear();
            fill(visited.begin(), visited.end(), false);

            DFS(start_point);

            for (i = path.size() - 1; i > 0; i--)
                cout << path[i] << " ";
            cout << path[0] << "\n\n";
        }
    }
    return 0;
}