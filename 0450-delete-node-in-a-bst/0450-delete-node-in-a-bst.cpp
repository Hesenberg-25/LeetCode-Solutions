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
public:
    TreeNode* rightest(TreeNode* root){
        if(root->right==nullptr){
            return root;
        }
        return rightest(root->right);
    }

    TreeNode* Deleter(TreeNode* root){
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->right==nullptr){
            return root->left;
        }

        TreeNode* rightChild=root->right;
        TreeNode* lastRight=rightest(root->left);
        lastRight->right=rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;

        if(key==root->val){
            return Deleter(root);
        }
        TreeNode* Dummy=root;
        while(root!=nullptr){
            if(key<root->val){
                if(root->left!=nullptr && root->left->val==key){
                    root->left=Deleter(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=nullptr && root->right->val==key){
                    root->right=Deleter(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return Dummy;
    }
};