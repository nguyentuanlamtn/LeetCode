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

// Hàm tính độ sâu tối đa bằng đệ quy
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Nếu cây rỗng, độ sâu là 0
    }
    int leftDepth = maxDepth(root->left);  // Tính độ sâu cây con trái
    int rightDepth = maxDepth(root->right); // Tính độ sâu cây con phải
    return 1 + max(leftDepth, rightDepth); // Độ sâu là 1 + độ sâu lớn nhất giữa cây trái và cây phải
}

int main() {
    // Tạo cây nhị phân:
    //         3
    //        / \
    //       9  20
    //          /  \
    //         15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    cout << "Maximum tree depth: " << maxDepth(root) << endl;

    return 0;
}


//Phương pháp duyệt theo chiều rộng

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
//// Hàm tính độ sâu tối đa bằng duyệt BFS
//int maxDepth(TreeNode* root) {
//    if (root == nullptr) {
//        return 0; // Nếu cây rỗng, độ sâu là 0
//    }
//
//    queue<TreeNode*> q;
//    q.push(root); // Đưa gốc vào hàng đợi
//    int depth = 0;
//
//    while (!q.empty()) {
//        int levelSize = q.size(); // Số nút ở cấp hiện tại
//        for (int i = 0; i < levelSize; i++) {
//            TreeNode* node = q.front();
//            q.pop();
//            if (node->left != nullptr) {
//                q.push(node->left); // Thêm cây con trái vào hàng đợi
//            }
//            if (node->right != nullptr) {
//                q.push(node->right); // Thêm cây con phải vào hàng đợi
//            }
//        }
//        depth++; // Hoàn thành một cấp, tăng độ sâu
//    }
//
//    return depth;
//}
//
//int main() {
//    // Tạo cây nhị phân:
//    //         3
//    //        / \
//    //       9  20
//    //          /  \
//    //         15   7
//    TreeNode* root = new TreeNode(3);
//    root->left = new TreeNode(9);
//    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
//
//    cout << "Độ sâu tối đa của cây: " << maxDepth(root) << endl;
//
//    return 0;
//}

