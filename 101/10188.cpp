/*
    模擬
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k = 0;
    string in;
    while (cin >> n and n) {
        vector<char> number1, number2;
        vector<string> answer, output;
        cout << "Run #" << ++k << ": ";
        cin.ignore(1024, '\n');
        while (n--) {
            getline(cin, in);
            answer.push_back(in);
        }
        cin >> m;
        cin.ignore(1024, '\n');
        while (m--) {
            getline(cin, in);
            output.push_back(in);
        }
        if (answer == output)
            cout << "Accepted\n";
        else {
            for (const auto i : answer)
                for (const auto c : i)
                    if (c <= '9' and c >= '0')
                        number1.push_back(c);
            for (const auto i : output)
                for (const auto c : i)
                    if (c <= '9' and c >= '0')
                        number2.push_back(c);
            if (number1 == number2)
                cout << "Presentation Error\n";
            else
                cout << "Wrong Answer\n";
        }
    }
}