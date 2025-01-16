#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int num : nums2) {
        if (set1.count(num)) {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
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

        vector<int> result = intersection(nums1, nums2);

        cout << "Intersection of two arrays: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
