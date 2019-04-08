/*
    排序
    時間複雜度: O(NlogN)
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Count {
   private:
    int alphabet, counter;

   public:
    static int now;
    Count() {
        alphabet = ++now;
        counter = 0;
    }
    void operator++() {
        ++counter;
    }
    bool operator<(const Count& other) const {
        if (this->counter == other.counter)
            return this->alphabet > other.alphabet;
        return this->counter < other.counter;
    }
    friend ostream& operator<<(ostream& out, const Count& count) {
        if (count.counter)
            out << count.alphabet << " " << count.counter << "\n";
        return out;
    }
};

int Count::now = -1;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string str;
    bool flag = false;
    while (getline(cin, str)) {
        if (flag)
            cout << "\n";

        vector<Count> counter(129);

        for (const char& c : str)
            ++counter[c];

        sort(counter.begin(), counter.end());

        for (Count i : counter)
            cout << i;

        Count::now = -1;
        flag = true;
    }
}