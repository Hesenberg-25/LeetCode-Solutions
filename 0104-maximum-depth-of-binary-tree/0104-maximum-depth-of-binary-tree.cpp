class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root==nullptr) return 0;
        int lheight=maxDepth(root->left);
        int rheight=maxDepth(root->right);

        return 1+max(lheight,rheight);
    }
};