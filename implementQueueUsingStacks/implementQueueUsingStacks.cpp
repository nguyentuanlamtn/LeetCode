#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack1; // Ngăn xếp chính để đẩy các phần tử
    stack<int> stack2; // Ngăn xếp phụ để lấy phần tử theo thứ tự FIFO

public:
    MyQueue() {}

    // Đẩy phần tử x vào cuối hàng đợi
    void push(int x) {
        stack1.push(x);
    }

    // Xóa phần tử khỏi đầu hàng đợi và trả về phần tử đó
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int topElement = stack2.top();
        stack2.pop();
        return topElement;
    }

    // Trả về phần tử ở đầu hàng đợi
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    // Kiểm tra xem hàng đợi có trống hay không
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    // Lấy phần tử đầu hàng đợi
    int peekElement = queue.peek(); // Kết quả: 1
    int popElement = queue.pop();   // Kết quả: 1
    bool isEmpty = queue.empty();   // Kết quả: false

    return 0;
}
