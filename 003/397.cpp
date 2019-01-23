/*
    模擬、連結串列
    時間複雜度: O(N^2)
*/
#include <iostream>
#include <string>

using namespace std;

string variable;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// 輸出算式
void print(Node* new_num, Node* op) {
    while (new_num->next != NULL) {
        cout << new_num->data << " " << char(op->data) << " ";
        new_num = new_num->next;
        op = op->next;
    }
    cout << variable << "\n";
}

// 找乘除號
Node* get_mul_div(Node* head, int* index) {
    int i;
    for (i = 0; head->next != NULL; i++, head = head->next)
        if (head->data == 42 /* * */ || head->data == 47 /* / */)
            break;
    *index = i;
    return head;
}

Node* index_node(Node* head, int index) {
    for (int i = 0; i < index; i++)
        head = head->next;
    return head;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int num, index;
    char op;

    Node *op_now, *num_now, *num_next, *new_num;

    while (cin >> num >> op) {
        Node *numbers = new Node{0, NULL, NULL}, *operators = new Node{0, NULL, NULL};
        Node *prev_num = numbers, *prev_op = operators;

        do {
            prev_num->data = num;
            prev_op->data = op;

            num_now = new Node{-1, NULL, prev_num};
            op_now = new Node{-1, NULL, prev_op};

            prev_num->next = num_now;
            prev_op->next = op_now;

            prev_num = num_now;
            prev_op = op_now;
        } while (op != '=' && cin >> num >> op);

        cin >> variable;

        op_now = get_mul_div(operators, &index);
        print(numbers, operators);
        // 由左至右計算全部乘法和除法
        while (op_now->next != NULL) {
            num_now = index_node(numbers, index);
            num_next = num_now->next;
            new_num = new Node{0, num_next->next, num_now->prev};
            if (op_now->data == 42)  // 乘法
                new_num->data = num_now->data * num_next->data;
            else
                new_num->data = num_now->data / num_next->data;

            if (num_now->prev == NULL)  // 是第一個
                numbers = new_num;
            else
                num_now->prev->next = new_num;
            if (num_next->next != NULL)  // 不是最後一個
                num_next->next->prev = new_num;
            if (op_now->prev == NULL)  // 是第一個
                operators = op_now->next;
            else
                op_now->prev->next = op_now->next;
            if (op_now->next != NULL)  // 不是最後一個
                op_now->next->prev = op_now->prev;

            // 釋放記憶體
            delete op_now;
            delete num_now;
            delete num_next;

            op_now = get_mul_div(operators, &index);
            print(numbers, operators);
        }

        op_now = operators;
        // 由左而右算加減法
        while (op_now->data != 61) {  // 等號
            num_now = numbers;
            num_next = num_now->next;

            new_num = new Node{0, num_next->next, num_now->prev};
            if (op_now->data == 43)  // 加號
                new_num->data = num_now->data + num_next->data;
            else
                new_num->data = num_now->data - num_next->data;

            // 新的變成開頭
            numbers = new_num;
            operators = op_now->next;

            delete op_now;
            delete num_now;
            delete num_next;

            op_now = operators;
            print(numbers, operators);
        }
        cout << "\n";
    }
}