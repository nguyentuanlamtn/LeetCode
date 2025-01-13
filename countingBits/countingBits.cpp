#include <iostream>
#include <vector>
using namespace std;

std::vector<int> countBits(int n) {
    std::vector<int> ans(n + 1, 0); // Mảng kết quả, khởi tạo với giá trị 0
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i >> 1] + (i & 1); // Sử dụng mối quan hệ đệ quy
    }
    return ans;
}

int main() {
    int n = 5; // Ví dụ với n = 5
    std::vector<int> result = countBits(n);

    // In kết quả
    for (int num : result) {
        std::cout << num << " ";
    }
    cout << endl;
    return 0;
}
