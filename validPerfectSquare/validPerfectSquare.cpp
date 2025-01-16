#include <iostream>
using namespace std;

//bool isPerfectSquare(int num) {
//    int i = 1;
//    while (i * i <= num) {
//        if (i * i == num) {
//            return true;  // Nếu i * i bằng num, tức là num là số chính phương
//        }
//        i++;
//    }
//    return false;  // Nếu không tìm thấy số nào thỏa mãn
//}

bool isPerfectSquare(int num) {
    if (num < 1) return false;  // Số nguyên dương

    int left = 1, right = num;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;

        if (square == num) {
            return true;
        }
        else if (square < num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}


int main() {
    int num;
    cout << "Enter positive integer: ";
    cin >> num;

    if (isPerfectSquare(num)) {
        cout << num << " is a square number." << endl;
    }
    else {
        cout << num << " not a square number." << endl;
    }

    return 0;
}
