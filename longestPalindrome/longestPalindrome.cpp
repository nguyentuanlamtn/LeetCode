#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        int length = 0;
        bool hasOdd = false;

        // Đếm số lần xuất hiện của mỗi ký tự
        for (char c : s) {
            charCount[c]++;
        }

        // Duyệt qua bảng đếm
        for (auto pair : charCount) {
            int count = pair.second;

            // Thêm số chẵn vào độ dài chuỗi palindrome
            if (count % 2 == 0) {
                length += count;
            }
            else {
                // Nếu là số lẻ, cộng (count - 1)
                length += count - 1;
                hasOdd = true;  // Đánh dấu có ký tự lẻ
            }
        }

        // Nếu có ký tự lẻ, thêm 1 để đặt ở trung tâm
        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = solution.longestPalindrome(s);
    cout << "Length of longest palindrome: " << result << endl;

    return 0;
}
