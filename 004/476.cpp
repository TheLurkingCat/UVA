/*
    計算幾何
    時間複雜度: O(N)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<pair<pair<double, double>, pair<double, double>>> rectangle(10);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char c;
    int figure_num, count = 0, point_num = 1;
    double x, y;
    bool flag;

    while (cin >> c && c != '*') {
        cin >> rectangle[count].first.first >> rectangle[count].first.second >> rectangle[count].second.first >> rectangle[count].second.second;
        count++;
    }

    while (cin >> x >> y) {
        if (x == 9999.9 && y == 9999.9)
            break;

        flag = true;

        for (figure_num = 0; figure_num < count; figure_num++)
            // 注意邊界不算
            if (rectangle[figure_num].first.first < x && rectangle[figure_num].second.first > x && rectangle[figure_num].second.second < y && rectangle[figure_num].first.second > y) {
                flag = false;
                cout << "Point " << point_num << " is contained in figure " << figure_num + 1 << "\n";
            }

        if (flag)
            cout << "Point " << point_num << " is not contained in any figure\n";

        point_num++;
    }

    return 0;
}