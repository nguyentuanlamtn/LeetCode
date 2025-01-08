#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // Bỏ qua các khoảng trắng ở cuối
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Đếm độ dài từ cuối cùng
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        Solution solution;
        string s;
        // Nhập chuỗi từ bàn phím
        cout << "Enter the string: ";   
        getline(cin, s);

        // Gọi hàm và in kết quả
        int result = solution.lengthOfLastWord(s);
        cout << "Length of the last word: " << result << endl;
        
    }

    return 0;
}
