#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Bắt đầu từ chữ số cuối cùng
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;  // Nếu không phải 9, tăng lên và trả về kết quả
                return digits;
            }
            digits[i] = 0;  // Nếu là 9, đổi thành 0
        }

        // Nếu tất cả các chữ số đều là 9, thêm 1 vào đầu mảng
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        Solution solution;
        int n;
        cout << "So phan tu: ";
        cin >> n;
        // Ví dụ minh họa
        vector<int> digits(n);
        
        cout << "Nhap mang: ";
        for (int i = 0; i < n; i++)
        {
            cin >> digits[i];
        }

        // Gọi hàm và in kết quả
        vector<int> result = solution.plusOne(digits);
        
        cout << "Result after adding one: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    

    return 0;
}
