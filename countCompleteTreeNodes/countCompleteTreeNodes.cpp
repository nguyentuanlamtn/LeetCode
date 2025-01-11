#include <iostream>
#include <cmath> // Dùng cho pow()
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm tính chiều cao của cây (đi sâu vào con trái)
//int computeHeight(TreeNode* node) {
//    int height = 0;
//    while (node != nullptr) {
//        ++height;
//        node = node->left;
//    }
//    return height;
//}
//
//int countNodes(TreeNode* root) {
//    if (!root) return 0; // Cây rỗng, số nút là 0
//
//    int leftHeight = computeHeight(root->left);
//    int rightHeight = computeHeight(root->right);
//
//    if (leftHeight == rightHeight) {
//        // Cây con trái là cây hoàn chỉnh
//        return (1 << leftHeight) + countNodes(root->right); // 2^leftHeight + số nút cây con phải
//    }
//    else {
//        // Cây con phải là cây hoàn chỉnh
//        return (1 << rightHeight) + countNodes(root->left); // 2^rightHeight + số nút cây con trái
//    }
//}

int getHeight(TreeNode* root) {
    int height = 0;
    while (root) {
        ++height;
        root = root->left;
    }
    return height;
}

// Hàm đếm số nút trong cây
int countNodes(TreeNode* root) {
    if (!root) return 0; // Nếu cây rỗng, trả về 0

    // Tính chiều cao cây con trái và phải
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight == rightHeight) {
        // Cây con trái là cây hoàn chỉnh
        // Số nút cây con trái: 2^leftHeight - 1, cộng thêm nút gốc và đệ quy cây con phải
        return (1 << leftHeight) + countNodes(root->right);
    }
    else {
        // Cây con phải là cây hoàn chỉnh
        // Số nút cây con phải: 2^rightHeight - 1, cộng thêm nút gốc và đệ quy cây con trái
        return (1 << rightHeight) + countNodes(root->left);
    }
}



int main() {
    // Tạo một cây nhị phân hoàn chỉnh
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes: " << countNodes(root) << endl;

    return 0;
}
