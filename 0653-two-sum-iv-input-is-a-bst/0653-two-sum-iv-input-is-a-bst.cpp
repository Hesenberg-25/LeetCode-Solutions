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

class BSTIterator {
private:
    stack<TreeNode*> store;
    bool reverse;

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            store.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !store.empty();
    }

    int next() {
        TreeNode* choose = store.top();
        store.pop();

        if (!reverse) {
            pushAll(choose->right);
        } else {
            pushAll(choose->left);
        }

        return choose->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i = left.next();
            } else {
                j = right.next();
            }
        }

        return false;
    }
};