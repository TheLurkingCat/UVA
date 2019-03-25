/*
    陣列運用
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_testcase;
    char c;
    cin >> n_testcase;
    cin.ignore(1024, '\n');

    while (n_testcase--) {
        int count[26] = {};
        while ((c = cin.get()) != '\n')
            ++count[c - 65];

        int ans = min(0x7fffffff, count[12]);
        ans = min(ans, count[0] / 3);
        ans = min(ans, count[17] / 2);
        ans = min(ans, count[6]);
        ans = min(ans, count[19]);
        ans = min(ans, count[8]);
        cout << ans << "\n";
    }
    return 0;
}
