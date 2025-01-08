#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid; // Tìm thấy mục tiêu
            }
            else if (nums[mid] < target) {
                low = mid + 1; // Tìm kiếm phía phải
            }
            else {
                high = mid - 1; // Tìm kiếm phía trái
            }
        }

        return low; // Vị trí cần chèn
    }
};

int main() {
    
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution;
        int n, target;

        // Nhập kích thước của mảng
        cout << "Enter the size of the array: ";
        cin >> n;

        // Nhập các phần tử của mảng
        vector<int> nums(n);
        cout << "Enter the sorted elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Nhập giá trị cần tìm hoặc chèn
        cout << "Enter the target value: ";
        cin >> target;

        // Gọi hàm xử lý và in kết quả
        int result = solution.searchInsert(nums, target);
        cout << "Target index or insertion point: " << result << endl;

    }
    return 0;
}
