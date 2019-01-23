/*
    最長遞增子序列 (LIS)
    時間複雜度: O(N^2)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct brick {
    int x;
    int y;
    int z;
    int max_height;  // 以這塊磚塊當底時的最大高度
    bool operator>(const brick& other) const {
        return x > other.x && y > other.y;  // 嚴格遞增
    }
};

bool compare(const brick& a, const brick& b) {
    // 先照長再照寬排
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, n, x, y, z, answer, n_case = 0;

    while (cin >> n && n) {
        vector<brick> bricks;
        answer = 0x80000000;  // -2147483648

        for (i = 0; i < n; i++) {
            cin >> x >> y >> z;
            // 每個磚塊都可以轉
            bricks.push_back(brick{max(x, y), min(x, y), z, z});
            bricks.push_back(brick{max(x, z), min(x, z), y, y});
            bricks.push_back(brick{max(y, z), min(y, z), x, x});
        }

        sort(bricks.begin(), bricks.end(), compare);
        n *= 3;  // 放了三倍的磚塊進去

        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++)
                if (bricks[i] > bricks[j])
                    // 如果 j 可以放在 i 上，那以 i 為底的最大高度就是以 j 為底的最大高度加上 i 的高度
                    bricks[i].max_height = max(bricks[i].max_height, bricks[j].max_height + bricks[i].z);
            answer = max(answer, bricks[i].max_height);
        }

        cout << "Case " << ++n_case << ": maximum height = " << answer << "\n";
    }
}