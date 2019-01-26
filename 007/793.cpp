/*
    並查集
    時間複雜度(每個操作最糟): O(logN)
    時間複雜度(平均): O(1)
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int get_parent(const int& vertex, vector<int>& parents) {
    if (parents[vertex] == vertex)
        return vertex;
    parents[vertex] = get_parent(parents[vertex], parents);  // 路徑壓縮
    return parents[vertex];
}

bool same(const int& x, const int& y, vector<int>& parents) {
    return get_parent(x, parents) == get_parent(y, parents);  // 有共同祖先就是同一個集合
}

void rank_union(const int& x, const int& y, vector<int>& rank, vector<int>& parents) {
    int x_parent = get_parent(x, parents), y_parent = get_parent(y, parents);
    if (rank[x_parent] > rank[y_parent])
        parents[y_parent] = x_parent;  // 將小集合合併到大集合
    else {
        parents[x_parent] = y_parent;          // 將小集合合併到大集合
        if (rank[x_parent] == rank[y_parent])  // 集合大小相同就合併之後 rank + 1
            rank[y_parent]++;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, n_case, n_computer, computer_1, computer_2, correct, wrong;
    char operation;
    string line;

    cin >> n_case;
    while (n_case--) {
        cin >> n_computer;
        cin.ignore(1024, '\n');

        n_computer++;
        correct = wrong = 0;
        vector<int> rank(n_computer, 0), parents;
        // 一開始每台電腦都自己一個集合
        parents.reserve(n_computer);
        for (i = 0; i < n_computer; i++)
            parents.push_back(i);

        while (getline(cin, line) && line.length()) {
            istringstream input(line);
            input >> operation >> computer_1 >> computer_2;

            if (operation == 'c')  // 合併
                rank_union(computer_1, computer_2, rank, parents);
            else if (same(computer_1, computer_2, parents))
                correct++;
            else
                wrong++;
        }

        cout << correct << "," << wrong << "\n";
        if (n_case)
            cout << "\n";
    }
}