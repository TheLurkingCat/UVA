/*
    二分搜尋、最大值最小化
    時間複雜度: O(NlogN)
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool is_possible(const long long &page_per_group, const int &n_group, const vector<int> &books) {
    long long sum = 0;
    int i = books.size() - 1, j = 0;

    while (i > -1) {
        if (sum + books[i] > page_per_group) {
            sum = 0;
            j++;  // 下一堆
        } else
            sum += books[i--];  // 還放得下就塞進去
        if (j == n_group)
            return false;  // 分太多組，代表 page_per_group 太小
    }
    return true;  // 分太少組，代表 page_per_group 太大
}

void slash_pos(const long long &page_per_group, const int &n_group, vector<int> &slash_position, const vector<int> &books) {
    long long sum = 0;
    int i = books.size() - 1, j = 1;

    while (i > -1) {
        if (sum + books[i] <= page_per_group && i >= n_group - j) {  //每組至少一個
            sum += books[i--];
        } else {
            j++;
            sum = 0;
            slash_position.push_back(i + 1);  // 紀錄第幾個後要印出 /
        }
        if (j > n_group)
            break;
    }
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_case, n_book, n_group, i, j;
    long long lower, upper, mid;
    vector<int> slash_position;
    slash_position.reserve(n_group);

    cin >> n_case;
    while (n_case--) {
        cin >> n_book >> n_group;

        vector<int> books(n_book, 0);

        for (i = 0; i < n_book; i++)
            cin >> books[i];

        lower = *max_element(books.begin(), books.end());     // 下界是分成 n_book 組的情形
        upper = accumulate(books.begin(), books.end(), 0LL);  // 上界是只分一組的情形

        // 二分搜尋找最多頁的一組的最小頁數
        do {
            mid = (lower + upper) / 2;
            if (is_possible(mid, n_group, books))
                upper = mid;
            else
                lower = mid + 1;
        } while (lower < upper);

        slash_pos(lower, n_group, slash_position, books);

        cout << books[0];
        for (i = 1; i < n_book; i++) {
            if (!slash_position.empty() && i == slash_position.back()) {
                cout << " /";
                slash_position.pop_back();
            }
            cout << " " << books[i];
        }
        cout << "\n";
    }
    return 0;
}