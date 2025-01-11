#include <iostream>
#include <vector>
#include <iomanip>  // Để sử dụng std::setw() để căn chỉnh
#include <string>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;  // Mảng 2D để lưu tam giác Pascal

    // Nếu numRows là 0, trả về tam giác rỗng
    if (numRows == 0) {
        return triangle;
    }

    // Thêm hàng đầu tiên vào tam giác Pascal
    triangle.push_back({ 1 });

    // Xây dựng các hàng tiếp theo
    for (int i = 1; i < numRows; i++) {
        vector<int> row(i + 1, 1);  // Khởi tạo một hàng mới có i+1 phần tử, đều là 1

        // Tính các số ở giữa hàng
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        // Thêm hàng này vào tam giác
        triangle.push_back(row);
    }

    return triangle;
}

void printPascalTriangle(const vector<vector<int>>& triangle) {
    int numRows = triangle.size();

    // Tìm chiều rộng tối đa của số trong tam giác để căn giữa
    int maxWidth = to_string(triangle[numRows - 1][triangle[numRows - 1].size() - 1]).size();

    for (int i = 0; i < numRows; i++) {
        // In các số của hàng i, căn giữa theo chiều ngang
        int spaces = (numRows - i - 1); // Tính số khoảng trắng trước mỗi hàng
        for (int s = 0; s < spaces; s++) {
            cout << " ";  // In khoảng trắng trước mỗi hàng
        }

        for (int j = 0; j < triangle[i].size(); j++) {
            // In mỗi số với chiều rộng maxWidth và căn giữa
            cout << setw(maxWidth) << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows;
    cout << "Enter the number of rows in Pascal's triangle: ";
    cin >> numRows;

    vector<vector<int>> result = generate(numRows);

    // In ra tam giác Pascal với căn giữa
    cout << "Pascal's triangle: " << endl;
    printPascalTriangle(result);

    return 0;
}
