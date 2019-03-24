#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

void recursion(const string& str, vector<int64_t>& sequence) {
    int sign = 1, i, memory = 0, length = str.length();
    char operator_;

    for (i = 1; i < length; i++)
        if (str[i] == '-')
            sign = -1;
        else if (str[i] >= '0' && str[i] <= '9')
            memory = memory * 10 + str[i] - '0';
        else {
            operator_ = str[i];
            break;
        }

    memory *= sign;

    if (operator_ == '+') {
        recursion(str.substr(i + 1), sequence);
        int64_t prev = sequence[0];
        sequence[0] = memory;
        for (int i = 1; i < n; i++) {
            int64_t temp = sequence[i];
            sequence[i] = sequence[i - 1] + prev;
            prev = temp;
        }
    } else if (operator_ == '*') {
        recursion(str.substr(i + 1), sequence);
        sequence[0] *= memory;
        for (int i = 1; i < n; i++)
            sequence[i] *= sequence[i - 1];
    } else
        fill(sequence.begin(), sequence.end(), memory);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string str;

    while (cin >> str >> n) {
        vector<int64_t> sequence(n);
        recursion(str, sequence);
        for (int i = 0; i < n; i++)
            cout << sequence[i] << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}