class Solution {
private:
    bool checkNext(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr || head->val != root->val) return false;

        return checkNext(head->next, root->left) || checkNext(head->next, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        return checkNext(head, root) || 
               isSubPath(head, root->left) || 
               isSubPath(head, root->right);
    }
};