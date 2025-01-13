#include <iostream>
#include <string>
#include <algorithm> // Để sử dụng hàm reverse
using namespace std;

class Solution {
public:
    bool isReverse(string s, string t) {
        if (s.length() != t.length()) return false;

        // Đảo ngược chuỗi t
        reverse(t.begin(), t.end());

        // So sánh s với chuỗi t đã đảo ngược
        return s == t;
    }
};

int main() {
    Solution solution;

    string s = "hello";
    string t = "olleh";

    bool result = solution.isReverse(s, t);
    cout << (result ? "True" : "False") << endl; // Kết quả: True

    return 0;
}
