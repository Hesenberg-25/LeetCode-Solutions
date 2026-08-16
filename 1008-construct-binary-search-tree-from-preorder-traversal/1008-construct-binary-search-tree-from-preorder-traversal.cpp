class Solution {
private:
    TreeNode* made(vector<int>& pre,int& cnt,int limit){
        if(cnt==pre.size() || pre[cnt]>limit) return nullptr;
        TreeNode* root = new TreeNode(pre[cnt++]);
        root->left=made(pre,cnt,root->val);
        root->right=made(pre,cnt,limit);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int cnt=0;
        return made(preorder,cnt,INT_MAX);
    }
};