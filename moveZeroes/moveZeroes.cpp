#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0; // Vị trí của phần tử không phải 0

        // Duyệt qua mảng
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Hoán đổi nums[i] với nums[lastNonZeroFoundAt]
                swap(nums[i], nums[lastNonZeroFoundAt]);
                lastNonZeroFoundAt++; // Di chuyển con trỏ lastNonZeroFoundAt
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 1, 0, 3, 12 };

    solution.moveZeroes(nums);

    // In mảng sau khi di chuyển các số 0 về cuối
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
