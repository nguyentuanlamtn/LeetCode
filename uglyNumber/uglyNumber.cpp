#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // Số âm và số 0 không phải là số xấu
        while (n % 2 == 0) n /= 2; // Chia cho 2
        while (n % 3 == 0) n /= 3; // Chia cho 3
        while (n % 5 == 0) n /= 5; // Chia cho 5
        return n == 1; // Nếu còn lại 1, thì n là số xấu
    }
};

int main() {
    Solution solution;

    int n = 6;
    bool result = solution.isUgly(n);
    cout << (result ? "True" : "False") << endl; // Kết quả: True (6 = 2 * 3)

    n = 14;
    result = solution.isUgly(n);
    cout << (result ? "True" : "False") << endl; // Kết quả: False (14 có ước là 7)

    return 0;
}
