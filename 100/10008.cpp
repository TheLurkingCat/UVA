#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

struct wrap {
    int count;
    char alphabet;
    bool operator<(const wrap& other) const {
        if (count == other.count)
            return alphabet < other.alphabet;
        return count > other.count;
    }
};

int main() {
    int n, t, cnt;
    char c;
    vector<wrap> data(26);

    while (cin >> n) {
        cin.ignore(1024, '\n');

        for (auto&& i : data)
            i.count = 0;

        for (int i = 0; i < n; i++) {
            while ((c = cin.get()) != '\n') {
                if (!isalpha(c))
                    continue;
                cnt++;
                t = toupper(c) - 65;
                data[t].count++;
                data[t].alphabet = toupper(c);
            }
        }

        sort(data.begin(), data.end());

        for (const auto& i : data) {
            if (i.count)
                cout << i.alphabet << " " << i.count << "\n";
        }
    }
}