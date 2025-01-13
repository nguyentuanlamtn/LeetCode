#include <iostream>
using namespace std;

// Giả sử API isBadVersion được cung cấp từ hệ thống
bool isBadVersion(int version) {
    // Chúng ta giả lập API này để kiểm tra các phiên bản xấu
    int firstBad = 4; // Giả sử phiên bản xấu đầu tiên là 4
    return version >= firstBad; // Tất cả các phiên bản từ 4 trở đi đều xấu
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid; // Nếu mid là phiên bản xấu, ta tiếp tục tìm trong nửa trái
            }
            else {
                low = mid + 1; // Nếu mid là phiên bản tốt, ta tiếp tục tìm trong nửa phải
            }
        }
        return low; // low sẽ là phiên bản xấu đầu tiên khi vòng lặp kết thúc
    }
};

int main() {
    Solution solution;

    int n = 5; // Tổng số phiên bản
    int badVersion = solution.firstBadVersion(n);

    cout << "First bad version is: " << badVersion << endl;

    return 0;
}
