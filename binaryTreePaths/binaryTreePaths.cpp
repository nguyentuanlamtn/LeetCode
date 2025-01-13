#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root) dfs(root, "", paths); // Nếu cây không rỗng, bắt đầu đệ quy
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        path += to_string(node->val); // Thêm giá trị của nút hiện tại vào đường dẫn
        if (!node->left && !node->right) { // Nếu là nút lá
            paths.push_back(path);
        }
        else {
            path += "->"; // Thêm dấu nối khi chưa tới lá
            if (node->left) dfs(node->left, path, paths);
            if (node->right) dfs(node->right, path, paths);
        }
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);

    for (const string& path : result) {
        cout << path << endl;
    }

    return 0;
}
