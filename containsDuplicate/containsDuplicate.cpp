#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// Sử dụng unordered_set
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return true; // Đã tìm thấy phần tử trùng lặp
        }
        seen.insert(num);
    }
    return false; // Không tìm thấy phần tử trùng lặp
}
// Sử dụng sắp xếp
//bool containsDuplicate(vector<int>& nums) {
//    sort(nums.begin(), nums.end()); // Sắp xếp mảng
//    for (int i = 1; i < nums.size(); ++i) {
//        if (nums[i] == nums[i - 1]) {
//            return true; // Đã tìm thấy phần tử trùng lặp
//        }
//    }
//    return false; // Không tìm thấy phần tử trùng lặp
//}

int main() {
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    vector<int> nums2 = { 1, 2, 3, 4, 1 };

    cout << boolalpha;
    cout << "Example 1: " << containsDuplicate(nums1) << endl; // false
    cout << "Example 2: " << containsDuplicate(nums2) << endl; // true

    return 0;
}
