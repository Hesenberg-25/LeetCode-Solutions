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
    void dfs(TreeNode* root, int col, int row,vector<tuple<int, int, int>> &levels){
        if(!root) return;
        levels.emplace_back(col,row,root->val);
        dfs(root->left,col-1,row+1,levels);
        dfs(root->right,col+1,row+1,levels);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<tuple<int, int, int>> levels;
        dfs(root,0,0,levels);
        sort(levels.begin(),levels.end());

        int newCol=INT_MIN;
        for(auto [col,row,val] : levels){
            if(col!=newCol){
                ans.push_back({});
                newCol=col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};