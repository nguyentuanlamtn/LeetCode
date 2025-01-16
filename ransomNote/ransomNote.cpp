#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineCount;

        // Đếm số lần xuất hiện của mỗi ký tự trong magazine
        for (char c : magazine) {
            magazineCount[c]++;
        }

        // Duyệt qua ransomNote để kiểm tra từng ký tự
        for (char c : ransomNote) {
            if (magazineCount[c] > 0) {
                magazineCount[c]--;  // Dùng ký tự trong magazine
            }
            else {
                return false;  // Nếu không đủ ký tự, trả về false
            }
        }

        return true;  // Nếu duyệt hết ransomNote mà không gặp vấn đề, trả về true
    }
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution;
        string ransomNote, magazine;

        cout << "Nhap ransomNote: ";
        cin >> ransomNote;
        cout << "Nhap magazine: ";
        cin >> magazine;

        bool result = solution.canConstruct(ransomNote, magazine);
        if (result) {
            cout << "Can create ransomNote from magazine." << endl;
        }
        else {
            cout << "Cannot create ransomNote from magazine." << endl;
        }
    }

    return 0;
}
