class Solution {
private:
    int lengthLL(ListNode *head) {
        int cnt = 0;
        ListNode *temp = head;
        while (temp) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        int len = lengthLL(head);
        int rotate = k % len;

        if (rotate == 0) return head;

        int stepTotail = len - rotate;
        int cnt = 1;

        ListNode* wantedTail = nullptr;
        ListNode* Tail = nullptr;
        ListNode* newHead = nullptr;
        ListNode* temp = head;

        while (temp->next != nullptr) {
            if (cnt == stepTotail) {
                wantedTail = temp;
            }
            temp = temp->next;
            cnt++;
        }
        Tail = temp;

        Tail->next = head;
        newHead = wantedTail->next;
        wantedTail->next = nullptr;

        return newHead;
    }
};