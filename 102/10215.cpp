/*
    數學題，記得加1E-9不然會WA
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    double L, W;
    while (cin >> L >> W) {
        cout << setprecision(3) << fixed << (L + W - sqrt(L * (L - W) + W * W)) / 6 + 1E-9;
        cout << " 0.000 " << min(L, W) / 2 + 1E-9 << "\n";
    }
}