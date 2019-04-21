/*
    對答案二分搜
    時間複雜度: O(logD)
*/
#include <iostream>

using namespace std;

inline long long calculate_sum(const long long& start, const long long& x) {
    return (x * (x + 1) - start * (start - 1)) / 2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n_day, start;
    while (cin >> start >> n_day) {
        long long left = 1, right = 1E8, mid = 5E7;
        do {
            if (calculate_sum(start, mid) < n_day)
                left = mid + 1;
            else
                right = mid;
            mid = (left + right - 1) / 2;
        } while (left < right);
        cout << right << "\n";
    }
}