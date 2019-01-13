#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int height[10001] = {};
    int i, l, h, r, end = 0;
    while (cin >> l >> h >> r) {
        for (i = l; i < r; i++) {
            height[i] = max(height[i], h);
        }
        end = max(end, r);
    }
    for (i = 1; i < end; i++) {
        if (height[i] != height[i - 1])
            cout << i << ' ' << height[i] << ' ';
    }
    cout << i << " 0\n";
    return 0;
}