/*
    數學題
*/
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    double x, y;
    while (cin >> x >> y) {
        vector<pair<double, double>> points;
        points.emplace_back(x, y);
        cin >> x >> y;
        points.emplace_back(x, y);
        for (int i = 0; i < 2; i++) {
            cin >> x >> y;
            if (make_pair(x, y) == points[0])
                swap(points[0], points[1]);
            else if (make_pair(x, y) != points[1])
                points.emplace_back(x, y);
        }
        cout << setprecision(3) << fixed << points[0].first + points[2].first - points[1].first << " "
             << points[0].second + points[2].second - points[1].second << "\n";
    }
}