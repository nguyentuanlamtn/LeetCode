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

// Hàm tính độ sâu tối thiểu của cây
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Nếu cây rỗng, độ sâu là 0
    }

    // Nếu chỉ có một cây con (trái hoặc phải), chỉ cần xét chiều sâu của nó
    if (root->left == nullptr && root->right != nullptr) {
        return 1 + minDepth(root->right);
    }
    if (root->right == nullptr && root->left != nullptr) {
        return 1 + minDepth(root->left);
    }

    // Nếu có cả hai cây con trái và phải, tính độ sâu của cả hai cây con và trả về độ sâu tối thiểu
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    // Tạo cây nhị phân:
    //         1
    //        / \
    //       2   3
    //      /
    //     4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), nullptr);
    root->right = new TreeNode(3);

    // Tính độ sâu tối thiểu của cây
    cout << "Minimum tree depth: " << minDepth(root) << endl;

    return 0;
}
