#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        // Hàm DFS để duyệt cây
        function<void(int)> dfs = [&](int current) {
            if (current > n) return; // Nếu vượt qua n, dừng lại
            result.push_back(current);
            for (int i = 0; i <= 9; ++i) {
                int next_number = current * 10 + i;
                if (next_number > n) break; // Không thêm nếu vượt qua n
                dfs(next_number);
            }
        };

        // Bắt đầu DFS từ các số từ 1 đến 9
        for (int i = 1; i <= 9; ++i) {
            dfs(i);
        }

        return result;
    }
};

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        Solution solution;
        int n; // Thay giá trị n tại đây
        cin >> n;
        vector<int> result = solution.lexicalOrder(n);

        // In kết quả
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
