#include <iostream>
#include <unordered_map>
#include <sstream>

bool wordPattern(const std::string& pattern, const std::string& s) {
    std::unordered_map<char, std::string> charToWord;
    std::unordered_map<std::string, char> wordToChar;
    std::istringstream stream(s);
    std::string word;
    int i = 0;

    for (; stream >> word; ++i) {
        if (i >= pattern.size()) return false; // Số từ nhiều hơn số ký tự trong pattern
        char c = pattern[i];

        // Kiểm tra ánh xạ ký tự -> từ
        if (charToWord.count(c) && charToWord[c] != word) return false;

        // Kiểm tra ánh xạ từ -> ký tự
        if (wordToChar.count(word) && wordToChar[word] != c) return false;

        // Gán ánh xạ nếu chưa tồn tại
        charToWord[c] = word;
        wordToChar[word] = c;
    }

    // Kiểm tra nếu số ký tự trong pattern nhiều hơn số từ
    return i == pattern.size();
}

int main() {
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";

    std::cout << (wordPattern(pattern, s) ? "True" : "False") << "\n";
    return 0;
}
