/*
    建305的Code的Code
    時間複雜度: O(1)
*/
#include <iostream>

using namespace std;

bool is_answer(int k, int m) {
    int now = 0, i;
    for (i = k * 2; i > k; i--) {
        now = (now - 1 + m) % i;
        if (now < k)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int m, k, ans[15];

    for (k = 1; k < 14; k++) {
        m = k + 1;
        while (1) {
            if (is_answer(k, m))
                break;
            m++;
        }
        ans[k] = m;
    }

    cout << "/*\n"
         << "    約瑟夫問題、建表、離線計算\n"
         << "    時間複雜度: O(1)\n"
         << "*/\n"
         << "#include <iostream>\n\n"
         << "using namespace std;\n\n"
         << "int main() {\n"
         << "    cin.tie(0);\n"
         << "    ios_base::sync_with_stdio(0);\n\n"
         << "    int k, ans[14] = {0";

    for (k = 1; k < 14; k++)
        cout << ", " << ans[k];

    cout << "};\n\n"
         << "    while (cin >> k && k)\n"
         << "        cout << ans[k] << \"\\n\";\n"
         << "    return 0;\n"
         << "}\n";

    return 0;
}