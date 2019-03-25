/*
    模擬
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_testcase;
    cin >> n_testcase;
    while (n_testcase--) {
        int sum = 0, day, n, m;
        cin >> day >> n;
        vector<bool> calendar(day, false);

        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = m - 1; j < day; j += m)
                calendar[j] = true;
        }

        for (int i = 0; i < day; i++)
            if (calendar[i] && i % 7 < 5)
                sum++;

        cout << sum << "\n";
    }
    return 0;
}