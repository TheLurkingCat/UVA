/*
    模擬、字元替換
    時間複雜度: O(N)
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char terminal[10][10];

void clear_terminal() {
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            terminal[i][j] = ' ';
}

void write_character(char character, int row, int column, bool mode) {
    if (mode)
        for (int i = 8; i >= column; i--)
            terminal[row][i + 1] = terminal[row][i];

    terminal[row][column] = character;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j, length, n, row, column, case_number = 0;
    bool mode;  // 0:OVERWRIE, 1:INSERT
    string input;

    while (cin >> n && n) {
        case_number++;
        row = column = mode = 0;
        clear_terminal();

        cin.ignore(1024, '\n');  // 清空多餘的字

        while (n--) {
            getline(cin, input);
            length = input.size();

            for (i = 0; i < length; i++) {
                if (input[i] == '^') {
                    i++;
                    switch (input[i]) {
                        case 'b':
                            column = 0;
                            break;
                        case 'c':
                            clear_terminal();
                            break;
                        case 'd':
                            row = min(row + 1, 9);
                            break;
                        case 'e':
                            for (j = column; j < 10; j++)
                                terminal[row][j] = ' ';
                            break;
                        case 'h':
                            row = column = 0;
                            break;
                        case 'i':
                            mode = 1;
                            break;
                        case 'l':
                            column = max(0, column - 1);
                            break;
                        case 'o':
                            mode = 0;
                            break;
                        case 'r':
                            column = min(column + 1, 9);
                            break;
                        case 'u':
                            row = max(0, row - 1);
                            break;
                        case '^':
                            write_character('^', row, column, mode);
                            column = min(column + 1, 9);
                            break;
                        default:
                            row = input[i] - '0';
                            i++;
                            column = input[i] - '0';
                            break;
                    }
                } else {
                    write_character(input[i], row, column, mode);
                    column = min(column + 1, 9);
                }
            }
        }

        cout << "Case " << case_number << "\n+----------+\n";

        for (i = 0; i < 10; i++) {
            cout << "|";

            for (j = 0; j < 10; j++)
                cout << terminal[i][j];

            cout << "|\n";
        }
        cout << "+----------+\n";
    }

    return 0;
}