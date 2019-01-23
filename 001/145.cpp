/*
    模擬
    時間複雜度: O(N)
*/
#include <bitset>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int cost[5][3] = {
    2, 10, 6,
    5, 25, 15,
    13, 53, 33,
    17, 87, 47,
    30, 144, 80};

int charge_time[5] = {0, 480, 1080, 1320, 1440};  // 因為有跨日所以切成4時段

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bitset<1440> used;
    char charging_step;
    string phone_number;
    int a, b, c, d, i, j, time_begin, time_end;

    while (cin >> charging_step && charging_step != '#') {
        int charge_categories[5] = {};

        cin >> phone_number >> a >> b >> c >> d;
        time_begin = a * 60 + b;
        time_end = c * 60 + d;

        if (time_begin >= time_end) {  // 跨日情形(0小時其實是24小時)
            // 今天
            for (i = time_begin; i < 1440; i++)
                used[i] = 1;
            // 明天
            for (i = 0; i < time_end; i++)
                used[i] = 1;

        } else
            for (i = time_begin; i < time_end; i++)
                used[i] = 1;
        // 簡單算一下費用
        for (i = 0; i < 4; i++) {
            for (j = charge_time[i]; j < charge_time[i + 1]; j++)
                charge_categories[i] += used[j];
            charge_categories[4] += charge_categories[i] * cost[charging_step - 'A'][i % 3];
        }

        cout << setw(10) << phone_number
             << setw(6) << charge_categories[1]
             << setw(6) << charge_categories[2]
             << setw(6) << charge_categories[3] + charge_categories[0]
             << setw(3) << charging_step
             << setw(8) << fixed << setprecision(2) << double(charge_categories[4]) / 100
             << '\n';

        used.reset();
    }
    return 0;
}