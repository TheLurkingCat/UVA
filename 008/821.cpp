/*
    所有最短路徑平均長度(Floyd-Warshall)
    時間複雜度: O(N^3)
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int from, to, n, i, j, k, sum, n_case = 1;
    while (cin >> from >> to && from) {
        sum = 0;
        vector<vector<int>> distance(101, vector<int>(101, 0x3fffffff));
        n = max(from, to);
        distance[from][to] = 1;

        while (cin >> from >> to && from) {
            distance[from][to] = 1;
            n = max(n, max(from, to));
        }

        n++;

        for (k = 1; k < n; k++)
            for (i = 1; i < n; i++)
                for (j = 1; j < n; j++)
                    if (i != j)
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
        n = 0;
        for (const vector<int>& row : distance)
            for (const int& dist : row)
                if (dist != 0x3fffffff) {
                    sum += dist;
                    n++;
                }
        cout << "Case " << n_case++ << ": average length between pages = " << setprecision(3) << fixed << double(sum) / n << " clicks\n";
    }
}