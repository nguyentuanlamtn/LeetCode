#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = ""; // Chuỗi lưu kết quả
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0; // Giá trị nhớ

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry; // Bắt đầu với giá trị nhớ

            if (i >= 0) {
                sum += a[i] - '0'; // Thêm chữ số từ chuỗi a
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Thêm chữ số từ chuỗi b
                j--;
            }

            result += (sum % 2) + '0'; // Lấy phần dư (bit nhị phân) và thêm vào kết quả
            carry = sum / 2;          // Cập nhật giá trị nhớ
        }

        reverse(result.begin(), result.end()); // Đảo ngược chuỗi kết quả
        return result;
    }
};

int main() {
    Solution solution;

    string a, b;
    cout << "Enter binary string a: ";
    cin >> a;
    cout << "Enter binary string b: ";
    cin >> b;

    string result = solution.addBinary(a, b);
    cout << "Sum of binary strings: " << result << endl;

    return 0;
}
