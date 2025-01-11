#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
        // Dịch kết quả sang trái để chuẩn bị chỗ cho bit tiếp theo
        result <<= 1;
        // Lấy bit thấp nhất của n và thêm vào result
        result |= (n & 1);
        // Dịch n sang phải để tiếp tục kiểm tra bit tiếp theo
        n >>= 1;
    }
    return result;
}

int main() {
    uint32_t n = 43261596;  // Ví dụ với một số
    uint32_t reversed = reverseBits(n);
    cout << "Bitwise inversion of " << n << " là: " << reversed << endl;
    return 0;
}
