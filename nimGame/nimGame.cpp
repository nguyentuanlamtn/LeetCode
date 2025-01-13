#include <iostream>

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    int n = 7; // Ví dụ số lượng đá ban đầu
    if (canWinNim(n)) {
        std::cout << "True\n"; // Bạn có thể thắng
    }
    else {
        std::cout << "False\n"; // Bạn không thể thắng
    }
    return 0;
}
