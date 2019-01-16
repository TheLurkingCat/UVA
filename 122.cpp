/*
    二元樹層次遍歷問題
    時間複雜度: O(NlogN) (排序)
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int number;
    string route;
};

// 定義兩個Node的大小，讓他由上到下、由左而右
bool cmp(Node a, Node b) {
    if (a.route.size() < b.route.size())
        return true;
    else if (a.route.size() == b.route.size())
        return a.route < b.route;
    else
        return false;
}

vector<Node> tree_nodes;
unordered_map<string, int> seen;

bool read_data() {
    seen.clear();
    tree_nodes.clear();
    bool is_end = false;
    char c;
    int x;
    string input, route;

    while (cin >> input && input != "()") {
        is_end = true;
        stringstream string_data(input);
        string_data >> c >> x >> c >> route;  // (11,LL) => (x,route
        route.pop_back();                     // 刪掉右括號
        tree_nodes.push_back(Node{x, route});
    }
    return is_end;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while (read_data()) {
        sort(tree_nodes.begin(), tree_nodes.end(), cmp);
        // 如果第一個不是root(有路徑)，就一定沒完成
        if (tree_nodes[0].route != "")
            cout << "not complete\n";
        else {
            bool is_complete = true;
            int i, total_nodes;
            string parent;
            seen[""] = 1;
            total_nodes = tree_nodes.size();
            // 按照順序迭代所有節點，如果上面沒有節點或是已經出現過一次了，也是沒完成
            for (i = 1; i < total_nodes; i++) {
                parent = tree_nodes[i].route.substr(0, tree_nodes[i].route.size() - 1);  // RRL 上方的節點必定是 RR，所以去掉最後一個字
                if (seen[parent] == 0 || seen[tree_nodes[i].route]) {
                    is_complete = false;
                    break;
                }
                seen[tree_nodes[i].route]++;
            }

            if (is_complete) {
                cout << tree_nodes.front().number;
                for (i = 1; i < total_nodes; i++)
                    cout << ' ' << tree_nodes[i].number;
                cout << '\n';
            } else
                cout << "not complete\n";
        }
    }
    return 0;
}