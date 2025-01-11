#include <iostream>
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

// Hàm đệ quy kiểm tra xem có đường dẫn từ gốc đến lá sao cho tổng các giá trị bằng targetSum không
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return false;  // Nếu cây rỗng, không có đường dẫn
    }

    // Nếu là lá, kiểm tra tổng
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;  // Nếu là lá, kiểm tra giá trị của nó có bằng targetSum không
    }

    // Đệ quy kiểm tra các cây con trái và phải
    targetSum -= root->val;  // Giảm targetSum đi giá trị của nút hiện tại
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);  // Kiểm tra cây con trái và phải
}

int main() {
    // Tạo cây nhị phân:
    //         5
    //        / \
    //       4   8
    //      /   / \
    //     11  13  4
    //    /  \      / \
    //   7    2    5   1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum)) {
        cout << "A tree with root-to-leaf paths has a total of: " << targetSum << endl;
    }
    else {
        cout << "A tree has no path from root to leaf with sum equal to: " << targetSum << endl;
    }

    return 0;
}
