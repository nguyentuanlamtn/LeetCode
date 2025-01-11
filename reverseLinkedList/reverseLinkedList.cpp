#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        // Lưu nút tiếp theo
        next = current->next;
        // Đảo ngược liên kết
        current->next = prev;
        // Di chuyển prev và current lên một nút
        prev = current;
        current = next;
    }

    return prev; // prev là đầu của danh sách đã đảo ngược
}

// Hàm tạo danh sách liên kết từ mảng (hỗ trợ kiểm tra)
ListNode* createList(const int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Hàm in danh sách liên kết
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);
    cout << "Original list: ";
    printList(head);

    ListNode* reversedHead = reverseList(head);
    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
