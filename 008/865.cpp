/*
    字元替換、麻煩的輸入
    時間複雜度: O(N)
*/
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<char> map(128);
    int n_case, length, i;
    string plaintext, substitution;

    cin >> n_case;
    cin.ignore(1024, '\n');
    cin.ignore(1024, '\n');  // 第一次要濾掉兩個換行
    while (n_case--) {
        iota(map.begin(), map.end(), 0);  // 自己對應自己

        getline(cin, plaintext);  // 有可能有空白
        getline(cin, substitution);

        cout << substitution << "\n"
             << plaintext << "\n";

        length = plaintext.length();

        for (i = 0; i < length; i++)
            map[plaintext[i]] = substitution[i];  // 建對應表

        while (getline(cin, plaintext) && plaintext.length()) {
            for (const char& c : plaintext)
                cout << map[c];
            cout << "\n";
        }
        if (n_case)
            cout << "\n";
    }
}