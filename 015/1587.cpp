/*
    立方體定義
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct pallets {
    int x, y;
    pallets(int n, int m) {
        x = min(n, m);
        y = max(n, m);
    }
    bool operator<(const pallets& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int x, y;
    bool possible;

    while (cin >> x >> y) {
        vector<pallets> plane;
        plane.reserve(6);
        plane.push_back(pallets(x, y));
        possible = true;

        for (int i = 0; i < 5; i++) {
            cin >> x >> y;
            plane.push_back(pallets(x, y));
        }

        sort(plane.begin(), plane.end());

        for (int i = 0; i < 6; i += 2)
            if (plane[i].x != plane[i + 1].x || plane[i].y != plane[i + 1].y)
                possible = false;  // 對面相等

        if (plane[0].x != plane[2].x || plane[0].y != plane[4].x || plane[2].y != plane[4].y)
            possible = false;  // 臨邊相等

        if (possible)
            cout << "POSSIBLE\n";
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}