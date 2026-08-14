/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int result=-1;
    int count=0;
    void Finder(TreeNode* root,int k){
        if(root==nullptr) return ;

        Finder(root->left,k);
        count++;
        if(count==k){
            result = root->val;
            return;
        }
        Finder(root->right,k);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        Finder(root,k);
        return result;
    }
};