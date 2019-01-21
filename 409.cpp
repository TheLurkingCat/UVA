/*
    字串比對
    時間複雜度: O((K+E)N) (N是字串長度，E是字串數目，K是關鍵字數)
*/
#include <algorithm>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool compare(const pair<string, int> &a,
             const pair<string, int> &b) {
    return a.second > b.second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, k, e, count, largest, set = 1;
    string input;
    regex pattern("[^A-Za-z]");
    unordered_map<string, int> seen;
    vector<pair<string, int>> excuses;
    vector<string> keyword;

    while (cin >> k >> e) {
        for (i = 0; i < k; i++) {
            cin >> input;
            keyword.push_back(input);
        }

        cin.ignore(1024, '\n');  // 多的換行

        for (i = 0; i < e; i++) {
            count = 0;
            getline(cin, input);
            excuses.push_back(make_pair(input, 0));

            transform(input.begin(), input.end(), input.begin(), ::tolower);  // 換成全部小寫
            istringstream word(regex_replace(input, pattern, " "));           // 把全部不是英文換成空白

            while (word >> input)
                seen[input] += 1;

            for (const string &j : keyword)
                count += seen[j];

            excuses[i].second = count;
            seen.clear();
        }

        sort(excuses.begin(), excuses.end(), compare);  // 按照藉口次數大到小排序
        largest = excuses[0].second;

        cout << "Excuse Set #" << set++ << "\n";

        for (const auto &excuse : excuses) {
            if (excuse.second != largest)
                break;
            cout << excuse.first << "\n";
        }
        cout << "\n";
        excuses.clear();
        keyword.clear();
    }
    return 0;
}