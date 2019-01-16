/*
    約瑟夫問題，加上需要迭代每一個m
    時間複雜度: O(NlogN)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, last_offline;

    while (cin >> n && n != 0) {
        // 剛好差1直接有解
        if (n == 13)
            cout << "1\n";
        else {
            n--;  // 總共有n個區域，編號1~n，，第一區一定最先停
                  // 所以要求的區域變成2~n，轉換成n-1人的約瑟夫問題
            last_offline = 0;
            m = 1;
            // 經過轉換回左移2區，所以編號13變成編號11
            while (last_offline != 11) {
                m++;
                // 約瑟夫問題O(logN)解法，詳細在最下方
                last_offline = n * m - 1;
                while (last_offline >= n) {
                    last_offline += (last_offline - n) / (m - 1) - n;
                }
            }
            cout << m << '\n';
        }
    }
    return 0;
}

/*
第n * m - 1次數到的區域就是最後一個斷電的區域，那就追蹤他之前每次被數到的時候來確定他的編號。
假設n=5, m=3，一共有15次計數(每數m次停電一區，一共有n個區域，所以需要n*m次計數)，
每一次數到的區域的編號如下：

計數: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
區域: 0 1 2 3 4 0 1 3 4 1  3  1  3  3  3

設第p次(從0數起)數到的區域是y，令 p = m * a + b (0 <= b < m)。
經過前p次計數，一共有 floor(p / m) = a 區停電，還剩下 n - a 區。
如果y本次被數到之後沒有斷電，那麼他下次被數到是在其他 n - a 區都數過之後，
也就是第 q = p + n - a = n + (m - 1) * a + b 次計數。
反推就能得到解

由y本次計數後還存活知 b < m - 1 ，故 a = floor((q - n) / (m - 1))，
p = q - (n - a) = q - n + floor((q - n) / (m - 1))。

我們要求最後一個停電的的區域，他是第 n * m - 1 次計數後斷電的，
用計算前驅的方式求出這個區域之前一次被數到是在什麼時候
不斷地重複這一過程，直到知道他是第 k' (0 <= k' < n) 次被數到的人，那麼k'就是這個區域的編號。
*/