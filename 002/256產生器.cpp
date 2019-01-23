/*
    建256的Code的Code
    時間複雜度: O(1)
*/
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int i, j;
    cout << "#include <iostream>\n\n"
         << "using namespace std;\n\n"
         << "int main() {\n"
         << "    cin.tie(0);\n"
         << "    ios_base::sync_with_stdio(0);\n\n"
         << "    int n;\n\n"
         << "    while (cin >> n) {\n"
         << "        if (n == 2) {\n";

    for (i = 0; i <= 9; ++i)
        for (j = 0; j <= 9; ++j)
            if ((i + j) * (i + j) == (i * 10 + j))
                cout << "            cout << \"" << setw(1) << setfill('0') << i << setw(1) << setfill('0') << j << "\\n\";\n";

    cout << "        } else if (n == 4) {\n";

    for (i = 0; i <= 99; ++i)
        for (j = 0; j <= 99; ++j)
            if ((i + j) * (i + j) == (i * 100 + j))
                cout << "            cout << \"" << setw(2) << setfill('0') << i << setw(2) << setfill('0') << j << "\\n\";\n";
    cout << "        } else if (n == 6) {\n";

    for (i = 0; i <= 999; ++i)
        for (j = 0; j <= 999; ++j)
            if ((i + j) * (i + j) == (i * 1000 + j))
                cout << "            cout << \"" << setw(3) << setfill('0') << i << setw(3) << setfill('0') << j << "\\n\";\n";

    cout << "        } else if (n == 8) {\n";

    for (i = 0; i <= 9999; ++i)
        for (j = 0; j <= 9999; ++j)
            if ((i + j) * (i + j) == (i * 10000 + j))
                cout << "            cout << \"" << setw(4) << setfill('0') << i << setw(4) << setfill('0') << j << "\\n\";\n";

    cout << "        }\n"
         << "    }\n"
         << "    return 0;\n}\n";
    return 0;
}