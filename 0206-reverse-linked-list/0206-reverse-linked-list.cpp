class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* up = nullptr;

        while (current != nullptr) {
            up = current->next;
            current->next = prev;
            prev = current;
            current = up;
        }

        return prev;
    }
};