/*
    建表
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    while (cin >> n) {
        if (n == 2) {
            cout << "00\n";
            cout << "01\n";
            cout << "81\n";
        } else if (n == 4) {
            cout << "0000\n";
            cout << "0001\n";
            cout << "2025\n";
            cout << "3025\n";
            cout << "9801\n";
        } else if (n == 6) {
            cout << "000000\n";
            cout << "000001\n";
            cout << "088209\n";
            cout << "494209\n";
            cout << "998001\n";
        } else if (n == 8) {
            cout << "00000000\n";
            cout << "00000001\n";
            cout << "04941729\n";
            cout << "07441984\n";
            cout << "24502500\n";
            cout << "25502500\n";
            cout << "52881984\n";
            cout << "60481729\n";
            cout << "99980001\n";
        }
    }
    return 0;
}