/*
    數學
    時間複雜度: O(1)
*/
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    char c;
    double hour_angle, minute_angle, angle;

    while (cin >> n >> c >> m && (n || m)) {
        hour_angle = n * 30 + m * 0.5;
        minute_angle = m * 6;
        angle = fabs(hour_angle - minute_angle);
        if (angle > 180)
            angle = 360 - angle;
        cout << setprecision(3) << fixed << angle << "\n";
    }
    return 0;
}