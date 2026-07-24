class Solution {
        int maxi = INT_MIN;
private:
    int getMaxSum(TreeNode* Node){
        
        if(Node==nullptr) return 0;

        int lSum=max(getMaxSum(Node->left),0);
        int rSum=max(getMaxSum(Node->right),0);
        
        int NodeMax=Node->val+lSum+rSum;
        maxi=max(maxi,NodeMax);

        return Node->val+max(lSum,rSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        getMaxSum(root);
        return maxi;
    }
};