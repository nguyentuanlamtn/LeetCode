﻿#include <iostream>

bool isPowerOfThree(int n) {
    // Nếu n <= 0, chắc chắn không phải là lũy thừa của 3
    if (n <= 0) {
        return false;
    }

    // Chia liên tục n cho 3 cho đến khi không chia hết nữa
    while (n % 3 == 0) {
        n /= 3;
    }

    // Nếu kết quả cuối cùng là 1, thì n là lũy thừa của 3
    return n == 1;
}

int main() {
    int n = 27; // Ví dụ với n = 27
    if (isPowerOfThree(n)) {
        std::cout << "True\n";  // 27 là lũy thừa của 3
    }
    else {
        std::cout << "False\n"; // 27 không phải lũy thừa của 3
    }

    return 0;
}
