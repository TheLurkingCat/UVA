/*
    排序
    時間複雜度: O(NlogN)
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<string, int>& a,
             const pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, number;
    string order;
    vector<pair<string, int>> data_array;

    while (cin >> n)
        while (n--) {
            cin.ignore(1024, '\n');
            cin.ignore(1024, '\n');
            getline(cin, order);
            istringstream order_input(order);

            while (order_input >> number)
                data_array.push_back(make_pair(string(), number));

            for (auto&& i : data_array)
                cin >> i.first;

            sort(data_array.begin(), data_array.end(), compare);  // 照 number 先排序

            for (const auto& i : data_array)
                cout << i.first << "\n";

            data_array.clear();

            if (n)
                cout << "\n";
        }
}