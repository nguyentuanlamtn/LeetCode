#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        count += (n & 1); // Nếu bit thấp nhất là 1, tăng count
        n >>= 1;           // Dịch bit sang phải
    }
    return count;
}

int main() {
    uint32_t n = 11; // Số 11 có biểu diễn nhị phân là 1011
    cout << "Hamming weight of: " << n << " là: " << hammingWeight(n) << endl;
    return 0;
}
