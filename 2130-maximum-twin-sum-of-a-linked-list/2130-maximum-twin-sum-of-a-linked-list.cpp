class Solution {
private:
    vector<int> convertArr(ListNode* head){
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return arr;
    }
public:
    int pairSum(ListNode* head) {
        vector<int> arr = convertArr(head);
        int first=0;
        int last=arr.size()-1;
        int maxi=0;
        while(first<last){
            int sum=arr[first]+arr[last];
            maxi=max(maxi,sum);
            first++;
            last--;
        }
        return maxi;
    }
};