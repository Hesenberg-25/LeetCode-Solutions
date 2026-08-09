class Solution {
private:
    TreeNode* buildedTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& InMap){
        if(preStart>preEnd || inStart>inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot=InMap[root->val];
        int inLeft=inRoot-inStart;

        root->left=buildedTree(preorder,preStart+1,preStart+inLeft,inorder,inStart,inRoot-1,InMap);
        root->right=buildedTree(preorder,preStart+inLeft+1,preEnd,inorder,inRoot+1,inEnd,InMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> InMap;
        for(int i=0;i<inorder.size();i++){
            InMap[inorder[i]]=i;
        }
        return buildedTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,InMap);
    }
};