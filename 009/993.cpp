/*
    因數分解
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_case;
    cin >> n_case;
    while (n_case--) {
        vector<int> number;
        int n, cnt = 0;
        cin >> n;
        if (n == 0)
            cout << "0\n";
        else if (n == 1)
            cout << "1\n";
        else {
            // 這裡要由大到小做回來
            for (int i = 9; i > 1 && n != 1; i--) {
                while (n % i == 0) {
                    number.push_back(i);
                    n /= i;
                }
            }

            sort(number.begin(), number.end());

            if (n != 1)
                cout << "-1\n";
            else {
                for (const int& i : number)
                    cout << i;
                cout << "\n";
            }
        }
    }
    return 0;
}