class BSTIterator {
private:
    stack<TreeNode *> store;
    void pushNode(TreeNode* node){
        while(node!=nullptr){
            store.push(node);
            node=node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushNode(root);
    }
    
    int next() {
        TreeNode* choose=store.top();
        store.pop();
        pushNode(choose->right);
        return choose->val;
    }
    
    bool hasNext() {
        return !store.empty();
    }
};