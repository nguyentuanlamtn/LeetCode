#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> answer;  // Mảng chứa kết quả
    for (int i = 1; i <= n; ++i) {    // Duyệt từ 1 đến n
        if (i % 3 == 0 && i % 5 == 0) {
            answer.push_back("FizzBuzz");  // Nếu chia hết cho cả 3 và 5
        }
        else if (i % 3 == 0) {
            answer.push_back("Fizz");      // Nếu chia hết cho 3
        }
        else if (i % 5 == 0) {
            answer.push_back("Buzz");      // Nếu chia hết cho 5
        }
        else {
            answer.push_back(std::to_string(i));  // Số i dưới dạng chuỗi
        }
    }
    return answer;
}

int main() {
    int n = 15;  // Ví dụ đầu vào
    std::vector<std::string> result = fizzBuzz(n);

    // In kết quả
    for (const std::string& str : result) {
        std::cout << str << " ";
    }
    cout << endl;
    return 0;
}
