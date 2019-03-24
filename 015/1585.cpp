/*
    模擬
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int score, point_now, n;
    char c;
    cin >> n;
    cin.ignore(1024, '\n');

    while (n--) {
        score = 0;
        point_now = 1;

        while ((c = cin.get()) != '\n')
            if (c == 'O')
                score += point_now++;
            else
                point_now = 1;

        cout << score << "\n";
    }
    return 0;
}