/*
    質數
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<bool> is_prime(1000000, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 1000; i++)
        if (is_prime[i])
            for (int j = i * i; j < 1000000; j += i)
                is_prime[j] = false;
    int n, k;
    while (cin >> n) {
        cout << n;
        if (is_prime[n]) {
            string word = to_string(n);
            reverse(word.begin(), word.end());
            k = stoi(word);
            if (k != n and is_prime[k])
                cout << " is emirp.\n";
            else
                cout << " is prime.\n";
        } else
            cout << " is not prime.\n";
    }
}
