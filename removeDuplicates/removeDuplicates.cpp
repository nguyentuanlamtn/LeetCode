#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) 
            return 0; // Nếu mảng rỗng, trả về 0

        int i = 1; // Con trỏ cho vị trí lưu phần tử duy nhất
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j]; // Cập nhật phần tử duy nhất tại vị trí i
                i++;               // Di chuyển con trỏ i
            }
        }

        return i; // Số phần tử duy nhất
    }
};

int main() {
    // Ví dụ minh họa
    vector<int> nums = { 1, 1, 2, 2, 3, 3, 4, 5, 5 };

    Solution solution;
    int k = solution.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after processing: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
