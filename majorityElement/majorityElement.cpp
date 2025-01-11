#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 1;

    // Bước 1: Tìm phần tử khả dĩ là phần tử đa số
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Bước 2: Trả về phần tử đa số
    return candidate;
}

int main() {
    vector<int> nums = { 1,4,1,3,2,3,2,3,3 };
    //vector<int> nums = { 2,2,1,1,1,2,2 };
    cout << "The majority element is: " << majorityElement(nums) << endl;
    return 0;
}
