#include <iostream>
#include <unordered_set>
using namespace std;

// Hàm tính tổng bình phương các chữ số của n
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10; // Lấy chữ số cuối
        sum += digit * digit; // Thêm bình phương của chữ số
        n /= 10; // Loại bỏ chữ số cuối
    }
    return sum;
}

// Hàm kiểm tra xem số n có phải số hạnh phúc không
bool isHappy(int n) {
    unordered_set<int> seen; // Lưu các số đã xuất hiện
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n); // Lưu giá trị hiện tại
        n = sumOfSquares(n); // Tính tổng bình phương các chữ số
    }
    return n == 1; // Nếu n = 1, thì là số hạnh phúc
}

int main() {
    int n = 19; // Ví dụ: 19 là số hạnh phúc
    if (isHappy(n)) {
        cout << n << " is the happy number!" << endl;
    }
    else {
        cout << n << " not a happy number!" << endl;
    }
    return 0;
}
