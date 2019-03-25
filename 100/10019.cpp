/*
    進位轉換
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string number;
    int n_testcase;
    cin >> n_testcase;
    while (n_testcase--) {
        cin >> number;
        cout << __builtin_popcount(stoi(number, NULL, 10)) << " " << __builtin_popcount(stoi(number, NULL, 16)) << "\n";
    }

    return 0;
}