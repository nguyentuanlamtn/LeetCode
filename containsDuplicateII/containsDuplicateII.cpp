#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
using namespace std;


//Sử dụng unordered_map
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> indexMap;

    for (int i = 0; i < nums.size(); ++i) {
        if (indexMap.count(nums[i]) && i - indexMap[nums[i]] <= k) {
            return true; // Tìm thấy nums[i] xuất hiện trước đó với khoảng cách <= k
        }
        // Cập nhật chỉ số mới nhất của nums[i]
        indexMap[nums[i]] = i;
    }

    return false; // Không tìm thấy cặp nào thoả mãn
}

//Sử dụng Sliding Window với unordered_set
//bool containsNearbyDuplicate(vector<int>& nums, int k) {
//    unordered_set<int> window;
//
//    for (int i = 0; i < nums.size(); ++i) {
//        if (window.count(nums[i])) {
//            return true; // Tìm thấy phần tử trùng trong cửa sổ
//        }
//        // Thêm phần tử hiện tại vào cửa sổ
//        window.insert(nums[i]);
//
//        // Nếu kích thước cửa sổ vượt quá k, loại bỏ phần tử cũ nhất
//        if (window.size() > k) {
//            window.erase(nums[i - k]);
//        }
//    }
//
//    return false; // Không tìm thấy cặp nào thoả mãn
//}

int main() {
    vector<int> nums1 = { 1, 2, 3, 1 };
    int k1 = 3;
    vector<int> nums2 = { 1, 0, 1, 1 };
    int k2 = 1;
    vector<int> nums3 = { 1, 2, 3, 1, 2, 3 };
    int k3 = 2;

    cout << boolalpha;
    cout << "Example 1: " << containsNearbyDuplicate(nums1, k1) << endl; // true
    cout << "Example 2: " << containsNearbyDuplicate(nums2, k2) << endl; // true
    cout << "Example 3: " << containsNearbyDuplicate(nums3, k3) << endl; // false

    return 0;
}
