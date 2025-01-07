#include <iostream>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    int sum_s = 0, sum_t = 0;

    // Tính tổng mã ASCII của tất cả ký tự trong chuỗi s
    for (char c : s) {
        sum_s += c;
    }

    // Tính tổng mã ASCII của tất cả ký tự trong chuỗi t
    for (char c : t) {
        sum_t += c;
    }

    // Chữ cái thừa chính là hiệu của tổng mã ASCII của t và s
    return (char)(sum_t - sum_s);
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cout << "Nhap s: ";
        cin >> s;
        cout << "Nhap t: ";
        cin >> t;

        cout << findTheDifference(s, t) << endl;
    }
    return 0;
}
