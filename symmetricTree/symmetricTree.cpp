//Phương pháp đệ quy

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

// Hàm kiểm tra hai cây có đối xứng nhau hay không
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return true; // Cả hai cây đều rỗng
    }
    if (t1 == nullptr || t2 == nullptr) {
        return false; // Một trong hai cây rỗng
    }
    return (t1->val == t2->val) // Giá trị nút gốc giống nhau
        && isMirror(t1->left, t2->right) // Cây con trái của t1 đối xứng cây con phải của t2
        && isMirror(t1->right, t2->left); // Cây con phải của t1 đối xứng cây con trái của t2
}

// Hàm kiểm tra cây có đối xứng hay không
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true; // Cây rỗng là đối xứng
    return isMirror(root->left, root->right);
}

int main() {
    // Tạo cây nhị phân:
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    if (isSymmetric(root)) {
        cout << "Symmetrical tree." << endl;
    }
    else {
        cout << "Asymmetrical tree." << endl;
    }

    return 0;
}

// Phương pháp duyệt vòng lặp

//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//// Hàm kiểm tra cây có đối xứng hay không
//bool isSymmetric(TreeNode* root) {
//    if (root == nullptr) return true; // Cây rỗng là đối xứng
//
//    queue<TreeNode*> q;
//    q.push(root->left);
//    q.push(root->right);
//
//    while (!q.empty()) {
//        TreeNode* t1 = q.front();
//        q.pop();
//        TreeNode* t2 = q.front();
//        q.pop();
//
//        if (t1 == nullptr && t2 == nullptr) continue; // Cả hai nút rỗng, tiếp tục kiểm tra
//        if (t1 == nullptr || t2 == nullptr) return false; // Một trong hai nút rỗng
//        if (t1->val != t2->val) return false; // Giá trị không giống nhau
//
//        // Đẩy các cặp cây con đối xứng vào hàng đợi
//        q.push(t1->left);
//        q.push(t2->right);
//        q.push(t1->right);
//        q.push(t2->left);
//    }
//
//    return true;
//}
//
//int main() {
//    // Tạo cây nhị phân:
//    //        1
//    //       / \
//    //      2   2
//    //     / \ / \
//    //    3  4 4  3
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
//    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));
//
//    if (isSymmetric(root)) {
//        cout << "Cây đối xứng." << endl;
//    }
//    else {
//        cout << "Cây không đối xứng." << endl;
//    }
//
//    return 0;
//}
