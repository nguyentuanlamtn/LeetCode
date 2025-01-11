#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);  // Khởi tạo hàng với tất cả giá trị là 1

    for (int i = 1; i <= rowIndex / 2; i++) {
        // Tính giá trị của phần tử tại vị trí i
        row[i] = row[rowIndex - i] = (long long)row[i - 1] * (rowIndex - i + 1) / i;
    }
    return row;
}

int main() {
    int rowIndex;
    cout << "Enter the specified number of rows (rowIndex): ";
    cin >> rowIndex;

    vector<int> result = getRow(rowIndex);

    // In ra hàng tam giác Pascal
    cout << "Row " << rowIndex << " in Pascal's triangle: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
