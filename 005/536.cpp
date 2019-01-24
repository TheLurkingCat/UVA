/*
    樹的遍歷
    時間複雜度: O(N^2)
*/
#include <iostream>
#include <string>

using namespace std;

void post_order(int inorder_start, int inorder_end, int&& preorder_head, const string& inorder, const string& preorder) {
    if (inorder_start < inorder_end) {
        int root = inorder_start, left_chlid_size;

        while (inorder[root] != preorder[preorder_head])
            root++;  // 找當前的根節點

        left_chlid_size = root - inorder_start;  //左子樹內點的個數

        post_order(inorder_start, inorder_start + left_chlid_size, preorder_head + 1, inorder, preorder);  // 左子樹
        post_order(root + 1, inorder_end, preorder_head + left_chlid_size + 1, inorder, preorder);         // 右子樹

        cout << inorder[root];  // 後序
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string preorder, inorder;
    while (cin >> preorder >> inorder) {
        post_order(0, preorder.length(), 0, inorder, preorder);
        cout << "\n";
    }
    return 0;
}