#include <iostream>
using namespace std;

// Giả sử số tôi chọn được nhập từ bàn phím
int pick; // Số tôi chọn

// API guess được định nghĩa để so sánh với số tôi chọn
int guess(int num) {
    if (num < pick) return 1;  // num nhỏ hơn pick
    if (num > pick) return -1; // num lớn hơn pick
    return 0; // num bằng pick
}

int guessNumber(int n) {
    int left = 1, right = n;

    while (left <= right) {
        // Tính mid một cách an toàn
        int mid = left + (right - left) / 2;

        int result = guess(mid);

        if (result == 0) {
            return mid;  // Nếu guess trả về 0, tức là đã đoán đúng.
        }
        else if (result == -1) {
            right = mid - 1;  // Nếu guess trả về -1, giảm phạm vi tìm kiếm.
        }
        else {
            left = mid + 1;   // Nếu guess trả về 1, tăng phạm vi tìm kiếm.
        }
    }

    return -1;  // Chỉ trả về nếu không tìm được kết quả, nhưng trong bài toán này thì luôn có số cần tìm.
}

int main() {
    int n;
    cout << "Enter value n: ";
    cin >> n;

    // Nhập số tôi chọn (pick) từ bàn phím
    cout << "Enter the number I choose (pick): ";
    cin >> pick;

    int result = guessNumber(n);
    cout << "The number I chose is: " << result << endl;

    return 0;
}
