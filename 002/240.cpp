/*
    R元的霍夫曼編碼
    時間複雜度: O(N)
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    set<char> characters;
    int weight;

    bool operator<(const Node &other) const {
        if (weight != other.weight)
            return weight > other.weight;
        return *characters.begin() > *other.characters.begin();
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, r, n, count = 1, weighted_sum, total_chars, frequency[26];
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char number[] = "0123456789";

    while (cin >> r && r) {
        cin >> n;
        weighted_sum = total_chars = 0;
        priority_queue<Node> build_huffman_tree;
        unordered_map<char, string> code;

        for (i = 0; i < n; i++) {
            cin >> frequency[i];
            total_chars += frequency[i];
            build_huffman_tree.push(Node{{alphabet[i]}, frequency[i]});
        }
        // 注意 i == build_huffman_tree.size()
        // R大於2時，如果字不夠就要加假想字
        if (r > 2)
            while ((i % (r - 1)) != 1) {
                build_huffman_tree.push(Node{{']'}, 0});  // 加的字要比Z大
                i++;
            }

        // 建構霍夫曼編碼
        while (i > 1) {
            Node new_combination = {{}, 0};
            // 依次取最接近的 r 個一組
            for (j = 0; j < r; j++) {
                Node now = build_huffman_tree.top();
                build_huffman_tree.pop();
                i--;
                // C++11 range based，[PYTHON] for x in now.characters:
                for (const char &c : now.characters) {
                    code[c] += number[j];
                    new_combination.characters.insert(c);  // 新編號加入舊編號，注意: 這裡用 set 維持字典序由小到大
                }
                new_combination.weight += now.weight;  // 新權重是 r 個權重和
            }
            build_huffman_tree.push(new_combination);
            i++;
        }

        for (i = 0; i < n; i++)
            weighted_sum += frequency[i] * code[alphabet[i]].size();

        cout << "Set " << count++ << "; average length " << setprecision(2) << fixed << double(weighted_sum) / total_chars << "\n";

        for (i = 0; i < n; i++) {
            reverse(code[alphabet[i]].begin(), code[alphabet[i]].end());
            cout << "    " << alphabet[i] << ": " << code[alphabet[i]] << "\n";
        }
        cout << "\n";
    }

    return 0;
}