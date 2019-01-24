/*
    質因數分解
    時間複雜度: O(NlogN)
*/
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int power(int& base, int expo) {
    if (expo == 0)
        return 1;
    if (expo == 1)
        return base;
    int ans = power(base, expo / 2);
    return expo & 1 ? ans * ans * base : ans * ans;
}

vector<int> generate_prime(int N) {
    int i, j;
    vector<int> prime_table;
    vector<bool> is_prime(N, true);
    for (i = 2; i < N; i++) {
        if (is_prime[i])
            prime_table.push_back(i);
        for (j = 0; i * prime_table[j] < N; j++) {
            is_prime[i * prime_table[j]] = false;
            if (i % prime_table[j] == 0)
                break;
        }
    }
    return prime_table;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int sum, base, expo, cnt;
    string x;
    stack<pair<int, int>> ans;
    vector<int> primes = generate_prime(182);

    while (getline(cin, x)) {
        if (x.length() == 1)
            break;

        istringstream input(x);
        sum = 1;

        while (input >> base >> expo)
            sum *= power(base, expo);

        sum--;

        for (const int& prime : primes) {
            cnt = 0;
            while (sum % prime == 0) {
                sum /= prime;
                cnt++;
            }
            if (cnt)
                ans.push(make_pair(prime, cnt));
        }

        if (sum != 1)
            ans.push(make_pair(sum, 1));

        cout << ans.top().first << " " << ans.top().second;
        ans.pop();

        while (!ans.empty()) {
            const pair<int, int> k = ans.top();
            cout << " " << k.first << " " << k.second;
            ans.pop();
        }

        cout << "\n";
    }
    return 0;
}