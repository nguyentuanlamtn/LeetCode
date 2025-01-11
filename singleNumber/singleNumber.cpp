#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR tất cả các phần tử
    }
    return result;
}

int main() {
    vector<int> nums = { 4, 1, 2, 1, 2 };
    cout << "The only element is: " << singleNumber(nums) << endl;
    return 0;
}
