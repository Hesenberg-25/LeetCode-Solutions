class Solution {
private:
    vector<int> inorder;
    int index = 0;

    void getInorder(TreeNode* root) {
        if (!root) return;
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
    }

    void restoreTree(TreeNode* root) {
        if (!root) return;
        restoreTree(root->left);
        root->val = inorder[index++];
        restoreTree(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        getInorder(root);
        sort(inorder.begin(), inorder.end());
        restoreTree(root);
    }
};