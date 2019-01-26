/*
    字串最小表示法
    時間複雜度: O(N)
*/
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_case, i, j, k, difference, n;
    char str[10001];

    cin >> n_case;
    while (n_case--) {
        cin >> str;

        i = 0;
        j = 1;
        n = strlen(str);

        while (j < n) {
            // 同樣的字，找到第一個不一樣的字，下面就能知道 i 開頭還是 j 開頭字典序比較小
            k = 0;
            do {
                difference = str[i + k] - str[(j + k) % n];
                k++;
            } while (difference == 0 && i + k < n);

            if (difference > 0) {
                i += k;             // 找到字典序更小的字，把 i 移到字上(相當於以此為開頭搜尋)
                j = max(i + 1, j);  // j 至少要是 i + 1，越大越好
            } else
                j += k;  // 找到字典序更大的字，把 j 移到字後(跳過他)
        }
        cout << i + 1 << "\n";
    }
    return 0;
}