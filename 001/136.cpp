/*
    醜數
    時間複雜度: O(1)
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int i;
    long long ith_ugly_number;
    // 紀錄是否已經放入priority_queue
    unordered_map<long long, bool> seen;
    priority_queue<long long, vector<long long>, greater<long long>> ugly_numbers;

    ugly_numbers.push(1);
    seen[1] = 1;

    for (i = 1; i < 1501; i++) {
        ith_ugly_number = ugly_numbers.top();
        ugly_numbers.pop();
        // 把2、3、5的倍數放進ugly_numbers
        if (seen[ith_ugly_number * 2] == 0) {
            ugly_numbers.push(ith_ugly_number * 2);
            seen[ith_ugly_number * 2] = 1;
        }
        if (seen[ith_ugly_number * 3] == 0) {
            ugly_numbers.push(ith_ugly_number * 3);
            seen[ith_ugly_number * 3] = 1;
        }
        if (seen[ith_ugly_number * 5] == 0) {
            ugly_numbers.push(ith_ugly_number * 5);
            seen[ith_ugly_number * 5] = 1;
        }
    }
    cout << "The 1500'th ugly number is " << ith_ugly_number << ".\n";
    return 0;
}

/*
    cout << "The 1500'th ugly number is 859963392.\n";
*/