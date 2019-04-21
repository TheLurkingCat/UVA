/*
    模擬
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Nap {
   public:
    int start, duration;
    Nap(int s, int d) {
        start = s;
        duration = d;
    }
    bool operator<(const Nap& other) const {
        if (duration == other.duration)
            return start > other.start;
        return duration < other.duration;
    }
    void print_time() {
        int hour = start / 60;
        int minute = start % 60;
        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute;
    }
    void print_duration() {
        int hour = duration / 60;
        int minute = duration % 60;
        if (hour)
            cout << hour << " hours and ";
        cout << minute << " minutes.\n";
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int day = 0, n, hour_start, minute_start, hour_end, minute_end, start, end;
    char no_use;
    while (cin >> n) {
        vector<pair<int, int>> schedule;
        pair<int, int> head;

        while (n--) {
            cin >> hour_start >> no_use >> minute_start >> hour_end >> no_use >> minute_end;
            start = hour_start * 60 + minute_start;
            end = hour_end * 60 + minute_end;
            cin.ignore(1024, '\n');
            schedule.emplace_back(start, end);
        }

        sort(schedule.begin(), schedule.end());
        schedule.emplace_back(1080, 1440);

        int last_end = 600;

        Nap ans(0, 0);

        for (const auto& i : schedule) {
            ans = max(ans, Nap(last_end, i.first - last_end));
            last_end = i.second;
        }

        cout << "Day #" << ++day << ": the longest nap starts at ";
        ans.print_time();
        cout << " and will last for ";
        ans.print_duration();
    }
}