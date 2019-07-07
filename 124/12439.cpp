/*
    閏年、數學
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline int day_count(int year, string month, int day) {
    int ans = (year / 4) - (year / 100) + (year / 400);
    if ((year % 4 == 0) and (year % 100 != 0 or year % 400 == 0))
        if (month == "January" or (month == "February" and day != 29))
            --ans;
    return ans;
}

int main() {
    int n, day, year, leap_days;
    char no_use;
    string month;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> month >> day >> no_use >> year;
        leap_days = day_count(year, month, day - 1);  // 半開區間
        cin >> month >> day >> no_use >> year;
        cout << "Case " << i << ": " << abs(leap_days -= day_count(year, month, day)) << "\n";
    }
}