class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = 0, rh = 0;
        TreeNode* currL = root;
        TreeNode* currR = root;

        while (currL) {
            lh++;
            currL = currL->left;
        }

        while (currR) {
            rh++;
            currR = currR->right;
        }

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};