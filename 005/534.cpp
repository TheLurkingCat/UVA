/*
    最小瓶頸路徑長 (經過的最長路長度最短)
    時間複雜度: O(N^3)
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, k, n, Scenario = 1;
    vector<pair<double, double>> points(200);
    vector<vector<double>> dist(200, vector<double>(200));

    while (cin >> n && n) {
        for (i = 0; i < n; i++)
            cin >> points[i].first >> points[i].second;

        // 距離矩陣
        for (i = 0; i < n; i++)
            for (j = 0; j < i; j++)
                dist[j][i] = dist[i][j] = hypot(points[i].first - points[j].first, points[i].second - points[j].second);

        // 弗洛伊德演算法 (Floyd-Warshall)
        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));  // 修改成找 兩者最長路 和 原路 長度較短者

        cout << "Scenario #" << Scenario++ << "\nFrog Distance = " << setprecision(3) << fixed << dist[0][1] << "\n\n";
    }
    return 0;
}