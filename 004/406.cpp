/*
    區間找質數
    時間複雜度: O(N)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> primes(1, 1);

void build_prime_array() {
    vector<bool> isprime(1010, true);
    int i, j;
    for (i = 2; i < 32; i++)
        if (isprime[i]) {
            primes.push_back(i);
            for (j = i * i; j < 1010; j += i)
                isprime[j] = false;
        }
    for (i = 37; i < 1010; i++)
        if (isprime[i])
            primes.push_back(i);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, n, c, left, right, mid;
    build_prime_array();

    while (cin >> n >> c) {
        cout << n << " " << c << ":";
        n++;
        right = 0;

        while (primes[right + 1] < n)
            right++;

        mid = right / 2;
        left = mid;
        right = mid + (right & 1);

        // 從中心往外找邊界，注意不能超出[0, n]
        while (c--) {
            if (left > -1)
                left--;
            if (primes[right] < n)
                right++;
        }

        for (i = left + 1; i < right; i++)
            cout << " " << primes[i];
        cout << "\n\n";
    }
}