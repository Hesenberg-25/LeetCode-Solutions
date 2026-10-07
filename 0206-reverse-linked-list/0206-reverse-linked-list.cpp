class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* tail = head;
        ListNode* newHead = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            tail->next = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = tail->next;
        }

        return newHead;
    }
};