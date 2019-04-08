/*
    中位數
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while ((cin >> n)) {
        vector<int> number(n, 0);
        unordered_map<int, int> counter;

        for (int i = 0; i < n; i++) {
            cin >> number[i];
            counter[number[i]]++;
        }

        sort(number.begin(), number.end());

        int mid = (number.size() - 1) / 2;

        if (number.size() & 1)
            cout << number[mid] << " " << counter[number[mid]] << " 1\n";
        else {
            int temp = 0;
            for (int i = number[mid]; i <= number[mid + 1]; i++)
                temp += counter[i];
            cout << number[mid] << " " << temp << " " << number[mid + 1] - number[mid] + 1 << "\n";
        }
    }
}