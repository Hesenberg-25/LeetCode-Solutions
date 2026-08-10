class Solution {
public:
    TreeNode* BuildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int poStart, int poEnd, unordered_map<int,int> &InMap){
        if(inStart>inEnd || poStart>poEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[poEnd]);

        int inRoot=InMap[root->val];
        int isLeft=inRoot-inStart;

        root->left=BuildTree(inorder,inStart,inRoot-1,postorder,poStart,poStart+isLeft-1,InMap);
        root->right=BuildTree(inorder,inRoot+1,inEnd,postorder,poStart+isLeft,poEnd-1,InMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> InMap;
        for(int i=0 ; i<inorder.size() ; i++){
            InMap[inorder[i]]=i;
        }

        return BuildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,InMap);
    }
};