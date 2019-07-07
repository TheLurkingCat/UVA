/*
    字串計數
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string word;
    regex pattern("[^A-Za-z]");
    int count;
    bool case_n = false;

    while (cin >> count) {
        if (case_n)
            cout << "\n";

        bool print = case_n = true;
        map<string, int> order;
        cin.ignore(1024, '\n');
        while (getline(cin, word)) {
            if (word.length() == 0)
                continue;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            istringstream input(regex_replace(word, pattern, " "));
            while (input >> word and word != "endoftext")
                if (word.length())
                    ++order[word];
            if (word == "endoftext")
                break;
        }

        for (const auto &i : order)
            if (i.second == count) {
                print = false;
                cout << i.first << "\n";
            }
        if (print)
            cout << "There is no such word.\n";
    }
}
