/*
    連結串列暴力解
    時間複雜度: O(N)
*/
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string word;
    Node *next;
};

int main() {
    Node *head = new Node{"", NULL};
    char c = getchar();

    while (1) {
        if (isdigit(c)) {
            if (c == '0')
                break;

            int i, num = 0;
            Node *now = head, *prev = new Node{"", NULL};
            // 讀取後續數字部分，最後多的那個getchar
            // 剛好會回到最外面迴圈
            while (isdigit(c)) {
                num = num * 10 + c - '0';
                c = getchar();
            }
            // 找到連結串列中的數字
            for (i = 1; i < num; i++) {
                prev = now;
                now = now->next;
            }
            // 如果數字不是1就要把那個node移到第一個
            if (now != head) {
                prev->next = now->next;
                now->next = head;
                head = now;
            }
            // 數字代表的單字會在第一個
            cout << head->word;
        } else if (isalpha(c)) {
            string word;
            // 讀取整個文字
            while (isalpha(c)) {
                word += c;
                c = getchar();
            }

            cout << word;
            // 在連結串列中新增一個節點
            Node *now = new Node{word, head};
            head = now;

        } else {
            putchar(c);
            c = getchar();
        }
    }
    // 釋放掉所有節點的記憶體位置
    Node *temp = head, *t;
    while (temp->next != NULL) {
        t = temp->next;
        delete temp;
        temp = t;
    }
    return 0;
}