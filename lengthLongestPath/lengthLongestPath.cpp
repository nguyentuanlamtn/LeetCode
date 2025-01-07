#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int lengthLongestPath(string input) {
    vector<int> pathLength; // Lưu độ dài đường dẫn tại mỗi cấp
    pathLength.push_back(0); // Độ dài đường dẫn tại cấp gốc
    int maxLength = 0;

    // Duyệt qua từng dòng trong hệ thống tệp
    size_t i = 0;
    while (i < input.size()) {
        // Đếm số lượng '\t' để xác định cấp độ
        int level = 0;
        while (i < input.size() && input[i] == '\t') {
            ++level;
            ++i;
        }

        // Xác định tên tệp hoặc thư mục
        size_t start = i;
        while (i < input.size() && input[i] != '\n') {
            ++i;
        }
        string name = input.substr(start, i - start);

        // Di chuyển đến dòng tiếp theo
        ++i;

        // Cập nhật độ dài tại cấp độ hiện tại
        if (level + 1 >= pathLength.size()) {
            pathLength.resize(level + 2);
        }

        pathLength[level + 1] = pathLength[level] + name.size() + 1; // +1 cho dấu '/'

        // Nếu là tệp, cập nhật độ dài đường dẫn dài nhất
        if (name.find('.') != string::npos) { // Kiểm tra nếu đây là tệp
            maxLength = max(maxLength, pathLength[level + 1] - 1); // -1 để loại bỏ dấu '/' cuối
        }
    }

    return maxLength;
}

int main() {
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    cout << "Longest path length: " << lengthLongestPath(input) << endl; // Output: 32
    return 0;
}
