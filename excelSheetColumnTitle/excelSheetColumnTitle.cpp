#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int columnNumber) {
    string result = "";
    while (columnNumber > 0) {
        columnNumber--; // Đưa về chỉ số 0-based
        char ch = 'A' + (columnNumber % 26); // Tìm ký tự hiện tại
        result = ch + result;               // Thêm ký tự vào chuỗi kết quả
        columnNumber /= 26;                 // Chuyển sang phần còn lại
    }
    return result;
}

int main() {
    // Ví dụ
    int columnNumber;
    cout << "Enter number of columns: ";
    cin >> columnNumber;

    string title = convertToTitle(columnNumber);
    cout << "Column header: " << title << endl;

    return 0;
}
