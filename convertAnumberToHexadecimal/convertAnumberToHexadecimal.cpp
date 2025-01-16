#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        // Nếu số là 0, trả về "0"
        if (num == 0) return "0";

        // Mảng ký tự để biểu diễn các chữ số thập lục phân
        const char hexDigits[] = "0123456789abcdef";
        string result = "";

        // Chuyển số sang kiểu không dấu để xử lý bù hai tự động
        unsigned int n = num;

        // Lặp qua tối đa 8 lần (vì số 32 bit có thể biểu diễn bằng 8 ký tự hex)
        while (n > 0) {
            int digit = n & 15;  // Lấy 4 bit cuối cùng
            result += hexDigits[digit];  // Thêm ký tự tương ứng vào chuỗi kết quả
            n >>= 4;  // Dịch số sang phải 4 bit
        }

        // Đảo ngược chuỗi kết quả để có đúng thứ tự
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution solution;

    int num;
    cout << "Enter an integer: ";
    cin >> num;

    string hexString = solution.toHex(num);
    cout << "Hexadecimal representation: " << hexString << endl;

    return 0;
}
