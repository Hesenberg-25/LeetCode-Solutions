class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            t1 = (t1 == nullptr) ? headB : t1->next;
            t2 = (t2 == nullptr) ? headA : t2->next;
        }

        return t1;
    }
};