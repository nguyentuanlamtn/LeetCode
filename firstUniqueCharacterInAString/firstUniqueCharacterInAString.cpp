#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;

        // Bước 1: Đếm số lần xuất hiện của mỗi ký tự trong chuỗi
        for (char c : s) {
            charCount[c]++;
        }

        // Bước 2: Duyệt qua chuỗi để tìm ký tự đầu tiên có số lần xuất hiện là 1
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;  // Trả về chỉ số của ký tự đầu tiên không lặp lại
            }
        }

        return -1;  // Nếu không có ký tự không lặp lại, trả về -1
    }
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution;
        string s;

        cout << "Enter string s: ";
        cin >> s;

        int result = solution.firstUniqChar(s);

        if (result != -1) {
            cout << "The first non-repeating character has an index: " << result << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
