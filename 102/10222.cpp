/*
    模擬、建表
*/
#include <iostream>

using namespace std;

const char keyboard[35] = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main() {
    char decoded[128], c;
    for (int i = 0; i < 128; ++i)
        decoded[i] = i;

    for (int i = 2; keyboard[i]; ++i)
        decoded[keyboard[i]] = keyboard[i - 2];
    while ((c = cin.get()) and !cin.eof()) {
        if (c >= 'A' and c <= 'Z')
            c |= 32;
        cout << decoded[c];
    }
}
