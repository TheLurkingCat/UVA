/*
    平均
    時間複雜度: O(N)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int answer, n, average, n_case = 1;
    while (cin >> n && n) {
        vector<int> brick(n, 0);
        answer = average = 0;

        while (n)
            cin >> brick[--n];

        for (const int& i : brick)
            average += i;

        average /= brick.size();

        for (const int& i : brick)
            if (i > average)
                answer += (i - average);

        cout << "Set #" << n_case++ << "\nThe minimum number of moves is " << answer << ".\n\n";
    }
}