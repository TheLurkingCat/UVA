/*
    氣泡排序交換次數
    時間複雜度: O(N^2)
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, n_testcase, n_car, cars[50], ans;
    cin >> n_testcase;

    while (n_testcase--) {
        ans = 0;
        cin >> n_car;

        for (i = 0; i < n_car; i++) {
            cin >> cars[i];
        }

        for (i = 0; i < n_car - 1; i++)
            for (j = 0; j < n_car - i - 1; j++)
                if (cars[j] > cars[j + 1]) {
                    swap(cars[j], cars[j + 1]);
                    ans++;
                }

        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
}