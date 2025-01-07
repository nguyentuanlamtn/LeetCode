#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//int romanToInt(string s) {
//    unordered_map<char, int> romanValues = {
//        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
//        {'C', 100}, {'D', 500}, {'M', 1000}
//    };
//
//    int total = 0;
//    int prevValue = 0;
//
//    // Duyệt từ phải sang trái
//    for (int i = s.size() - 1; i >= 0; --i) {
//        int currentValue = romanValues[s[i]];
//        if (currentValue < prevValue) {
//            total -= currentValue; // Trừ nếu nhỏ hơn ký tự trước đó
//        }
//        else {
//            total += currentValue; // Cộng nếu lớn hơn hoặc bằng ký tự trước đó
//        }
//        prevValue = currentValue;
//    }
//
//    return total;
//}

int romanToInt(string s) {
    unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        int currentValue = romanValues[s[i]];
        int nextValue = (i + 1 < n) ? romanValues[s[i + 1]] : 0;

        if (currentValue < nextValue) {
            total -= currentValue; // Trừ nếu nhỏ hơn ký tự sau
        }
        else {
            total += currentValue; // Cộng nếu lớn hơn hoặc bằng ký tự sau
        }
    }

    return total;
}

int main() {
    // Ví dụ sử dụng
    cout << romanToInt("III") << endl;     // Kết quả: 3
    cout << romanToInt("IV") << endl;      // Kết quả: 4
    cout << romanToInt("IX") << endl;      // Kết quả: 9
    cout << romanToInt("LVIII") << endl;   // Kết quả: 58
    cout << romanToInt("MCMXCIV") << endl; // Kết quả: 1994
    return 0;
}
