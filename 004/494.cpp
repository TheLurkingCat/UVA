/*
    輸入輸出
    時間複雜度: O(N)
*/
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string input;
    int word;
    regex pattern("[^A-Za-z]");

    while (getline(cin, input)) {
        word = 0;
        istringstream sentence(regex_replace(input, pattern, " "));
        while (sentence >> input)
            word++;
        cout << word << "\n";
    }
}