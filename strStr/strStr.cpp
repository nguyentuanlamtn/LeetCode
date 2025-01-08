#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // Nếu needle rỗng, trả về 0
        int n = haystack.size();
        int m = needle.size();

        // Nếu needle dài hơn haystack, không thể tồn tại
        if (m > n) return -1;

        // Duyệt qua haystack để tìm needle
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i; // Trả về chỉ số nếu tìm thấy
            }
        }

        return -1; // Không tìm thấy
    }
};

int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";

    int index = solution.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl;

    return 0;
}
