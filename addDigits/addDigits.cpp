#include <iostream>
using namespace std;

//Phương pháp Digital Root
//class Solution {
//public:
//    int addDigits(int num) {
//        if (num == 0) return 0;
//        return 1 + (num - 1) % 9; // Digital Root
//    }
//};
//phương pháp lặp đi lặp lại
class Solution {
public:
    int addDigits(int num) {
        // Lặp cho đến khi num chỉ còn một chữ số
        while (num >= 10) {
            int sum = 0;
            // Cộng tất cả các chữ số của num
            while (num > 0) {
                sum += num % 10;  // Lấy chữ số cuối cùng và cộng vào sum
                num /= 10;         // Loại bỏ chữ số cuối cùng
            }
            num = sum;  // Cập nhật num với tổng của các chữ số
        }
        return num;
    }
};

int main() {
    Solution solution;
    int num = 38;

    int result = solution.addDigits(num);
    cout << result << endl;  // Kết quả: 2 (3 + 8 = 11, 1 + 1 = 2)

    return 0;
}
