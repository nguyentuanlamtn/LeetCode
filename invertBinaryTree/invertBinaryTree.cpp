#include <iostream>
using namespace std;

// Định nghĩa cấu trúc nút cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm đảo ngược cây nhị phân
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr; // Nếu cây rỗng, không cần đảo ngược
    }

    // Đảo ngược cây con trái và cây con phải
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    // Hoán đổi cây con trái và cây con phải
    root->left = right;
    root->right = left;

    return root; // Trả về gốc của cây đã đảo ngược
}

// Hàm in cây nhị phân (tiền thứ tự)
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Tạo một cây nhị phân mẫu
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree (Pre-order): ";
    printTree(root);
    cout << endl;

    // Đảo ngược cây
    TreeNode* invertedRoot = invertTree(root);

    cout << "Inverted tree (Pre-order): ";
    printTree(invertedRoot);
    cout << endl;

    return 0;
}
