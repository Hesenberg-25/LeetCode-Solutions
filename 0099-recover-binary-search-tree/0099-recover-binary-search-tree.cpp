class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inOrder(TreeNode* node) {
        if (node == nullptr) return;

        inOrder(node->left);

        if (prev != nullptr && node->val < prev->val) {
            if (first == nullptr) {
                first = prev;
                middle = node;
            } 
            else {
                last = node;
            }
        }
        prev = node;

        inOrder(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;
        inOrder(root);

        if (first && last) {
            swap(first->val, last->val);
        } 
        else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};