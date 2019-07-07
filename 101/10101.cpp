/*
    進位制
*/
#include <iomanip>
#include <iostream>

using namespace std;

void cut(long long x) {
    if (x >= 10000000) {
        if (x / 10000000 >= 100)
            cut(x / 10000000);
        else
            cout << " " << x / 10000000;
        cout << " kuti";
        x %= 10000000;
    }
    if (x >= 100000) {
        cout << " " << x / 100000 << " lakh";
        x %= 100000;
    }
    if (x >= 1000) {
        cout << " " << x / 1000 << " hajar";
        x %= 1000;
    }
    if (x >= 100) {
        cout << " " << x / 100 << " shata";
        x %= 100;
    }
    if (x)
        cout << " " << x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n;
    int number = 0;
    while (cin >> n) {
        cout << setw(4) << ++number << ".";
        if (n)
            cut(n);
        else
            cout << " 0";
        cout << "\n";
    }
}