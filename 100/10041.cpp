/*
    中位數、排序
    時間複雜度: O(NlogN)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_testcase;
    cin >> n_testcase;
    while (n_testcase--) {
        int n, temp;
        cin >> n;
        vector<int> relative(n, 0);

        for (int i = 0; i < n; i++)
            cin >> relative[i];

        sort(relative.begin(), relative.end());

        int mid = relative.size() / 2;

        if (n & 1)
            mid = relative[mid];
        else
            mid = (relative[mid] + relative[mid - 1]) / 2;

        int ans = 0;

        for (const int& i : relative)
            ans += abs(i - mid);

        cout << ans << "\n";
    }
}