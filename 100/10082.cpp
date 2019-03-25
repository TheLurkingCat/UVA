#include <iostream>

using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char map[128];

    for (int i = 0; key[i] != 0; ++i)
        map[key[i]] = key[i - 1];

    map[' '] = ' ';
    map['\n'] = '\n';

    int c;

    while ((c = cin.get()) != -1)
        cout << map[c];

    return 0;
}