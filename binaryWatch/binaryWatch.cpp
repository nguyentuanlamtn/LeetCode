#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        // Duyệt qua tất cả các giá trị giờ và phút
        for (int hour = 0; hour < 12; ++hour) {       // Giờ: 0 -> 11
            for (int minute = 0; minute < 60; ++minute) { // Phút: 0 -> 59
                // Tổng số bit 1 của giờ và phút phải bằng turnedOn
                if (countBits(hour) + countBits(minute) == turnedOn) {
                    // Định dạng chuỗi giờ và phút
                    string time = to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
                    result.push_back(time); // Lưu vào kết quả
                }
            }
        }
        return result;
    }

private:
    // Hàm thay thế __builtin_popcount
    int countBits(int num) {
        int count = 0;
        while (num > 0) {
            count += (num & 1); // Kiểm tra bit cuối cùng có phải 1 hay không
            num >>= 1;          // Dịch phải 1 bit
        }
        return count;
    }
};

int main() {
    Solution solution;
    int turnedOn;

    // Nhập số đèn LED đang bật
    cout << "Enter the number of LEDs that are on: ";
    cin >> turnedOn;

    // Lấy tất cả các thời gian có thể
    vector<string> times = solution.readBinaryWatch(turnedOn);

    // Hiển thị kết quả
    cout << "The times can be: ";
    for (const string& time : times) {
        cout << time << " ";
    }
    cout << endl;
    return 0;
}
