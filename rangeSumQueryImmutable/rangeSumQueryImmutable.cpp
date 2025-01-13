#include <iostream>
#include <vector>

class NumArray {
private:
    std::vector<int> prefix; // Mảng tiền tố để lưu tổng các phần tử

public:
    // Khởi tạo đối tượng bằng mảng số nguyên nums
    NumArray(const std::vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0); // Mảng tiền tố có kích thước n + 1
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i]; // Tính tổng tiền tố
        }
    }

    // Trả về tổng các phần tử giữa left và right
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    std::vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray numArray(nums);

    // Các truy vấn ví dụ
    std::cout << numArray.sumRange(0, 2) << "\n"; // Output: 1
    std::cout << numArray.sumRange(2, 5) << "\n"; // Output: -1
    std::cout << numArray.sumRange(0, 5) << "\n"; // Output: -3

    return 0;
}
