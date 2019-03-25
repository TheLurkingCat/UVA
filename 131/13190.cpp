/*
    優先佇列
    時間複雜度: O(NlogN)
*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Medicine {
   private:
    static int count;
    string name;
    int order, freqency, now;

   public:
    Medicine(const string& name, const int& freqency, const int& now) {
        this->order = Medicine::count++;
        this->freqency = freqency;
        this->name = name;
        this->now = now;
    }

    bool operator>(const Medicine& other) const {
        if (this->now == other.now)
            return this->order > other.order;
        return this->now > other.now;
    }

    Medicine take() const {
        cout << now << " " << name << "\n";
        Medicine&& temp = Medicine(*this);
        temp.now += freqency;
        return temp;
    }
};

int Medicine::count = 0;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n_testcase;
    cin >> n_testcase;

    while (n_testcase--) {
        priority_queue<Medicine, vector<Medicine>, greater<Medicine>> schedule;
        string name;
        int n_medicine, n_times, frequency;
        cin >> n_medicine >> n_times;

        while (n_medicine--) {
            cin >> name >> frequency;
            schedule.emplace(name, frequency, frequency);
        }

        while (n_times--) {
            schedule.emplace(schedule.top().take());
            schedule.pop();
        }
    }
}