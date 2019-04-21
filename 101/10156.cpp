/*
    模擬，注意輸出格式
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class position {
   public:
    int x, y;
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int row, column, n_turtles, move;

    while (cin >> row >> column >> n_turtles >> move) {
        unordered_map<int, position> turtle_pos;
        vector<vector<bool>> pond(row, vector<bool>(column, false));
        int id, x, y;
        string pos;

        for (int i = 0; i < n_turtles; i++) {
            cin >> id >> x >> y;
            turtle_pos[id].x = x;
            turtle_pos[id].y = y;
            pond[x][y] = true;
        }

        for (int i = 0; i < move; i++) {
            cin >> id >> pos;
            position &turtle = turtle_pos[id];
            x = turtle.x;
            y = turtle.y;

            if (pos == "N")
                x--;
            else if (pos == "S")
                x++;
            else if (pos == "E")
                y++;
            else if (pos == "W")
                y--;
            else if (pos == "NE")
                x--, y++;
            else if (pos == "NW")
                x--, y--;
            else if (pos == "SE")
                x++, y++;
            else
                x++, y--;

            if (x > -1 and y > -1 and x < row and y < column and !pond[x][y]) {
                pond[turtle.x][turtle.y] = false;
                turtle.x = x;
                turtle.y = y;
                pond[x][y] = true;
            }
        }

        for (int i = 0; i < row; i++) {
            int j = column - 1;
            while (j > -1 and !pond[i][j])
                j--;

            for (int k = 0; k <= j; k++)
                if (pond[i][k])
                    cout << '*';
                else
                    cout << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}