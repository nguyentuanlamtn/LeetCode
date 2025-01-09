#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa cấu trúc TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Hàm đệ quy để chuyển đổi mảng thành cây tìm kiếm nhị phân cân bằng
TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr; // Nếu chỉ số trái lớn hơn phải, tức là không còn phần tử
    }

    int mid = left + (right - left) / 2; // Tìm phần tử giữa mảng
    TreeNode* root = new TreeNode(nums[mid]); // Tạo nút với giá trị giữa mảng

    // Tạo cây con trái và phải bằng cách đệ quy
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

// Hàm giúp gọi đệ quy từ đầu
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// Hàm để in cây theo kiểu duyệt trung gian (in-order traversal)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> nums = { -10, -3, 0, 5, 9 };

    // Chuyển đổi mảng thành cây tìm kiếm nhị phân cân bằng
    TreeNode* root = sortedArrayToBST(nums);

    // Duyệt cây theo thứ tự trung gian để in ra kết quả
    cout << "Tree traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
