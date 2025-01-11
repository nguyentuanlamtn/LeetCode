#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa cấu trúc Node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Hàm xóa các nút có giá trị val
ListNode* removeElements(ListNode* head, int val) {
    // Tạo một nút giả để dễ xử lý trường hợp đầu danh sách
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* current = dummy;

    while (current->next != nullptr) {
        if (current->next->val == val) {
            // Bỏ qua nút có giá trị val
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp; // Giải phóng bộ nhớ
        }
        else {
            current = current->next;
        }
    }
    // Trả về đầu danh sách mới (bỏ qua nút giả)
    ListNode* newHead = dummy->next;
    delete dummy; // Giải phóng bộ nhớ nút giả
    return newHead;
}

// Hàm tạo danh sách liên kết từ mảng
ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Hàm in danh sách liên kết
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Hàm chính
int main() {
    vector<int> nums = { 1, 2, 6, 3, 4, 5, 6 };
    int val = 6;

    ListNode* head = createLinkedList(nums);
    cout << "Original List: ";
    printLinkedList(head);

    head = removeElements(head, val);
    cout << "Modified List: ";
    printLinkedList(head);

    return 0;
}
