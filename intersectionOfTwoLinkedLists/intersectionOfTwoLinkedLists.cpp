#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Hàm tìm nút giao của hai danh sách liên kết
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    // Di chuyển hai con trỏ qua cả hai danh sách
    while (a != b) {
        // Nếu a đến cuối, chuyển nó sang đầu danh sách B
        a = (a == nullptr) ? headB : a->next;
        // Nếu b đến cuối, chuyển nó sang đầu danh sách A
        b = (b == nullptr) ? headA : b->next;
    }

    // Trả về điểm giao hoặc nullptr nếu không giao nhau
    return a;
}

int main() {
    // Tạo danh sách liên kết
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    // Tìm nút giao
    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Valuable intersection: " << intersection->val << endl;
    }
    else {
        cout << "No intersection." << endl;
    }

    return 0;
}
