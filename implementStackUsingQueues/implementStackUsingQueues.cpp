#include <queue>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // Hai hàng đợi

public:
    MyStack() {}

    // Đẩy phần tử x vào ngăn xếp
    void push(int x) {
        // Thêm x vào hàng đợi q2
        q2.push(x);

        // Di chuyển tất cả phần tử từ q1 sang q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Đổi vai trò của q1 và q2
        swap(q1, q2);
    }

    // Xóa phần tử trên cùng và trả về nó
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    // Trả về phần tử trên cùng
    int top() {
        return q1.front();
    }

    // Kiểm tra xem ngăn xếp có rỗng không
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Top element: 3
    cout << "Top element: " << myStack.top() << endl;

    // Pop top element: 3
    cout << "Pop element: " << myStack.pop() << endl;

    // Top element after pop: 2
    cout << "Top element: " << myStack.top() << endl;

    // Check if stack is empty: false
    cout << "Is stack empty? " << boolalpha << myStack.empty() << endl;

    return 0;
}
