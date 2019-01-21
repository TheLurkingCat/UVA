/*
    計數器
    時間複雜度: O(N) (一行有N個字)
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>

using namespace std;

int main() {
    char alphabet;
    map<char, int> counter;  // 查找和插入都是 O(log(size))，但這裡 size <= 52 是常數，所以是 O(1)
    int max_occurrence;

    while (cin.get(alphabet) && alphabet != EOF) {
        max_occurrence = 0;
        counter[alphabet] = 1;

        while (cin.get(alphabet) && alphabet != '\n')
            if (isalpha(alphabet))
                counter[alphabet]++;

        for (const auto& i : counter)
            max_occurrence = max(max_occurrence, i.second);

        for (const auto& i : counter)
            if (max_occurrence == i.second)
                cout << i.first;

        cout << " " << max_occurrence << "\n";
        counter.clear();
    }
}