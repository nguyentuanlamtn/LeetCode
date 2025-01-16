#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> countMap;
    vector<int> result;

    // Đếm tần suất của các phần tử trong nums1
    for (int num : nums1) {
        countMap[num]++;
    }

    // Duyệt qua nums2 và kiểm tra xem phần tử có trong countMap không
    for (int num : nums2) {
        if (countMap[num] > 0) {
            result.push_back(num);  // Thêm phần tử vào kết quả
            countMap[num]--;  // Giảm số lần xuất hiện của phần tử trong nums1
        }
    }

    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of elements in the array nums1: ";
    cin >> n;

    vector<int> nums1(n);
    cout << "Enter the elements of the array nums1: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the number of elements in the array nums2: ";
    cin >> m;

    vector<int> nums2(m);
    cout << "Enter the elements of the array nums2: ";
    for (int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }

    vector<int> result = intersect(nums1, nums2);

    cout << "Intersection of two arrays: ";
    for (int num : result) {
        cout <<  num << " ";
    }
    cout << endl;

    return 0;
}
