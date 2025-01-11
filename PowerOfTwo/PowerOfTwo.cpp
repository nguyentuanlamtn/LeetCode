#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false; // Số âm và 0 không phải là lũy thừa của 2
    while (n % 2 == 0) { // Lặp lại khi n chia hết cho 2
        n /= 2;
    }
    return n == 1; // Nếu n trở về 1, nó là lũy thừa của 2
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (isPowerOfTwo(n) ? "True" : "False") << endl; // Output: True
    }
    return 0;
}
