#include <iostream>
#include <algorithm>
using namespace std;

// Định nghĩa cấu trúc TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Hàm để tính chiều cao của cây và kiểm tra xem cây có cân bằng không
int height(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Nếu cây rỗng, chiều cao là 0
    }

    // Tính chiều cao của cây con trái và phải
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Nếu một trong hai cây con không cân bằng, trả về -1 để báo lỗi
    if (leftHeight == -1 || rightHeight == -1) {
        return -1;
    }

    // Nếu chênh lệch chiều cao giữa hai cây con vượt quá 1, cây không cân bằng
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Trả về -1 để báo cây không cân bằng
    }

    // Trả về chiều cao của cây hiện tại
    return 1 + max(leftHeight, rightHeight);
}

// Hàm kiểm tra xem cây có cân bằng về chiều cao không
bool isBalanced(TreeNode* root) {
    return height(root) != -1; // Nếu height trả về -1, cây không cân bằng
}

int main() {
    // Tạo cây nhị phân:
    //         1
    //        / \
    //       2   2
    //      / \
    //     3   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(3));
    root->right = new TreeNode(2);

    if (isBalanced(root)) {
        cout << "Height balancing tree." << endl;
    }
    else {
        cout << "Tree height is not balanced." << endl;
    }

    return 0;
}
