/*
    回文
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n_testcase;
    cin >> n_testcase;

    while (n_testcase--) {
        int step = 0;
        string origin, temp;
        cin >> origin;
        temp = origin;
        reverse(temp.begin(), temp.end());

        do {
            temp = origin = to_string(stoul(temp) + stoul(origin));
            reverse(temp.begin(), temp.end());
            step++;
        } while (temp != origin);

        cout << step << " " << origin << "\n";
    }
    return 0;
}
