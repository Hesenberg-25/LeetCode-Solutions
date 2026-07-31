class Solution {
private:
    bool checkMirror(TreeNode* LeftSide, TreeNode* RightSide){
        if(LeftSide==nullptr && RightSide==nullptr) return true;
        if(LeftSide==nullptr || RightSide==nullptr) return false;

        if(LeftSide->val!=RightSide->val) return false;

        return(checkMirror(LeftSide->left,RightSide->right) && checkMirror(LeftSide->right,RightSide->left));
    }

    
public:
    bool isSymmetric(TreeNode* root) {
       if(root==nullptr) return true;
       return checkMirror(root->left,root->right);
    }
};