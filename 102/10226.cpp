/*
    字串排序、數量平均
*/
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_testcase;
    string tree;
    cin >> n_testcase;
    cin.ignore(1024, '\n');
    cin.ignore(1024, '\n');
    for (int i = 0; i < n_testcase; i++) {
        if (i)
            cout << "\n";
        map<string, double> forest;
        int total = 0;
        while (getline(cin, tree) and tree.length()) {
            forest[tree] += 100;
            ++total;
        }
        for (const auto &wood : forest)
            cout << wood.first << " " << setprecision(4) << fixed << wood.second / total << "\n";
    }
}