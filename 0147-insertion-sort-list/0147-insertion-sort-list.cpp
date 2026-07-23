class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        for(ListNode* cur = head; cur; cur = cur -> next) 
            for(ListNode* j = head; j != cur; j = j -> next) 
                if(j -> val > cur -> val) 
                    swap(j -> val, cur -> val);
        return head;    
    }
};