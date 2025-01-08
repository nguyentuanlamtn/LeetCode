#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // k là con trỏ chỉ số phần tử hợp lệ

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Di chuyển phần tử không bằng val về vị trí k
                k++;               // Tăng k lên
            }
        }

        return k;  // Trả về số phần tử không bằng val
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 3, 2, 2, 3, 4, 5, 3 };  // Mảng đầu vào
    int val = 3;  // Giá trị cần xóa

    int k = solution.removeElement(nums, val);  // Gọi hàm xử lý
    cout << "Number of elements after removal: " << k << endl;

    cout << "Array after removal: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";  // In các phần tử không phải val
    }
    cout << endl;

    return 0;
}
