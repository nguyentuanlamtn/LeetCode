#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> frequency;
    for (char c : s) {
        frequency[c]++;
    }

    // Step 2: Find the first non-repeating character
    for (int i = 0; i < s.size(); ++i) {
        if (frequency[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << firstUniqChar(s) << endl; // Output: 2
    }
    return 0;
}
