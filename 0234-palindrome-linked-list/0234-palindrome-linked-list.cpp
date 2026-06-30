class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* tempFirst = head;
        ListNode* tempSecond = prev;
        while (tempSecond != nullptr) {
            if (tempFirst->val != tempSecond->val) {
                return false;
            }
            tempFirst = tempFirst->next;
            tempSecond = tempSecond->next;
        }

        return true;
    }
};