/*
    七段顯示器
*/
#include <iostream>
#include <string>
using namespace std;

string output_type[5] = {
    "    ",
    "   |",
    "|   ",
    "|  |",
    " -- ",
};

int digits[10][5] = {
    {4, 3, 0, 3, 4},  // 0
    {0, 1, 0, 1, 0},  // 1
    {4, 1, 4, 2, 4},  // 2
    {4, 1, 4, 1, 4},  // 3
    {0, 3, 4, 1, 0},  // 4
    {4, 2, 4, 1, 4},  // 5
    {4, 2, 4, 3, 4},  // 6
    {4, 1, 0, 1, 0},  // 7
    {4, 3, 4, 3, 4},  // 8
    {4, 3, 4, 1, 4}   // 9
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, i, j, k, temp_n;
    string s;
    while (cin >> n >> s && n) {
        for (auto&& c : s)
            c -= '0';

        for (i = 0; i < 5; i++) {
            if (i == 0 || i == 2 || i == 4)
                temp_n = 1;
            else
                temp_n = n;

            while (temp_n--) {
                for (j = 0; j < s.length(); j++) {
                    cout << output_type[digits[s[j]][i]][0];

                    for (k = 0; k < n; k++)
                        cout << output_type[digits[s[j]][i]][1];

                    cout << output_type[digits[s[j]][i]][3];

                    if (j != s.length() - 1)
                        cout << ' ';
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}