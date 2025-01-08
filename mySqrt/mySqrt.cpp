#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // Trường hợp đặc biệt

        int low = 0, high = x, result = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x) {
                return mid; // Tìm thấy căn bậc hai chính xác
            }
            else if (mid * mid < x) {
                result = mid; // Cập nhật kết quả tạm thời
                low = mid + 1; // Tìm kiếm bên phải
            }
            else {
                high = mid - 1; // Tìm kiếm bên trái
            }
        }

        return result; // Trả về kết quả
    }
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution;

        int x;
        cout << "Enter a non-negative integer: ";
        cin >> x;

        int result = solution.mySqrt(x);
        cout << "The integer square root of " << x << " is: " << result << endl;
    }

    return 0;
}
