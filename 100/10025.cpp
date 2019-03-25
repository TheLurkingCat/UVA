/*
    找規律
*/
#include <iostream>

using namespace std;

int main() {
    int n_testcase;
    cin >> n_testcase;

    while (n_testcase--) {
        int n = 0, sum = 0, k;
        cin >> k;

        if (k == 0) {
            if (n_testcase)
                cout << "3\n\n";
            else
                cout << "3\n";
        } else {
            k = k > 0 ? k : -k;

            while (sum < k)
                sum += (++n);

            if ((sum - k) & 1)
                n += n & 1 ? 2 : 1;

            if (n_testcase)
                cout << n << "\n\n";
            else
                cout << n << "\n";
        }
    }
    return 0;
}