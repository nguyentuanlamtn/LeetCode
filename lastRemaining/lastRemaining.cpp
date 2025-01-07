#include <iostream>
using namespace std;

int eliminationGame(int n) {
    int remaining = n;
    bool left_to_right = true;  // Biến này dùng để theo dõi hướng loại bỏ (lẻ hoặc chẵn)

    while (remaining > 1) {
        if (left_to_right) {
            // Nếu loại bỏ số ở vị trí chẵn, số còn lại sẽ là số lẻ.
            remaining = remaining / 2;
        }
        else {
            // Nếu loại bỏ số ở vị trí lẻ, số còn lại sẽ là số chẵn.
            remaining = remaining / 2;
            if (n % 2 == 1) {
                remaining += 1;
            }
        }
        left_to_right = !left_to_right;  // Đổi hướng loại bỏ cho vòng tiếp theo
    }

    return remaining;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = eliminationGame(n);
    cout << "The last remaining number is: " << result << endl;

    return 0;
}
