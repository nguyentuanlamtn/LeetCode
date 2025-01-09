#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;            // Con trỏ cuối cùng trong nums1 (phần mảng thực sự)
    int p2 = n - 1;            // Con trỏ cuối cùng trong nums2
    int p = m + n - 1;         // Con trỏ cuối cùng trong nums1 (khoảng trống tổng)

    // Kết hợp từ cuối mảng
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        }
        else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // Nếu còn phần tử trong nums2
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}

int main() {
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 }; // nums1 có m + n phần tử, phần cuối là khoảng trống
    int m = 3;  // Số phần tử thực sự trong nums1
    vector<int> nums2 = { 2, 5, 6 }; // nums2 có n phần tử
    int n = 3;  // Số phần tử trong nums2

    merge(nums1, m, nums2, n);

    // In kết quả sau khi gộp
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
