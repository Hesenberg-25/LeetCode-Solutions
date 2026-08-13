class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;

        while (true) {
            if (val < curr->val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};