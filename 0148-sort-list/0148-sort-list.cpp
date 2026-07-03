class Solution {
private:
    ListNode* findingMiddle(ListNode *head) {
        if (head == nullptr) return nullptr;

        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tmp = dummy;

        ListNode *t1 = head1;
        ListNode *t2 = head2;

        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val > t2->val) {
                tmp->next = t2;
                t2 = t2->next;
            } else {
                tmp->next = t1;
                t1 = t1->next;
            }
            tmp = tmp->next;
        }

        if (t1 == nullptr) {
            tmp->next = t2;
        } else {
            tmp->next = t1;
        }

        ListNode *newhead = dummy->next;
        delete dummy;
        return newhead;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findingMiddle(head);
        
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr; 

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeTwoLists(leftHead, rightHead);
    }
};