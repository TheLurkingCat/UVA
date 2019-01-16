/*
    找零錢問題
    時間複雜度: O(N^2logN) (排序)
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct stamp_data {
    int* denominations;
    int stamp_types;
};

bool cmp(stamp_data a, stamp_data b) {
    if (a.stamp_types == b.stamp_types) {
        for (int i = a.stamp_types - 1; i > -1; i--)
            if (a.denominations[i] > b.denominations[i])
                return false;
        return true;
    }
    return a.stamp_types < b.stamp_types;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<stamp_data> answer(10);
    int s, n, i, j, m, temp, k, value;

    while (cin >> s && s) {
        value = 0;
        answer.clear();

        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> m;
            int dp[1101] = {};
            int* denominations = new int[10];

            // 解完全背包問題
            for (j = 0; j < m; j++) {
                cin >> temp;
                denominations[j] = temp;
                dp[temp] = 1;
                for (k = 1; k < 1001; k++)
                    if (dp[k] && dp[k] < s && (dp[k + temp] > dp[k] + 1 || dp[k + temp] == 0))
                        dp[k + temp] = dp[k] + 1;
            }
            // 找第一個組不出來的數字
            j = 1;
            while (dp[j])
                j++;
            j--;
            // j > value時，有更好的解所以清空之前累積的答案再放入當前面額組合
            // j == value時，就放入當前的面額組合
            if (j > value) {
                value = j;
                answer.clear();
                answer.push_back(stamp_data{denominations, m});
            } else if (j == value) {
                answer.push_back(stamp_data{denominations, m});
            }
        }
        // 照題意排序，最小的就是題目要的
        sort(answer.begin(), answer.end(), cmp);
        cout << "max coverage =" << setw(4) << value << " :";
        for (i = 0; i < answer[0].stamp_types; i++)
            cout << setw(3) << answer[0].denominations[i];
        cout << '\n';
    }
    return 0;
}