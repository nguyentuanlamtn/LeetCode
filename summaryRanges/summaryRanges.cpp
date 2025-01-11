#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(const vector<int>& nums) {
    vector<string> result;

    if (nums.empty()) {
        return result; // Nếu mảng rỗng, trả về danh sách rỗng
    }

    int start = nums[0]; // Bắt đầu từ phần tử đầu tiên
    for (int i = 1; i <= nums.size(); ++i) {
        // Kiểm tra điều kiện kết thúc phạm vi: nếu là phần tử cuối cùng hoặc không còn tiếp nối
        if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
            if (start == nums[i - 1]) {
                result.push_back(to_string(start)); // Chỉ có một phần tử trong phạm vi
            }
            else {
                result.push_back(to_string(start) + "->" + to_string(nums[i - 1])); // Có nhiều phần tử trong phạm vi
            }

            // Cập nhật start cho phạm vi mới
            if (i < nums.size()) {
                start = nums[i];
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 0, 1, 2, 4, 5, 7 };

    vector<string> result = summaryRanges(nums);

    cout << "Ranges: ";
    for (const string& range : result) {
        cout << range << " ";
    }
    cout << endl;

    return 0;
}
