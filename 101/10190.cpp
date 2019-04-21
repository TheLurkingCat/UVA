#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m) {
        if (m < 2 or n < m) {
            cout << "Boring!\n";
            continue;
        }
        vector<int> sequence;
        while (n % m == 0) {
            sequence.push_back(n);
            n /= m;
        }
        if (n == 1) {
            for (const int &i : sequence)
                cout << i << " ";
            cout << "1\n";
        } else
            cout << "Boring!\n";
    }
}
