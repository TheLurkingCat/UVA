/*
    關節點數量、DFS
    時間複雜度: O(V+E) = O(V) = O(N)
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> lowest_visit_time(100), visit_time(100);
vector<vector<int>> adjacency_list(100, vector<int>());

int N, step, ans;

void DFS(int parent, int current) {
    visit_time[current] = lowest_visit_time[current] = ++step;

    int child = 0, i;
    bool is_articulation_vertex = false;
    for (const int& j : adjacency_list[current])
        if (j != parent) {
            if (visit_time[j]) {
                lowest_visit_time[current] = min(lowest_visit_time[current], visit_time[j]);         // 這點之前看過了: back edge
            }                                                                                        // 判斷是之前還是現在遍歷時刻較低
            else {                                                                                   // 這點沒看過: tree edge
                child++;                                                                             // current 有新的子樹
                DFS(current, j);                                                                     // current 是 j 的祖先
                lowest_visit_time[current] = min(lowest_visit_time[current], lowest_visit_time[j]);  // 判斷是之前還是現在遍歷時刻較低
                if (lowest_visit_time[j] >= visit_time[current])                                     // 如果子孫和祖先沒有back edge
                    is_articulation_vertex = true;                                                   // current 就是關節點
            }
        }
    // 1. current 是樹根且有兩棵以上子樹
    // 2. current 的祖先和 current 的子孫沒有 back edge
    // 滿足兩者之一的話 current 就是關節點
    // cout << "Vertex " << current << " is an Articulation Vertex.\n";
    if (current == parent && child > 1)
        ans++;
    else if (current != parent && is_articulation_vertex)
        ans++;
}

inline void initial() {
    int from, to;
    string str;
    N++;

    for (auto&& row : adjacency_list)
        row.clear();
    fill(lowest_visit_time.begin(), lowest_visit_time.end(), 0);
    fill(visit_time.begin(), visit_time.end(), 0);

    step = ans = 0;
    // 建立鄰接表，這題 N = V > E
    // 使用鄰接矩陣會是 O(V^2) = O(N^2)
    // 使用鄰接表則會是 O(V+E) = O(N)
    // 輸入有點麻煩
    cin.ignore(1024, '\n');
    while (getline(cin, str)) {
        istringstream input(str);
        input >> from;
        if (!from)
            break;
        while (input >> to) {
            adjacency_list[from].push_back(to);
            adjacency_list[to].push_back(from);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (cin >> N && N) {
        initial();
        DFS(1, 1);  // 題目保證全部連通，隨便取一點都可以
        cout << ans << "\n";
    }
    return 0;
}