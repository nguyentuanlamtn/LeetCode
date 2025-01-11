#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm duyệt trước (không đệ quy)
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result; // Nếu cây rỗng, trả về danh sách rỗng

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();
        result.push_back(current->val); // Thăm nút gốc

        // Đẩy cây con bên phải vào ngăn xếp trước, sau đó đến cây con bên trái
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }

    return result;
}

int main() {
    // Tạo cây nhị phân
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Lấy kết quả duyệt trước
    vector<int> result = preorderTraversal(root);

    // In kết quả
    cout << "Pre-approval: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
