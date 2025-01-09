#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // Đi đến cây con bên trái sâu nhất
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        // Xử lý nút trên cùng của ngăn xếp
        current = s.top();
        s.pop();
        result.push_back(current->val);
        // Chuyển sang cây con bên phải
        current = current->right;
    }

    return result;
}

int main() {
    // Tạo cây nhị phân:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    // In kết quả
    cout << "Intermediate order censorship: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
