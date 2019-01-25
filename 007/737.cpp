/*
    計算幾何
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x, y, z, d, x_left, y_left, z_left, x_right, y_right, z_right;
    while (cin >> n && n--) {
        cin >> x >> y >> z >> d;

        x_left = x;
        y_left = y;
        z_left = z;

        x_right = x + d;
        y_right = y + d;
        z_right = z + d;

        while (n--) {
            cin >> x >> y >> z >> d;

            x_left = max(x_left, x);
            y_left = max(y_left, y);
            z_left = max(z_left, z);

            x_right = min(x_right, x + d);
            y_right = min(y_right, y + d);
            z_right = min(z_right, z + d);
        }

        cout << max(0, (x_right - x_left) * (y_right - y_left) * (z_right - z_left)) << "\n";  // 體積不能為負數
    }
    return 0;
}