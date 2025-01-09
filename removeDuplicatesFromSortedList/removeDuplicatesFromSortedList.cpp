#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Hàm xóa các phần tử trùng lặp trong danh sách liên kết đã sắp xếp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head; // Bắt đầu từ đầu danh sách
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Nếu giá trị của node hiện tại trùng với node tiếp theo
            current->next = current->next->next; // Bỏ qua node trùng lặp
        }
        else {
            current = current->next; // Di chuyển đến node tiếp theo
        }
    }
    return head; // Trả về danh sách đã được chỉnh sửa
}

// Hàm in danh sách liên kết
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Hàm main
int main() {
    // Tạo danh sách liên kết: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Initial List: ";
    printList(head); // In danh sách ban đầu

    // Xóa các phần tử trùng lặp
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head); // In danh sách sau khi xóa trùng lặp

    return 0;
}
