/*
    數學
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    unsigned long long n;
    while (cin >> n)
        cout << (3 * n * n + 3) / 2 + 3 * n - 9 << "\n";  // ((n + 1) / 2) * ((n + 1) / 2) * 6 - 9
}