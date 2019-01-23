/*
    陣列轉向
    時間複雜度: O(N)
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string sentence[101];
    int i, j, n = 0, length[101];
    int max_length = 0;

    while (getline(cin, sentence[n])) {
        length[n] = sentence[n].size();
        max_length = max(max_length, length[n]);
        n++;
    }

    for (i = 0; i < max_length; i++) {
        for (j = n - 1; j > -1; j--)
            if (i < length[j])
                cout << sentence[j][i];
            else
                cout << " ";
        cout << "\n";
    }
    return 0;
}