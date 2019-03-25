/*
    絕對值
*/
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n, m;
    while (cin >> n >> m)
        cout << abs(m - n) << "\n";
    return 0;
}