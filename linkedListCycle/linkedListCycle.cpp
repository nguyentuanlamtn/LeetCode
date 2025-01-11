#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false; // Nếu danh sách rỗng hoặc chỉ có 1 nút, không thể có chu trình

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;         // Di chuyển slow 1 bước
        fast = fast->next->next;   // Di chuyển fast 2 bước

        if (slow == fast) {
            return true;           // Nếu slow và fast gặp nhau, có chu trình
        }
    }

    return false; // Nếu fast hoặc fast->next là nullptr, không có chu trình
}

int main() {
    // Tạo một danh sách liên kết có chu trình
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2; // Tạo chu trình

    if (hasCycle(head)) {
        cout << "Programmatic Link List." << endl;
    }
    else {
        cout << "Linked list has no cycles." << endl;
    }

    return 0;
}
