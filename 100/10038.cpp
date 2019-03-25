/*
    模擬
*/
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while (cin >> n) {
        int last, num;
        vector<bool> seen(n, false);
        seen[0] = true;
        cin >> last;

        for (int i = 1; i < n; i++) {
            cin >> num;

            if (seen[0]) {
                int&& check = abs(num - last);

                if (check >= n || seen[check]) {
                    seen[0] = false;
                    cout << "Not jolly\n";
                } else {
                    seen[check] = true;
                    last = num;
                }
            }
        }

        if (seen[0])
            cout << "Jolly\n";
    }
    return 0;
}