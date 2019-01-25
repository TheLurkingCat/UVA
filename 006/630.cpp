/*
    字串處理
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_case, n_word, num;
    string word, sorted_word, test_word;
    unordered_map<string, vector<string>> table;

    cin >> n_case;
    while (n_case--) {
        cin >> n_word;

        while (n_word--) {
            cin >> word;
            sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            table[sorted_word].push_back(word);
        }

        while (cin >> test_word && test_word != "END") {
            cout << "Anagrams for: " << test_word << "\n";

            num = 1;
            sorted_word = test_word;
            sort(sorted_word.begin(), sorted_word.end());

            if (table[sorted_word].empty())
                cout << "No anagrams for: " << test_word << "\n";
            else
                for (const string& anagram : table[sorted_word])
                    cout << setw(3) << num++ << ") " << anagram << "\n";
        }

        if (n_case) {
            cout << "\n";
            table.clear();
        }
    }
    return 0;
}