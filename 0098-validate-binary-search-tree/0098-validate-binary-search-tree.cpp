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
    bool checkBST(TreeNode* root,long long mini,long long maxi){
        
        if(root==nullptr) return true;

        if(root->val<=mini || maxi<=root->val) return false;

        return checkBST(root->left,mini,root->val) && 
               checkBST(root->right,root->val,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        return checkBST(root,LLONG_MIN,LLONG_MAX);
    }
};