/*
    字元代換
    時間複雜度: O(N) (有N個字)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bool position = 0;  // 紀錄是第奇數個還是第偶數個雙引號
    char c;

    while (cin.get(c)) {
        if (c == '"') {
            position = !position;
            if (position)
                cout << "``";
            else
                cout << "''";

        } else
            cout << c;
    }
    return 0;
}