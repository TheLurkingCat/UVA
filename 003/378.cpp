/*
    求兩直線交點
    時間複雜度: O(1)
*/
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cout << "INTERSECTING LINES OUTPUT\n";

    int n_testcase;
    int x1, x2, x3, x4, y1, y2, y3, y4;
    int a1, a2, b1, b2, c1, c2;
    int delta, delta_x, delta_y;

    cin >> n_testcase;
    while (n_testcase--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        // 換成向量(a1, b1) (a2, b2)
        a1 = x2 - x1;
        b1 = y2 - y1;
        a2 = x4 - x3;
        b2 = y4 - y3;

        // 法向量求直線
        // b1 * x - a1 * y = c1
        // b2 * x - a2 * y = c2
        c1 = b1 * x1 - a1 * y1;
        c2 = b2 * x3 - a2 * y3;

        // 克拉瑪公式解
        // __           __
        // | b1 -a1 | c1 |
        // | b2 -a2 | c2 |
        // --            --
        delta = -b1 * a2 + a1 * b2;
        delta_x = -c1 * a2 + c2 * a1;
        delta_y = b1 * c2 - b2 * c1;

        if (delta)
            cout << "POINT " << setprecision(2) << fixed << double(delta_x) / delta << " " << setprecision(2) << fixed << double(delta_y) / delta << "\n";
        else {
            if (delta_x || delta_y)
                cout << "NONE\n";  // 無實數解
            else
                cout << "LINE\n";  // 無限多解
        }
    }
    cout << "END OF OUTPUT\n";
    return 0;
}