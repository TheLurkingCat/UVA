/*
    字串最小週期
    時間複雜度(naive): O(N^2) (N是字串長度)
    時間複雜度(KMP)  : O(N)
*/
#include <iostream>
#include <string>

using namespace std;

int KMP_solution(string word) {
    int i = 0, j = -1, next[100] = {-1}, length = word.size();
    // next[i] 表示 i 位置前綴和後綴有幾個字相同
    while (i < length)
        if (j == -1 || word[i] == word[j])
            next[++i] = ++j;
        else
            j = next[j];
    return length % (length - next[length]) ? length : length - next[length];  // 無法整除: 沒有小於 length 的循環節
}

int naive_solution(string word) {
    int i, j, length = word.size();
    for (i = 1; i < length; i++)
        if (length % i == 0) {
            for (j = length - 1; j >= i; j--)  // 反過來比較好算
                if (word[j] != word[j - i])
                    break;
            if (j < i)  // 找到最小解
                break;
        }
    return i;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string word;

    cin >> n;
    while (n--) {
        cin >> word;
        cout << KMP_solution(word) << "\n";
        if (n)
            cout << "\n";  // 小心 Presentation Error
    }
    return 0;
}