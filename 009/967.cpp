/*
    建表、二分搜
    時間複雜度: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> circular_prime{113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int left, right;

    while (cin >> left >> right) {
        // 二分搜找位置需要最多 6 * 2 = 12次
        vector<int>::iterator&& lower = lower_bound(circular_prime.begin(), circular_prime.end(), left);
        vector<int>::iterator&& upper = lower_bound(circular_prime.begin(), circular_prime.end(), right + 1);
        int&& ans = distance(lower, upper);

        if (ans == 0)
            cout << "No Circular Primes.\n";
        else if (ans == 1)
            cout << "1 Circular Prime.\n";
        else
            cout << ans << " Circular Primes.\n";
    }
    return 0;
}