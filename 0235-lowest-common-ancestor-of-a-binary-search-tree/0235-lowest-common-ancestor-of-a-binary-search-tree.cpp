class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }    
        TreeNode* Left = lowestCommonAncestor(root->left, p, q);
        TreeNode* Right = lowestCommonAncestor(root->right, p, q);
        if(Left==nullptr){
            return Right;
        }
        else if(Right==nullptr){
            return Left;
        }
        else{
            return root;
        }
    }
};