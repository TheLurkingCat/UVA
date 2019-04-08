/*
    數學
*/
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

double power(double base, int exponential) {
    if (exponential == 0)
        return 1;
    else if (exponential == 1)
        return base;

    double ans = power(base, exponential / 2);

    if (exponential & 1)
        return ans * ans * base;
    return ans * ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_testcase;
    cin >> n_testcase;
    while (n_testcase--) {
        int n_people, index;
        double probability;
        cin >> n_people >> probability >> index;
        double q = 1 - probability;
        double common_ratio = power(q, n_people);

        if (common_ratio == 1)
            cout << "0.0000\n";
        else
            cout << setprecision(4) << fixed << power(q, index - 1) * probability / (1 - common_ratio) << "\n";
    }
}