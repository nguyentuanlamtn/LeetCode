#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;  // Tổng dãy số từ 0 đến n
        int arraySum = 0;

        // Tính tổng của các phần tử trong mảng nums
        for (int num : nums) {
            arraySum += num;
        }

        return totalSum - arraySum;  // Sự chênh lệch chính là số thiếu
    }
};


int main() {
    Solution solution;

    vector<int> nums = { 3, 0, 1 };  // Ví dụ mảng nums
    int result = solution.missingNumber(nums);
    cout << "The missing number is: " << result << endl;  // Kết quả: 2

    return 0;
}
