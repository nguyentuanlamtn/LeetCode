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

// Hàm duyệt sau (không đệ quy)
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result; // Nếu cây rỗng, trả về danh sách rỗng

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);   // Đẩy cây con bên trái
        if (node->right) s1.push(node->right); // Đẩy cây con bên phải
    }

    // Đảo ngược kết quả trong ngăn xếp thứ hai
    while (!s2.empty()) {
        result.push_back(s2.top()->val);
        s2.pop();
    }

    return result;
}

int main() {
    // Tạo cây nhị phân
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Lấy kết quả duyệt sau
    vector<int> result = postorderTraversal(root);

    // In kết quả
    cout << "Post-processing: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
