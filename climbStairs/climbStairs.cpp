#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "The number of ways to climb to the top is: " << climbStairs(n) << endl;
    return 0;
}
