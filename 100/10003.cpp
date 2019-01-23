#include <algorithm>
#include <iostream>

using namespace std;

int length;
int cut[50], cost[51][51];

int dp(int x, int y) {
    if (cost[x][y] > -1) {
        return cost[x][y];
    }

    int ans = 2147483647, i;

    for (i = x + 1; i < y; i++) {
        ans = min(ans, dp(x, i) + dp(i, y));
    }

    cost[x][y] = ans + cut[y] - cut[x];

    return cost[x][y];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int i, n, j;
    while (cin >> length && length) {
        for (i = 0; i < 51; i++) {
            for (j = i; j < 51; j++)
                if (i + 1 == j) {
                    cost[i][j] = 0;
                } else {
                    cost[i][j] = -1;
                }
        }

        cin >> n;

        cut[0] = 0;
        cut[n + 1] = length;

        for (i = 1; i <= n; i++) {
            cin >> cut[i];
        }

        cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";
    }
    return 0;
}