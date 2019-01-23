/*
    集合
    時間複雜度: O(NlogN)
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> set_a, set_b;
    string line;
    int temp, pos_a, pos_b, size_a, size_b;
    bool is_only_in_a, is_only_in_b, is_a_b_intersect;

    while (getline(cin, line)) {
        istringstream input_a(line);
        while (input_a >> temp)
            set_a.push_back(temp);
        getline(cin, line);
        istringstream input_b(line);
        while (input_b >> temp)
            set_b.push_back(temp);

        size_a = set_a.size();
        size_b = set_b.size();
        is_only_in_a = is_only_in_b = is_a_b_intersect = false;
        pos_a = pos_b = 0;

        sort(set_a.begin(), set_a.end());
        sort(set_b.begin(), set_b.end());
        set_a.push_back(0x7fffffff);
        set_b.push_back(0x7fffffff);

        while (pos_a < size_a || pos_b < size_b)
            if (set_a[pos_a] < set_b[pos_b]) {
                pos_a++;
                is_only_in_a = true;
            } else if (set_a[pos_a] > set_b[pos_b]) {
                pos_b++;
                is_only_in_b = true;
            } else {
                pos_a++;
                pos_b++;
                is_a_b_intersect = true;
            }

        if (is_a_b_intersect)
            if (is_only_in_b)
                if (is_only_in_a)
                    cout << "I'm confused!\n";
                else
                    cout << "A is a proper subset of B\n";
            else if (is_only_in_a)
                cout << "B is a proper subset of A\n";
            else
                cout << "A equals B\n";
        else
            cout << "A and B are disjoint\n";

        set_a.clear();
        set_b.clear();
    }
}