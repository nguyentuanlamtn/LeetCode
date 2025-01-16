#include <vector>
#include <iostream>
using namespace std;

void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    //int right = s.size();

    while (left < right) {
        // Hoán đổi hai ký tự
        swap(s[left], s[right]);
        // Di chuyển con trỏ
        left++;
        right--;
    }
}

int main() {
    vector<char> s = { 'h', 'e', 'l', 'l', 'o' };

    cout << "Initial String: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    reverseString(s);

    cout << "String after reversal: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
