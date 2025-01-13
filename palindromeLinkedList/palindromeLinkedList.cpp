#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;

        // Sao chép các giá trị từ danh sách liên kết vào mảng
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        // So sánh hai đầu của mảng
        int left = 0, right = values.size() - 1;
        while (left < right) {
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};




//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if (!head || !head->next) return true;
//
//        // Bước 1: Tìm phần giữa của danh sách
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        // Bước 2: Đảo ngược nửa sau của danh sách
//        ListNode* reversedHalf = reverseList(slow);
//
//        // Bước 3: So sánh hai nửa
//        ListNode* left = head;
//        ListNode* right = reversedHalf;
//        while (right) {
//            if (left->val != right->val) {
//                return false;
//            }
//            left = left->next;
//            right = right->next;
//        }
//
//        // Bước 4 (Tùy chọn): Khôi phục danh sách ban đầu
//        // reverseList(reversedHalf);
//
//        return true;
//    }
//
//private:
//    // Hàm đảo ngược danh sách liên kết
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = nullptr;
//        while (head) {
//            ListNode* nextNode = head->next;
//            head->next = prev;
//            prev = head;
//            head = nextNode;
//        }
//        return prev;
//    }
//};


int main() {
    // Tạo danh sách liên kết: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    bool result = solution.isPalindrome(head);

    cout << (result ? "True" : "False") << endl; // Kết quả: True

    return 0;
}
