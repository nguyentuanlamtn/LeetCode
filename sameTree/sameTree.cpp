#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Hàm kiểm tra hai cây có giống nhau hay không
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true; // Cả hai cây đều rỗng
    }
    if (p == nullptr || q == nullptr) {
        return false; // Một trong hai cây rỗng
    }
    if (p->val != q->val) {
        return false; // Giá trị tại nút gốc không giống nhau
    }

    // Đệ quy kiểm tra cây con trái và cây con phải
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Tạo hai cây nhị phân
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Kiểm tra xem hai cây có giống nhau không
    if (isSameTree(tree1, tree2)) {
        cout << "Two identical trees." << endl;
    }
    else {
        cout << "Two trees are not the same." << endl;
    }

    return 0;
}
