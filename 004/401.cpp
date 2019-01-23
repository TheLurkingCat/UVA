/*
    鏡像迴文
    時間複雜度: O(N)
*/
#include <iostream>
#include <string>

using namespace std;

char mirror[128];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';

    string input;
    int length, i, j;

    while (cin >> input) {
        bool is_mirrored = true, is_palindrome = true;
        // 頭尾比對
        length = input.size();
        for (i = 0, j = length - 1; i <= j; i++, j--) {
            if (input[i] != input[j])
                is_palindrome = false;
            if (input[i] != mirror[input[j]])
                is_mirrored = false;
        }

        cout << input;

        if (is_mirrored) {
            if (is_palindrome)
                cout << " -- is a mirrored palindrome.\n\n";
            else
                cout << " -- is a mirrored string.\n\n";
        } else {
            if (is_palindrome)
                cout << " -- is a regular palindrome.\n\n";
            else
                cout << " -- is not a palindrome.\n\n";
        }
    }
}