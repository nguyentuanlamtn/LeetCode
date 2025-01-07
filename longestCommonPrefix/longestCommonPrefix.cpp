#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return ""; // Nếu mảng rỗng, trả về chuỗi rỗng

    string prefix = strs[0]; // Khởi tạo tiền tố bằng chuỗi đầu tiên

    for (int i = 1; i < strs.size(); ++i) {
        // So sánh tiền tố với từng chuỗi trong mảng
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1); // Giảm dần tiền tố
            if (prefix.empty()) return ""; // Nếu không có tiền tố chung, trả về ""
        }
    }

    return prefix; // Trả về tiền tố chung dài nhất
}

int main() {
    vector<string> strs = { "flower", "flow", "flight" };
    cout << "Longest common prefix: " << longestCommonPrefix(strs) << endl;

    vector<string> strs2 = { "dog", "racecar", "car" };
    cout << "Longest common prefix: " << longestCommonPrefix(strs2) << endl;

    return 0;
}
