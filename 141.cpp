/*
    模擬
    時間複雜度: O(N^3) (2N筆輸入，每筆花費4N^2旋轉)
*/
#include <bitset>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, k, t, m, n, x, y, move, winner_id;
    bitset<2500> temp, board;
    char operator_;

    while (cin >> n && n) {
        unordered_map<bitset<2500>, bool> seen;
        m = 2 * n;
        winner_id = 0;  // 一開始沒人贏

        for (i = 0; i < m; i++) {
            cin >> x >> y >> operator_;
            x--;
            y--;
            // 題目定義的操作
            if (operator_ == '+')
                board[x * n + y] = 1;
            else
                board[x * n + y] = 0;
            // 盤面出現過了，結束
            if (seen[board]) {
                i++;
                winner_id = (i & 1) + 1;  // 誰贏
                move = i;                 // 在第幾局贏
                break;
            }
            // 四個方向都要記錄，最後要轉回原本的樣子
            for (t = 0; t < 4; t++) {
                seen[board] = 1;
                for (j = 0; j < n; j++)
                    for (k = 0; k < n; k++)
                        temp[(k + 1) * n - j - 1] = board[j * n + k];
                board = temp;
            }
        }
        // 分出勝負之後把剩下資料讀完
        for (; i < m; i++) {
            cin >> x >> y >> operator_;
        }

        if (winner_id)
            cout << "Player " << winner_id << " wins on move " << move << '\n';
        else
            cout << "Draw\n";

        // 清空盤面
        board.reset();
    }
    return 0;
}