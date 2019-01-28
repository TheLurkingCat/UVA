/*
    建991的Code的Code
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int dp[11] = {1, 1, 2};
    for (int i = 3; i <= 10; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];

    cout << "#include <iostream>\n\n"
         << "using namespace std;\n\n"
         << "int main() {\n"
         << "    cin.tie(0);\n"
         << "    ios_base::sync_with_stdio(0);\n\n"
         << "    bool flag = false;\n"
         << "    int n, ans[11] = {";

    for (int i = 0; i < 10; i++)
        cout << dp[i] << ", ";

    cout << dp[10]
         << "};\n"
         << "    while (cin >> n) {\n"
         << "        if (flag)\n"
         << "            cout << \"\\n\";\n"
         << "        cout << ans[n] << \"\\n\";\n"
         << "        flag = true;\n"
         << "    }\n"
         << "}\n";
}