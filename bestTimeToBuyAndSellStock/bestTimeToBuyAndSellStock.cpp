#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    // Nếu không có giá hoặc chỉ có một ngày, không thể giao dịch
    if (prices.empty()) return 0;

    int minPrice = prices[0];  // Khởi tạo giá cổ phiếu mua thấp nhất
    int maxProfit = 0;         // Khởi tạo lợi nhuận tối đa

    // Duyệt qua các ngày còn lại để tính lợi nhuận
    for (int i = 1; i < prices.size(); i++) {
        // Cập nhật giá mua thấp nhất
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Tính lợi nhuận nếu bán vào ngày i
        int profit = prices[i] - minPrice;
        // Cập nhật lợi nhuận tối đa
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };

    int result = maxProfit(prices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}
