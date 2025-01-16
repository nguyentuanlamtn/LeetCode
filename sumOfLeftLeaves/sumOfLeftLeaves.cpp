#include <iostream>
using namespace std;

// Định nghĩa cấu trúc nút của cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // Nếu cây rỗng, trả về 0
        if (root == nullptr) return 0;

        int sum = 0;

        // Kiểm tra nếu nút con trái là lá
        if (root->left && isLeaf(root->left)) {
            sum += root->left->val; // Cộng giá trị của lá bên trái
        }

        // Đệ quy vào nhánh trái và nhánh phải
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }

private:
    // Hàm kiểm tra xem một nút có phải là lá hay không
    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};

// Hàm tiện ích để thêm một nút mới vào cây
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Hàm main để kiểm tra
int main() {
    // Tạo cây nhị phân mẫu:
    //         3
    //        / \
    //       9  20
    //          /  \
    //         15   7
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    Solution solution;
    int result = solution.sumOfLeftLeaves(root);

    cout << "The sum of the leaves on the left is: " << result << endl;

    return 0;
}
