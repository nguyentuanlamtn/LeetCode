#include <iostream>
#include <string>
#include <vector>
using namespace std;

//char findTheDifference(string s, string t) {
//    int sum_s = 0, sum_t = 0;
//
//    // Tính tổng mã ASCII của tất cả ký tự trong chuỗi s
//    for (char c : s) {
//        sum_s += c;
//    }
//
//    // Tính tổng mã ASCII của tất cả ký tự trong chuỗi t
//    for (char c : t) {
//        sum_t += c;
//    }
//
//    // Chữ cái thừa chính là hiệu của tổng mã ASCII của t và s
//    return (char)(sum_t - sum_s);
//}

//char findTheDifference(string s, string t) {
//    char result = 0;
//
//    // XOR tất cả các ký tự trong s và t
//    for (char c : s) {
//        result ^= c;
//    }
//    for (char c : t) {
//        result ^= c;
//    }
//
//    return result;  // Ký tự còn lại chính là chữ cái được thêm vào
//}

char findTheDifference(string s, string t) {
    vector<int> count(26, 0);

    // Đếm số lần xuất hiện của các ký tự trong t
    for (char c : t) {
        count[c - 'a']++;
    }

    // Trừ số lần xuất hiện của các ký tự trong s
    for (char c : s) {
        count[c - 'a']--;
    }

    // Tìm ký tự có số lần xuất hiện dương
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            return 'a' + i;
        }
    }

    return ' ';  // Không bao giờ xảy ra, vì luôn có ký tự được thêm
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
