class Solution {
private:
    ListNode* kthNodee(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = kthNodee(temp, k);
            if (kthNode == nullptr) {
                if (prevNode != nullptr) {
                    prevNode->next = temp;
                }
                break;
            }

            ListNode* up = kthNode->next;
            kthNode->next = nullptr;

            reverse(temp);

            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = up;
        }

        return head;
    }
};