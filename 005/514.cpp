/*
    模擬、堆疊
    時間複雜度: O(N)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, n;
    while (cin >> n && n) {
        while (cin >> i && i) {
            vector<int> station, order(n, 0);
            int car_now = 0, k = n;

            order[--k] = i;
            for (i = k - 1; i > -1; i--)
                cin >> order[i];

            while (!order.empty())
                if (!station.empty() && order.back() == station.back()) {
                    station.pop_back();
                    order.pop_back();
                } else if (car_now < n)
                    station.push_back(++car_now);
                else
                    break;

            cout << (station.empty() ? "Yes\n" : "No\n");
        }
        cout << "\n";
    }
    return 0;
}