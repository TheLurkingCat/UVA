#include <stdio.h>

int main() {
    char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char map[128];
    int i;

    for (i = 0; key[i] != 0; ++i) {
        map[key[i]] = key[i - 1];
    }

    map[' '] = ' ';
    map['\n'] = '\n';

    int c;
    while ((c = getchar()) != -1)
        putchar(map[c]);
    return 0;
}