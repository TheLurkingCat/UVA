/*
    優先佇列
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n_case, n, m, i, index_now, elements;

    cin >> n_case;
    while (n_case--) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>, less<int>> max_heap;
        queue<int> add, get;

        index_now = elements = 0;
        cin >> m >> n;

        while (m-- && cin >> i)
            add.push(i);

        while (n-- && cin >> i)
            get.push(i);

        while (!add.empty()) {
            elements++;

            if (!min_heap.empty() && add.front() > max_heap.top())
                min_heap.push(add.front());  // 維持 min_heap 中最小元素 > max_heap 中最大元素: max->[-4, -1000], min->[1, 2, 3, 8], i=2
            else
                max_heap.push(add.front());
            add.pop();

            while (!get.empty() && elements == get.front()) {
                while (max_heap.size() != index_now) {
                    if (max_heap.size() < index_now) {  // min_heap 太多了
                        max_heap.push(min_heap.top());
                        min_heap.pop();
                    } else if (max_heap.size() > index_now) {  // min_heap 不夠
                        min_heap.push(max_heap.top());
                        max_heap.pop();
                    }
                }

                cout << min_heap.top() << "\n";
                index_now++;
                get.pop();
            }
        }
        if (n_case)
            cout << "\n";
    }
    return 0;
}
