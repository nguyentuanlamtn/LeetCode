#include <iostream>
#include <cctype>  // Để sử dụng isalnum() và tolower()
#include <string>
using namespace std;

bool isPalindrome(string s) {
    // Chuẩn hóa chuỗi: loại bỏ ký tự không phải chữ cái và số, và chuyển thành chữ thường
    string filtered = "";
    for (char c : s) {
        if (isalnum(c)) {  // Kiểm tra nếu ký tự là chữ cái hoặc số
            filtered += tolower(c);  // Chuyển thành chữ thường
        }
    }

    // Kiểm tra xem chuỗi đã chuẩn hóa có phải là palindrome không
    int left = 0, right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cout << "Enter string: ";
        getline(cin, s);  // Đọc chuỗi bao gồm cả khoảng trắng

        if (isPalindrome(s)) {
            cout << "The string is palindrome.!" << endl;
        }
        else {
            cout << "The string is not a palindrome!" << endl;
        }
    }

    return 0;
}
