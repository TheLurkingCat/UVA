#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    unordered_map<string, string> match;
    int n, m;
    string a, b;

    cin >> n >> m;

    while (n--) {
        cin >> a >> b;
        match[a] = b;
    }

    while (m--) {
        cin >> a;
        auto temp = match.find(a);
        if (temp == match.end())
            switch (a.back()) {
                case 'y':
                    switch (a[a.length() - 2]) {
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'o':
                        case 'u':
                            cout << a << "s\n";
                            break;
                        default:
                            a.pop_back();
                            cout << a << "ies\n";
                            break;
                    }
                    break;
                case 'o':
                case 'h':
                case 'x':
                case 's':
                    cout << a << "es\n";
                    break;
                default:
                    cout << a << "s\n";
                    break;
            }
        else
            cout << temp->second << "\n";
    }
}