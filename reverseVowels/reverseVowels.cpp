#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (vowels.count(s[left]) && vowels.count(s[right])) {
            swap(s[left++], s[right--]);
        }
        else if (!vowels.count(s[left])) {
            left++;
        }
        else {
            right--;
        }
    }

    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cout << "Enter string: ";
        getline(cin, s);

        cout << "String after vowel reversal: " << reverseVowels(s) << endl;

    }
    return 0;
}
