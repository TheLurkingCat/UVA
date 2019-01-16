/*
    模擬題，照做就好
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // 紀錄曾經掉下去的地方
    int maps[55][55] = {};
    // 四個方向
    int position[4][2] = {0, 1,
                          1, 0,
                          0, -1,
                          -1, 0};

    int i, n, m, x, x_next, y, y_next, towards[128];
    char start, steps[101], face[5] = "NESW";

    towards['N'] = 0;
    towards['E'] = 1;
    towards['S'] = 2;
    towards['W'] = 3;

    cin >> n >> m;
    while (cin >> x >> y >> start) {
        cin >> steps;
        int face_now = towards[start], flag = 0;
        // 模擬移動
        for (i = 0; steps[i]; i++) {
            // 左轉
            if (steps[i] == 'L')
                face_now = (face_now + 3) % 4;
            // 右轉
            else if (steps[i] == 'R')
                face_now = (face_now + 1) % 4;
            // 往前走
            else {
                x_next = x + position[face_now][0];
                y_next = y + position[face_now][1];
                // 判斷這裡之前是否有機器人掉下去過了
                if (x_next < 0 || x_next > n || y_next < 0 || y_next > m) {
                    if (maps[x][y])
                        continue;
                    maps[x][y] = 1;
                    flag = 1;
                    break;
                }
                x = x_next;
                y = y_next;
            }
        }

        cout << x << ' ' << y << ' ' << face[face_now];
        if (flag)
            cout << " LOST";
        cout << "\n";
    }

    return 0;
}