/*
    直式加法
*/
#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        int count = 0, j = 0;

        do {
            if (n % 10 + m % 10 + j > 9)
                count += j = 1;
            else
                j = 0;
            n /= 10;
            m /= 10;
        } while (n != 0 || m != 0);

        if (count == 0)
            cout << "No carry operation.\n";
        else if (count == 1)
            cout << "1 carry operation.\n";
        else
            cout << count << " carry operations.\n";
    }
}